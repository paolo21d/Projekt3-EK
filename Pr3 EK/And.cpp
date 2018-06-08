#include "And.h"
#include <iostream>

using namespace std;

And::And(int id_, int in1_, int in2_) {
	id = id_;
	in1id = in1_;
	in2id = in2_;
	out = true;
}


And::~And() {
}



bool And::calOut() {
	out = input1->getOut() && input2->getOut();
	return out;
}
