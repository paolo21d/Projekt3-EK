#include "Nand.h"



Nand::Nand(int id_, int in1_, int in2_) {
	id = id_;
	in1id = in1_;
	in2id = in2_;
	out = true;
}


Nand::~Nand() {
}

bool Nand::calOut() {
	out = !(input1->getOut() && input2->getOut());
	return out;
}
