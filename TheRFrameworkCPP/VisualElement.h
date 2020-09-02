#pragma once
#include "Point.h"

class tVisualElement
{
public:
	tPoint* points;

	tVisualElement() {
		points = nullptr;
	}

	~tVisualElement()
	{
		delete[] points;
	}
};
