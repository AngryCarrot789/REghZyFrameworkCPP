#pragma once
#include "FrameworkElement.h"

class tButton : public tFrameworkElement {
public:
	tButton(const wchar_t* _text, tPoint _pos, tPoint _size) : tButton() {
		content.text = _text;
		pos = _pos;
		size = _size;
	}

	tButton() {
		content.text = L"btn";
		content.pos = tPoint(10, 10);
		pos = tPoint(10, 10);
		size = tPoint(100, 40);

		baseBackground = tColour(232, 232, 232);
		baseBorder = tColour(190, 190, 190);
		mouseOverBackground = tColour(210, 210, 210);
		mouseOverBorder = tColour(160, 160, 160);

		SetupBackgrounds();

		visual.points = new tPoint[4]{
			tPoint(0, 0),
			tPoint(1, 0),
			tPoint(1, 1),
			tPoint(0, 1),
		};
	}
};