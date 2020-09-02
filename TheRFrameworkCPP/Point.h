#pragma once
struct tPoint {
	int x, y;

	tPoint(int _x, int _y) : x(_x), y(_y) { }
	tPoint() { x = 0; y = 0; }

	inline tPoint operator*(double amount) {
		return tPoint(x * amount, y * amount);
	}

	inline tPoint operator*(tPoint p) {
		return tPoint(x * p.x, y * p.y);
	}

	inline tPoint operator+(tPoint p) {
		return tPoint(x + p.x, y + p.y);
	}

	inline tPoint operator+(double amount) {
		return tPoint(x + amount, y + amount);
	}
};