#include "eyetrace.h"

#include "../../entitylist/entitylist.h"
#include "../../../sdk/helpers/engine/engine.h"
#include "../../../sdk/definitions/cgametrace.h"
#include "../../../sdk/definitions/ctracefilters.h"

#include "../../../imgui/imgui.h"

// does not work

void EyeTrace_Run()
{
	constexpr float flRadius = 10.0f;
	constexpr float flScale = 50.0f;

	CTFPlayer* pLocal = EntityList::GetLocal();
	if (pLocal == nullptr || !pLocal->IsAlive())
		return;

	ImDrawList* draw = ImGui::GetBackgroundDrawList();
	if (draw == nullptr)
		return;

	int iWidth, iHeight;
	interfaces::Engine->GetScreenSize(iWidth, iHeight);

	Vector vecLocalCenter = pLocal->GetCenter();

	CGameTrace trace;
	CTraceFilterHitscan filter;

	for (const auto& enemy : EntityList::GetEnemies())
	{
		if (enemy.ptr == nullptr)
			continue;

		if ((enemy.flags & (EntityFlags::IsAlive | EntityFlags::IsPlayer)) == 0)
			continue;

		CTFPlayer* pPlayer = static_cast<CTFPlayer*>(enemy.ptr);
		filter.pSkip = pPlayer;

		Vector vecEyeAngles = pPlayer->m_angEyeAngles();
		Vector vecEyePos = pPlayer->GetEyePos();
		Vector vecForward;
		Math::AngleVectors(vecEyeAngles, &vecForward);

		helper::engine::Trace(vecEyePos, vecEyePos + (vecForward * 8192.0f), MASK_SHOT_HULL, &filter, &trace);

		if (trace.m_pEnt != pLocal)
			continue;

		//interfaces::Cvar->ConsolePrintf("Found");

		Vector vecDir = pPlayer->GetCenter() - vecLocalCenter;
		vecDir.Normalize();

		float flYaw = DEG2RAD(vecDir.ToAngle().y);
		float x, y;
		x = RAD2DEG(std::cosf(flYaw)) * flScale;
		y = RAD2DEG(std::sinf(flYaw)) * flScale;

		draw->AddCircleFilled(ImVec2((iWidth / 2.0f) + x, (iHeight / 2.0f) + y), flRadius, IM_COL32(255, 255, 255, 255));
	}
}