#pragma once
#include "Point.h"
#include "Mouse.h"

/// <summary>
/// Checks if the mouse cursor is over a rectangle
/// </summary>
/// <param name="pos"> - The Point where the rectangle starts</param>
/// <param name="size"> - The Size of the rectangle</param>
/// <param name="mPos"> - The location of the mouse cursor</param>
/// <returns></returns>
bool CheckMouseOver(tPoint& pos, tPoint& size, tPoint& mPos) {
	if (mPos.x >= pos.x && mPos.x <= (pos.x + size.x)) {
		if (mPos.y >= pos.y && mPos.y <= (pos.y + size.y)) {
			return true;
		}
		else return false;
	}
	else return false;
}