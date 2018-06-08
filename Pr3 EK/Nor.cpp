#include "Nor.h"

#include <iostream>
#include <vector>
using namespace std;

Nor::Nor(int id_, int in1_, int in2_) {
	id = id_;
	in1id = in1_;
	in2id = in2_;
	out = true;
}


Nor::~Nor(){
}


bool Nor::calOut() {
	out = !(input1->getOut() || input2->getOut());
	return out;
}
