#include "pred.h"

#include "../../../../../sdk/classes/player.h"
#include "../../../add_on/scriptarray/scriptarray.h"
#include "../../globals.h"

#include "../../../../prediction/prediction.h"

bool Predict(CBaseEntity* pTarget, float timeSeconds, CScriptArray* arr)
{
	if (pTarget == nullptr)
		return false;

	if (!pTarget->IsPlayer())
		return false;

	CTFPlayer* pPlayer = static_cast<CTFPlayer*>(pTarget);
	std::vector<Vec3> path;
	bool ret = false;

	gPrediction.BeginPrediction(pPlayer, timeSeconds);
	ret = gPrediction.Simulate(path);
	gPrediction.EndPrediction();

	// clear it
	arr->Resize(0);

	for (auto& pos : path)
		arr->InsertLast(&pos);

	return ret;
}

void Prediction_RegisterLibrary(asIScriptEngine *engine)
{
	auto def = engine->GetDefaultNamespace();

	engine->SetDefaultNamespace("Prediction");
	{
		engine->SetDefaultAccessMask(ScriptAccessMask::SCRIPT_MASK_ALLOW_PREDICTION);
		engine->RegisterGlobalFunction("bool Simulate(Entity@ target, float timeSeconds, array<Vector3> &inout path)", asFUNCTION(Predict), asCALL_CDECL);
	}

	engine->SetDefaultNamespace(def);
}