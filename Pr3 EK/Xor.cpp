#include "Xor.h"



Xor::Xor(int id_, int in1_, int in2_) {
	id = id_;
	in1id = in1_;
	in2id = in2_;
	out = true;
}


Xor::~Xor() {
}

bool Xor::calOut() {
	out = input1->getOut() ^ input2->getOut();
	return out;
}
