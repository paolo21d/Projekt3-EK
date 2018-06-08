#pragma once
#ifndef VCC_H
#define VCC_H

#include "Gate.h"
class Vcc : public Gate {
public:
	Vcc(){
		out = true;
		id = -2;
	}
	bool calOut() {
		return out;
	}
};

#endif // !VCC_H