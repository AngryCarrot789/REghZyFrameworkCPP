#pragma once
#include "Point.h"

class UIElement {
public:
	tPoint pos;
	tPoint size;

	UIElement(tPoint _pos, tPoint _size) : pos(_pos), size(_size) { }
	UIElement() { pos = tPoint(0, 0); size = tPoint(60, 25); }
};