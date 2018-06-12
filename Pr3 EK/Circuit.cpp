#include "Circuit.h"

using namespace std;


Circuit::Circuit() {
	try {
		vcc = new Vcc();
		gnd = new Gnd();
	}
	catch (const bad_alloc & ba) {
		cout << "Blad alokacji!! " << ba.what() << endl;
		delete vcc;
		delete gnd;
		//pomyslec nad rzuceniem wyjatku zeby poinformowac ze nie udalo sie zaalokowac vcc lub gnd wiec nie powinnismy juz wcale tworzyc ukladu!
	}
}

Circuit::~Circuit() {
	delete vcc;
	delete gnd;
	for (unsigned i = 0; i < gatesVector.size(); ++i) {
		delete gatesVector[i];
	}
}

bool Circuit::simulate() {
	for (unsigned i = 0; i < gatesVector.size(); ++i) {
		gatesVector[i]->calOut();
	}
	return circuitOut->getOut();
}

bool Circuit::loadCircuit() {
	cout << "LOAD" << endl;
	fstream file;
	stringstream ssline;
	/*string line, sid, gate, sin1, sin2;
	int id, in1=-3, in2=-3;*/
	Gate* last = nullptr;
	file.open("Circuit.txt", ios::in);
	if (!file.good()) {
		throw bad_open_file();
	}
	while (file.good()) {
		ssline.clear();
		/*in1 = -3;
		in2 = -3;*/
		string line, sid, gate, sin1, sin2;
		int id, in1 = -3, in2 = -3;
		getline(file, line, '\n');
		if (line == "") {
			break;
		}
		ssline << line;
		ssline >> sid;
		if (sid.substr(0,2) != "id") {
			throw bad_load_from_file("Bledne id");
		}
		sid.erase(0, 2);
		id = atoi(sid.c_str());
		if (id < 0) {
			throw bad_load_from_file("Bledne id");
		}
		//wczytywanie bramki (rodzaju, wejsc)
		ssline >> gate;
		if (gate == "AND" || gate == "OR" || gate == "XOR" || gate == "NOR" || gate == "NAND") {
			ssline >> sin1 >> sin2;
			if (sin1 == "1") {
				in1 = -2;
			} else if (sin1 == "0") {
				in1 = -1;
			}
			if (sin2 == "1") {
				in2 = -2;
			} else if (sin2 == "0") {
				in2 = -1;
			}
			if (sin1.substr(0, 2) != "id" && in1 == -3) {
				throw bad_load_from_file("Bledne wejscie");
			}
			if (sin2.substr(0, 2) != "id" && in2 == -3) {
				throw bad_load_from_file("Bledne wejscie");
			}
			if (in1 == -3) {
				sin1 = sin1.erase(0, 2);
				for (unsigned i = 0; i < sin1.size(); ++i) {
					if (!isdigit(sin1[i]))
						throw bad_load_from_file("Bledne wejscie");
				}
				in1 = atoi(sin1.c_str());
			}
			if (in2 == -3) {
				sin2 = sin2.erase(0, 2);
				for (unsigned i = 0; i < sin2.size(); ++i) {
					if (!isdigit(sin2[i]))
						throw bad_load_from_file("Bledne wejscie");
				}
				in2 = atoi(sin2.c_str());
			}
		}
		else if (gate == "NOT") {
			ssline >> sin1;
			if (sin1 == "1") {
				in1 = -2;
			} else if (sin1 == "0") {
				in1 = -1;
			}
			if (sin1.substr(0, 2) != "id" && in1 == -3) {
				throw bad_load_from_file("Bledne wejscie");
			}
			if (in1 == -3) {
				sin1 = sin1.erase(0, 2);
				for (unsigned i = 0; i < sin1.size(); ++i) {
					if (!isdigit(sin1[i]))
						throw bad_load_from_file("Bledne wejscie");
				}
				in1 = atoi(sin1.c_str());
			}
		} else {
			throw bad_load_from_file("Bledna nazwa bramki");
		}
		//Stoworzenie bramki i wrzucenie do gatesVextor
		if (gate == "AND") {
			And* ptr;
			try {
				ptr = new And(id, in1, in2);
			} catch (const bad_alloc & ba) {
				throw ba.what();
			}
			last = ptr;
			gatesVector.push_back(ptr);
		} else if (gate == "OR") {
			Or* ptr;
			try {
				ptr = new Or(id, in1, in2);
			} catch (const bad_alloc & ba) {
				throw ba.what();
			}
			last = ptr;
			gatesVector.push_back(ptr);
		} else if (gate == "NOR") {
			Nor* ptr;
			try {
				ptr = new Nor(id, in1, in2);
			} catch (const bad_alloc & ba) {
				throw ba.what();
			}
			last = ptr;
			gatesVector.push_back(ptr);
		} else if (gate == "NAND") {
			Nand* ptr;
			try {
				ptr = new Nand(id, in1, in2);
			} catch (const bad_alloc & ba) {
				throw ba.what();
			}
			last = ptr;
			gatesVector.push_back(ptr);
		} else if (gate == "XOR") {
			Xor* ptr;
			try {
				ptr = new Xor(id, in1, in2);
			} catch (const bad_alloc & ba) {
				throw ba.what();
			}
			last = ptr;
			gatesVector.push_back(ptr);
		} else if (gate == "NOT") {
			Not* ptr;
			try {
				ptr = new Not(id, in1);
			} catch (const bad_alloc & ba) {
				throw ba.what();
			}
			last = ptr;
			gatesVector.push_back(ptr);
		} else {
			throw("Bledna nazwa bramki");
		}
	}//wczytywanie z pliku
	for (unsigned i = 0; i < gatesVector.size(); ++i) {
		gatesVector[i]->setInputsPointers(gatesVector, vcc, gnd);
	}
	circuitOut = last;
	return 1;
}

unsigned Circuit::getSizeCircuit() const {
	return gatesVector.size();
}

bool Circuit::getCircuitOut() const {
	return circuitOut->getOut();
}

void Circuit::showCircuit() const {
	cout << "Show" << endl;
	for (unsigned i = 0; i < gatesVector.size(); ++i) {
		Gate * gate = gatesVector[i];
		cout << i << " " << gate->getId() << " " << gate->getIn1() << " " << gate->getIn2() << endl;
	}
}

bool Circuit::getGateOut(int id) const {
	if (id<0 || id>gatesVector.size())
		return 0;
	return gatesVector[id]->getOut();
}

std::ostream & operator<<(std::ostream & os, const Circuit & cir) {
	// TODO: tu wstawiæ instrukcjê return
	for (unsigned i = 0; i < cir.gatesVector.size(); ++i) {
		Gate * gate = cir.gatesVector[i];
		os << i << " " << gate->getId() << " " << gate->getIn1() << " " << gate->getIn2() << endl;
	}
	return os;
}
