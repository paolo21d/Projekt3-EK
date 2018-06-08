#pragma once
#ifndef OR_H
#define OR_H


#include "Gate.h"
class Or :	public Gate {

public:
	Or(int id_, int in1_, int in2_);
	~Or();
	bool calOut();
};

#endif // !OR_H