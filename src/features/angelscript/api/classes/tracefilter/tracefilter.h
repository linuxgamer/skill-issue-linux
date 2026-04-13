#pragma once

#include "../../../../../sdk/definitions/ienginetrace.h"
#include "../../../include/angelscript.h"

class ScriptTraceFilter : public ITraceFilter
{
public:
	ScriptTraceFilter(asIScriptFunction* fn);
	~ScriptTraceFilter();
	bool ShouldHitEntity(IHandleEntity* pEntity, int contentsMask) override;
	TraceType_t GetTraceType() const override { return TraceType_t::TRACE_EVERYTHING; }

private:
	asIScriptFunction* m_fn = nullptr;
};