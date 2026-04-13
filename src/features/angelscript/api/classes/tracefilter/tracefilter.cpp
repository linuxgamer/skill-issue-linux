#include "tracefilter.h"

#include "../../globals.h"

ScriptTraceFilter::ScriptTraceFilter(asIScriptFunction* fn)
: m_fn(fn)
{
	if (m_fn) m_fn->AddRef();
}

ScriptTraceFilter::~ScriptTraceFilter()
{
	if (m_fn) m_fn->Release();
}

bool ScriptTraceFilter::ShouldHitEntity(IHandleEntity* pEntity, int contents)
{
	if (!m_fn) return true;

	asIScriptContext* ctx = GetScriptEngine()->RequestContext();;

	ctx->Prepare(m_fn);
	ctx->SetArgObject(0, pEntity);
	ctx->SetArgDWord(1, contents);

	bool rc = true;
	if (ctx->Execute() != asEXECUTION_FINISHED)
		return ctx->GetReturnByte() != 0;

	bool result = ctx->GetReturnByte() != 0;

	GetScriptEngine()->ReturnContext(ctx);
	return result;
}