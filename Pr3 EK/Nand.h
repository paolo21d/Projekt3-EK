#pragma once
#ifndef  NAND_H
#define NAND_H


#include "Gate.h"

class Nand : public Gate {
	
public:
	Nand(int id_, int in1_, int in2_);
	~Nand();
	bool calOut();
};

#endif // ! NAND_H