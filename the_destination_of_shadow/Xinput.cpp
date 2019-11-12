#include"Xinput.h"

Xinput* Xinput::instance = NULL;

BOOL Xinput::UpdateControllerState()
{
	return (XInputGetState(0, &XinputState) == ERROR_SUCCESS) ? TRUE : FALSE;
}