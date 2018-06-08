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
}

bool Circuit::simulate() {
	return false;
}

bool Circuit::loadCircuit() {
	fstream file;
	file.open("Circuit.txt", ios::in);
	if (!file.good()) {
		throw bad_open_file();
	}
}
