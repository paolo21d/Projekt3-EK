#pragma once
#ifndef AND_H
#define AND_H

#include "Gate.h"
class And :	public Gate {

public:
	And(int id_, int in1_, int in2_);
	~And();
	bool calOut();
};

#endif // !AND_H