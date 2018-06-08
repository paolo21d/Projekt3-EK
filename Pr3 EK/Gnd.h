#pragma once
#ifndef GND_H
#define GND_H

#include "Gate.h"
class Gnd : public Gate {
public:
	Gnd() {
		out = false;
		id = -1;
	}
	bool calOut() {
		return out;
	}
};

#endif // !GND_H