#pragma once

#include <vector>

#include "chamsmaterial.h"

#include "../../sdk/classes/entity.h"

#include "../entitylist/entitylist.h"

namespace Chams
{
	void Init();
	void Reset();

	void OnLevelPostEntity();
	void OnLevelShutdown();
	void OnDoPostScreenSpaceEffects(CTFPlayer* pLocal);

	bool ShouldHide(int entindex);
	bool IsDrawing();

	std::vector<ChamsMaterial>& GetMaterials();
	void ApplyMaterials(CBaseEntity* entity, int drawflags);
	bool AddMaterial(const std::string& name, const std::string& vmt, ChamsMaterial& out);
	bool RemoveMaterial(const std::string& name);

	bool IsValidEntity(CTFPlayer* pLocal, const EntityListEntry& entity);

} // end namespace