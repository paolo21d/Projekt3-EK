#pragma once
#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "Gate.h"
#include "Vcc.h"
#include "Gnd.h"
#include <iostream>
#include <vector>

class Circuit {
	std::vector <Gate*> gatesVector;

	Gate* vcc;
	Gate* gnd;
public:
	Circuit();
	~Circuit();
	bool simulate();
	bool loadCircuit();
};

#endif // !CIRCUIT_H