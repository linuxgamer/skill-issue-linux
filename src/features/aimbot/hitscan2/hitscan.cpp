#include "hitscan.h"

#include "../../prediction/prediction.h"
#include "../../backtrack/backtrack.h"
#include "../../../settings/settings.h"
#include "../utils/utils.h"

static CBaseEntity* s_pTarget = nullptr;
static Vec3 s_vecBonePos {};
static float s_flSimTime = 0.0f;

void AimHitscan::Reset()
{
	if (s_pTarget)
		s_pTarget = nullptr;
}

bool CanDamageEntity(CTFPlayer* pLocal, CTFWeaponBase* pWeapon, CBaseEntity* pTarget)
{
	if (pLocal == nullptr || pWeapon == nullptr || pTarget == nullptr)
		return false;

	if (pLocal->m_iTeamNum() == pTarget->m_iTeamNum() && pWeapon->CanHitTeammates())
		return true;

	if (pTarget->IsPlayer())
	{
		CTFPlayer *player = static_cast<CTFPlayer *>(pTarget);

		if (Settings::Aimbot.waitforcharge && pWeapon->IsSniperRifle() && pLocal->InCond(TF_COND_ZOOMED))
			return static_cast<CTFSniperRifle *>(pWeapon)->GetChargedDamage() >= player->GetHealth();
	}

	if (pTarget->IsBuilding())
	{
		CBaseObject *obj = static_cast<CBaseObject *>(pTarget);

		if (Settings::Aimbot.waitforcharge && pWeapon->IsSniperRifle() && pLocal->InCond(TF_COND_ZOOMED))
			return static_cast<CTFSniperRifle *>(pWeapon)->GetChargedDamage() >= obj->m_iHealth();
	}

	return AimbotUtils::IsValidEntity(pTarget);
}

void AimHitscan::RunMain(CTFPlayer* pLocal, CTFWeaponBase* pWeapon, CUserCmd* pCmd)
{
	Reset();

	if (pLocal == nullptr || pWeapon == nullptr || pCmd == nullptr)
		return;

	if (!Settings::Aimbot.key->IsActive())
		return;

	float flBestFov = AimbotUtils::GetAimbotFovScaled();

	if (flBestFov == 0.0f)
		return;

	bool bWaitForCharge = Settings::Aimbot.waitforcharge;
	auto preferredHitpoint = GetPreferredHitPoint(pLocal, pWeapon);

	if (bWaitForCharge && preferredHitpoint == PreferredHitPoint::HEAD)
	{
		if (CanWaitForCharge(pWeapon))
		{
			if (pWeapon->IsAmbassador() && !pWeapon->CanAmbassadorHeadshot())
				return;
		}
	}

	Vec3 vecShootPos;// = pLocal->GetEyePos();
	{
		std::vector<Vec3> vPath;
		gPrediction.BeginPrediction(pLocal, TICKS_TO_TIME(1));
		gPrediction.Simulate(vPath);
		gPrediction.EndPrediction();

		vecShootPos = vPath.back() + pLocal->m_vecViewOffset();
	}

	CGameTrace trace;
	CTraceFilterHitscan filter;
	//filter.pSkip = pLocal;
	filter.iTeam = pLocal->m_iTeamNum() == 2 ? 3 : 2; // skip our teammates

	Vec3 viewAngles;
	interfaces::Engine->GetViewAngles(viewAngles);

	for (const auto& enemy : AimbotUtils::GetTargets(false, pLocal->m_iTeamNum()))
	{
		if (enemy.ptr == nullptr)
			continue;

		if (!CanDamageEntity(pLocal, pWeapon, enemy.ptr))
			continue;

		{
			Vec3 vecCenter = enemy.ptr->GetCenter();
			Vector vecAngle = Math::CalcAngle(vecShootPos, vecCenter);
			float flFov = Math::CalcFov(viewAngles, vecAngle);
	
			if (flFov > flBestFov)
				continue;

			flBestFov = flFov;
		}

		if (enemy.flags & EntityFlags::IsPlayer)
		{
			CTFPlayer* pPlayer = static_cast<CTFPlayer*>(enemy.ptr);
			std::vector<LagCompRecord> records;

			if (!Backtrack::GetRecords(pPlayer, records))
				continue;

			filter.pSkip = pPlayer;

			for (auto& record : records)
			{
				if (!record.IsValid(pCmd))
					continue;

				Vector vecPos;
				CBaseAnimating* pAnimating = static_cast<CBaseAnimating*>(pPlayer);
				bool bFound = false;

				if (!pAnimating->GetHitboxCenter(record.m_Bones, static_cast<int>(preferredHitpoint), vecPos))
					continue; // no bone? wtf

				helper::engine::Trace(vecShootPos, vecPos, MASK_SHOT, &filter, &trace);

				if (trace.fraction == 1.0f)
				{
					bFound = true;
				}
				else
				{
					for (int i = 0; i < HITBOX_LEFT_UPPERARM; i++)
					{
						if (!pAnimating->GetHitboxCenter(record.m_Bones, i, vecPos))
							continue;
	
						helper::engine::Trace(vecShootPos, vecPos, MASK_SHOT, &filter, &trace);
	
						if (trace.fraction == 1.0f)
						{
							bFound = true;
							break;
						}
					}
				}

				if (bFound)
				{
					s_pTarget = enemy.ptr;
					s_vecBonePos = vecPos;
					s_flSimTime = record.m_flSimTime;
					EntityList::m_pAimbotTarget = s_pTarget;
					break;
				}
			}
		}
	}

	if (s_pTarget == nullptr)
		return;

	if (Settings::Aimbot.autoshoot)
	{
		pCmd->buttons |= IN_ATTACK;

		if (pWeapon->GetWeaponID() == TF_WEAPON_SNIPERRIFLE_CLASSIC)
		{
			CTFSniperRifleClassic* pSniper = static_cast<CTFSniperRifleClassic*>(pWeapon);
			if (pSniper->m_flChargedDamage() > 50.0f)
				pCmd->buttons |= IN_ATTACK;
		}
	}

	if (helper::localplayer::IsAttacking(pLocal, pWeapon, pCmd))
		OnAttack(pLocal, pWeapon, pCmd);
}

