#include"Xinput.h"

BOOL Xinput::UpdateControllerState()
{
	return (XInputGetState(0, &XinputState) == ERROR_SUCCESS) ? TRUE : FALSE;
}