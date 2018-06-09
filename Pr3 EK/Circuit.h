#pragma once
#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "Gate.h"
#include "Vcc.h"
#include "Gnd.h"
#include "And.h"
#include "Or.h"
#include "Xor.h"
#include "Nor.h"
#include "Nand.h"
#include "Not.h"
#include "MyExceptions.h"
#include <iostream>
#include <fstream>
#include <sstream>

class Circuit {
	std::vector <Gate*> gatesVector;
	Gate* circuitOut;

	Gate* vcc;
	Gate* gnd;
public:
	Circuit();
	~Circuit();
	bool simulate();
	bool loadCircuit();
	bool getGateOut(int id) const;
	unsigned getSizeCircuit() const;
	bool getCircuitOut() const;
	void showCircuit() const;
};

#endif // !CIRCUIT_H