void AimHitscan::OnAttack(CTFPlayer *pLocal, CTFWeaponBase *pWeapon, CUserCmd *pCmd)
{
	if (pLocal == nullptr || pWeapon == nullptr || pCmd == nullptr || s_pTarget == nullptr)
		return;

	Vec3 vecShootPos = pLocal->GetEyePos();
	Vec3 vecDir = s_vecBonePos - vecShootPos;

	vecDir.Normalize();
	pCmd->viewangles = vecDir.ToAngle();
	pCmd->tick_count = TIME_TO_TICKS(s_flSimTime + Backtrack::GetInterp());
}

CBaseEntity* AimHitscan::GetTarget()
{
	return s_pTarget;
}

PreferredHitPoint AimHitscan::GetPreferredHitPoint(CTFPlayer* pLocal, CTFWeaponBase* pWeapon)
{
	if (pWeapon == nullptr)
		return PreferredHitPoint::PELVIS;

	switch (pWeapon->GetWeaponID())
	{
		case TF_WEAPON_REVOLVER:
		{
			if (pWeapon->CanAmbassadorHeadshot())
				return PreferredHitPoint::HEAD;

			return PreferredHitPoint::PELVIS;
		}

		case TF_WEAPON_SNIPERRIFLE:
		case TF_WEAPON_SNIPERRIFLE_DECAP:
		case TF_WEAPON_SNIPERRIFLE_CLASSIC:
		{
			if (!pLocal->InCond(TF_COND_ZOOMED))
				return PreferredHitPoint::PELVIS;

			if (static_cast<CTFSniperRifle *>(pWeapon)->m_flChargedDamage() < 50.0f)
				return PreferredHitPoint::PELVIS;

			return PreferredHitPoint::HEAD;
		}
	}

	return PreferredHitPoint::PELVIS;
}

bool AimHitscan::CanWaitForCharge(CTFWeaponBase* pWeapon)
{
	int id = pWeapon->GetWeaponID();

	switch(id)
	{
		case TF_WEAPON_SNIPERRIFLE:
		case TF_WEAPON_SNIPERRIFLE_DECAP:
		case TF_WEAPON_SNIPERRIFLE_CLASSIC:
		case TF_WEAPON_REVOLVER:
		{
			if (id == TF_WEAPON_REVOLVER)
				return pWeapon->IsAmbassador();

			return true;
		}

		default:
		return false;
	}

	return false;
}