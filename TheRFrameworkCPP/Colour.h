#pragma once

struct tColour {
	unsigned int r, g, b, a;

	tColour(int _r, int _g, int _b, int _a = 255) : r(_r), g(_g), b(_b), a(_a) {}
	tColour() { r = 0; g = 0; b = 0; a = 255; }
};