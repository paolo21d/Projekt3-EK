#pragma once
#ifndef XOR_H
#define XOR_H


#include "Gate.h"
class Xor :public Gate {
public:
	Xor(int id_, int in1_, int in2_);
	~Xor();
	bool calOut();
};

#endif // !XOR_H