#include "hooks/enginevgui_paint.h"
#include "core/core.h"

__attribute__((constructor))
void init(void)
{
	gApp.StartInterfaces();
	
	HookEngineVGuiPaint();
}