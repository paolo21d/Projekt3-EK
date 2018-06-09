#include "Not.h"
#include <iostream>
using namespace std;


Not::Not(int id_, int inid_) {
	id = id_;
	in1id = inid_;
	in2id = -3;
	out = true;
}


Not::~Not() {
}

bool Not::calOut() {
	out = ! input1->getOut();
	return out;
}

bool Not::setInputsPointers(std::vector<Gate*>& gatesVector, Gate * vcc, Gate * gnd) {
	if (in1id == -1) { //gnd
		input1 = gnd;
		return true;
	}
	else if (in1id == -2) { //vcc
		input1 = vcc;
		return true;
	}
	if (in1id >= 0 && in1id <= gatesVector.size()) {
		input1 = gatesVector[in1id];
		return true;
	}
	//for (unsigned i = 0; i < gatesVector.size(); ++i) { // ustawienie wskaznikow input1, input2
	//	Not* n;
	//	try {
	//		n = dynamic_cast<Not*>(gatesVector[i]);
	//	}
	//	catch (const bad_cast& bc) {
	//		cout << "Blad rzutowania! " << bc.what() << endl;
	//		return 0;
	//	}
	//	if (n->id == in1id) {
	//		input1 = gatesVector[i];
	//		return true;
	//	}
	//	/*Gate* g = gatesVector[i];
	//	if (g->id == in1id) {
	//		input1 = g;
	//		set1 = true;
	//	}*/
	//}
	return false;
}
