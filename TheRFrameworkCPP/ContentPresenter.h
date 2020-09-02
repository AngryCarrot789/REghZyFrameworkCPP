#pragma once
#include "UIElement.h"
#include "Colour.h"
#include <wchar.h>

class tContentPresenter : public UIElement {
public:
	tColour foreground;
	int size;
	const wchar_t* text;

	tContentPresenter(const wchar_t* _text, tColour _foreground = tColour(0, 0, 0), int _size = 16) {
		size = _size;
		text = _text;
		foreground = _foreground;
	}

	tContentPresenter() {
		size = 16;
		text = L"";
		foreground = tColour(0, 0, 0);
	}

	~tContentPresenter() {
		//delete text;
	}

	int getCount() {
		return wcslen(text);
	}
};