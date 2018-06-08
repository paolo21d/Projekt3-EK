#pragma once
#ifndef NOT_H
#define NOT_H


#include "Gate.h"
class Not :	public Gate {
public:
	Not(int id_, int inid_);
	~Not();
	bool calOut();
	virtual bool setInputsPointers(std::vector<Gate*>& gatesVector, Gate* vcc, Gate* gnd);
};

#endif // !NOT_H