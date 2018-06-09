#pragma once
#ifndef GATE_H
#define GATE_H
#include <vector>

class Gate{
protected:
	bool out;
	int id;
	Gate* input1;
	Gate* input2;
	int in1id, in2id;
public:
	//Gate(int id_, int in1_, int in2_);
	virtual ~Gate() {};
	bool getOut() const {
		return out;
	}
	virtual bool calOut()=0;
	virtual bool setInputsPointers(std::vector<Gate*>& gatesVector,  Gate* vcc,  Gate* gnd) {
		bool set1 = false, set2 = false;
		if (in1id == -1) { //gnd
			input1 = gnd;
			set1 = true;
		}
		else if (in1id == -2) { //vcc
			input1 = vcc;
			set1 = true;
		}
		if (in2id == -1) { //gnd
			input2 = gnd;
			set2 = true;
		}
		else if (in2id == -2) { //vcc
			input2 = vcc;
			set2 = true;
		}
		if (set1 && set2)
			return true;

		for (unsigned i = 0; i < gatesVector.size(); ++i) { // ustawienie wskaznikow input1, input2
			Gate* g = gatesVector[i];
			if (g->id == in1id) {
				input1 = g;
				set1 = true;
			}
			if (g->id == in2id) {
				input2 = g;
				set2 = true;
			}
			if (set1 && set2) //ustwiono oba wskazniki wejsc
				return true;
		}
		return false;
	}
	/*std::ostream & operator<<(const std::ostream& os) {
		return  os << this->id << " " << this->in1id << " " << this->input2 << std::endl;
	}*/
	int getIn1()const {
		return in1id;
	}
	int getIn2()const {
		return in2id;
	}
	int getId()const {
		return id;
	}
};
#endif // !GATE_H
