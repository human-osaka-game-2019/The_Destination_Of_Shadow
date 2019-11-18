#include"Xinput.h"

Xinput* Xinput::instance = NULL;

BOOL Xinput::UpdateControllerState()
{
	XInputGetKeystroke(0, NULL, &XinputKeyStroke);
	return (XInputGetState(0, &XinputState) == ERROR_SUCCESS) ? TRUE : FALSE;
}

BOOL Xinput::IsKeyStrokePressed(WORD key_type)
{
	return ((XinputKeyStroke.VirtualKey == key_type) & (XinputKeyStroke.Flags >= XINPUT_KEYSTROKE_REPEAT)) ? TRUE : FALSE;
}

BOOL Xinput::IsKeyStrokePushed(WORD key_type)
{
	return ((XinputKeyStroke.VirtualKey == key_type) & (XinputKeyStroke.Flags == XINPUT_KEYSTROKE_KEYDOWN)) ? TRUE : FALSE;
}

BOOL Xinput::IsKeyStrokeReleased(WORD key_type)
{
	return ((XinputKeyStroke.VirtualKey == key_type) & (XinputKeyStroke.Flags == XINPUT_KEYSTROKE_KEYUP)) ? TRUE : FALSE;
}

