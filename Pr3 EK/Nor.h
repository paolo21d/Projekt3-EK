#pragma once
#ifndef NOR_H
#define NOR_H

#include "Gate.h"
#include <vector>

class Nor :public Gate {
public:
	Nor(int id_, int in1_, int in2_);
	~Nor();
	bool calOut();
};

#endif // !NOR_H