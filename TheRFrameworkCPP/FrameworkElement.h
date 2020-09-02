#pragma once
#include "ElementHelper.h"
#include "UIElement.h"
#include "Colour.h"
#include "VisualElement.h"
#include "Mouse.h"
#include "ContentPresenter.h"

#include <string>
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#pragma comment (lib,"Gdiplus.lib")

// The fundamental interactable element
class tFrameworkElement : public UIElement {
public:
	tContentPresenter content;
	tVisualElement visual;

	tColour activeBackground;
	tColour activeBorder;

	tColour baseBackground;
	tColour baseBorder;
	tColour mouseOverBackground;
	tColour mouseOverBorder;

	tFrameworkElement() {
	}

	~tFrameworkElement() {

	}

	// not used atm
	virtual void OnMouseEnter(tMouse& e) {
		activeBackground = mouseOverBackground;
		activeBorder = mouseOverBorder;
	}

	virtual void OnMouseMove(tMouse& e) {
		activeBackground = mouseOverBackground;
		activeBorder = mouseOverBorder;
	}

	virtual void OnMouseLeave(tMouse& e) {
		activeBackground = baseBackground;
		activeBorder = baseBorder;
	}

	virtual void OnMouseDown(tMouse& e) {

	}

	virtual void OnMouseUp(tMouse& e) {

	}

	//std::wstring IntToString(int value) {
	//	std::wstring result;
	//
	//	while (value) {
	//		result.insert(result.begin(), '0' + value % 10);
	//		value = value / 10;
	//	}
	//
	//	return result;
	//}

	virtual void Update(tMouse& mouse) {
		if (CheckMouseOver(pos, size, mouse.pos)) {
			OnMouseMove(mouse);
		}
		else {
			OnMouseLeave(mouse);
		}
	}

	void SetupBackgrounds() {
		activeBackground = baseBackground;
		activeBorder = baseBorder;
	}

	virtual void Draw(HDC hdc) {
		Gdiplus::Graphics g(hdc);
		Gdiplus::SolidBrush bruh(Gdiplus::Color(activeBackground.a, activeBackground.r, activeBackground.g, activeBackground.b));
		Gdiplus::Pen bordr(Gdiplus::Color(activeBorder.a, activeBorder.r, activeBorder.g, activeBorder.b));

		g.Clear(Gdiplus::Color(255, 255, 255));

		if (visual.points) {
			const int count = sizeof(visual.points);
			Gdiplus::PointF backgroundPoly[count];
			for (int i = 0; i < count; i++) {
				tPoint point = visual.points[i] * size + pos;
				backgroundPoly[i] = Gdiplus::PointF(point.x, point.y);
			}

			g.FillPolygon(&bruh, backgroundPoly, count);
			g.DrawPolygon(&bordr, backgroundPoly, count);
		}

		Gdiplus::FontFamily  fontFamily(L"Consolas");
		Gdiplus::Font        font(&fontFamily, content.size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
		tPoint contentPos = pos + content.pos;
		Gdiplus::PointF      pointF(contentPos.x, contentPos.y);
		Gdiplus::SolidBrush  solidBrush(Gdiplus::Color(content.foreground.a, content.foreground.r, content.foreground.g, content.foreground.b));
		g.DrawString(content.text, -1, &font, pointF, &solidBrush);
	}
};