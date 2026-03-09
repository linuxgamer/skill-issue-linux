#include "thirdperson.h"

#include "../../../sdk/definitions/cgametrace.h"
#include "../../../sdk/definitions/ctracefilters.h"

// Call in FrameStageNotify -> FRAME_NET_UPDATE_END
void Thirdperson::FrameStageNotify(CTFPlayer* pLocal)
{
	if (!pLocal->IsAlive())
		return interfaces::CInput->CAM_ToFirstPerson();

	bool bState = IsThirdPerson(pLocal);
	if (bState)
		interfaces::CInput->CAM_ToThirdPerson();
	else
	 	interfaces::CInput->CAM_ToFirstPerson();

	pLocal->ThirdPersonSwitch(bState);
}

void Thirdperson::OverrideView(CTFPlayer* pLocal, CViewSetup *pView)
{
	if (!pLocal->IsAlive())
		return interfaces::CInput->CAM_ToFirstPerson();

	bool bState = IsThirdPerson(pLocal);
	if (bState)
		interfaces::CInput->CAM_ToThirdPerson();
	else
	 	interfaces::CInput->CAM_ToFirstPerson();

	pLocal->ThirdPersonSwitch(bState);

	if (interfaces::CInput->CAM_IsThirdPerson())
	{
		Vector vecViewAngles = pView->angles;
	
		Vector vecForward, vecRight, vecUp;
		Math::AngleVectors(vecViewAngles, &vecForward, &vecRight, &vecUp);
	
		float flScale = Settings::Misc.thirdperson_offset[3];
	
		Vector vecOrigin = pView->origin;
	
		CGameTrace trace{};
		CTraceFilterWorldAndPropsOnly filter{};
		filter.pSkip = pLocal;
	
		Vector vecEnd =
		pLocal->GetEyePos()
		+ (vecForward * Settings::Misc.thirdperson_offset[0] * flScale)
		+ (vecRight * Settings::Misc.thirdperson_offset[1] * flScale)
		+ (vecUp * Settings::Misc.thirdperson_offset[2] * flScale);
	
		helper::engine::Trace(pView->origin, vecEnd, MASK_SHOT_HULL, &filter, &trace);
	
		vecEnd = trace.endpos;
	
		pView->origin = vecEnd;
	}
}

bool Thirdperson::ShouldIgnoreBind(CTFPlayer *pLocal)
{
	return pLocal->IsTaunting()
		|| pLocal->IsGhost()
		|| pLocal->InCond(TF_COND_HALLOWEEN_KART)
		|| (
			pLocal->InCond(TF_COND_STUNNED)
			&& (pLocal->m_iStunFlags() & (TF_STUN_CONTROLS | TF_STUN_LOSER_STATE))
		);
}

bool Thirdperson::IsThirdPerson(CTFPlayer* pLocal)
{
	return Settings::Misc.thirdperson_key->IsActive() || ShouldIgnoreBind(pLocal);
}