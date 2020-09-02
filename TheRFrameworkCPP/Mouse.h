#pragma once
#include "MouseButtons.h"
#include "Point.h"

struct tMouse
{
	tPoint pos;
	tMouseButtons button;
	tMouseButtonStates state;

	tMouse(tPoint _pos, tMouseButtons _button, tMouseButtonStates _state) : pos(_pos), button(_button), state(_state) { }
	tMouse() { pos = tPoint(0, 0); button = tMouseButtons::None; state = tMouseButtonStates::Up; }
};