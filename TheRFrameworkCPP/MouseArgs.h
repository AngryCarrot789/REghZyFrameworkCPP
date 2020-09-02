#pragma once
#include "Mouse.h"

// not used atm, but can be used for detecting mouseenter/leave and other stuff maybe
struct tMouseArgs {
	tMouse prev;
	tMouse now;

	tMouseArgs(tMouse _previous, tMouse _new) : prev(_previous), now(_new) { }
	tMouseArgs() { prev = tMouse(); now = tMouse(); }
};