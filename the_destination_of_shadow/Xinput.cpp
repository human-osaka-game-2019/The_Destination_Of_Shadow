#include"Xinput.h"

Xinput* Xinput::instance = NULL;

BOOL Xinput::UpdateControllerState()
{
	XInputGetKeystroke(0, NULL, &XinputKeyStroke);
	return (XInputGetState(0, &XinputState) == ERROR_SUCCESS) ? TRUE : FALSE;
}