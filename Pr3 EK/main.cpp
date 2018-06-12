#include "Circuit.h"
#include "MyExceptions.h"

#include <iostream>
#include <string>

using namespace std;
int main() {
	Circuit cir;
	try {
		cir.loadCircuit();
	} catch(const bad_load_from_file & bl){
		cout << bl.what() << endl;
		return -1;
	} catch (const bad_open_file& bof) {
		cout << bof.what() << endl;
		return -1;
	}	catch (const char* cont) {
		cout << cont << endl;
		return -1;
	} catch (const string cont) {
		cout << cont << endl;
		return -1;
	}
	//cir.showCircuit();
	for (unsigned i = 0; i < 10; i++) {
		cir.simulate();
		cout << "Symulacja " << i + 1 << endl;
		for (unsigned j = 0; j < cir.getSizeCircuit(); ++j) {
			cout << "Bramka id" << j << " out: " << cir.getGateOut(j) << endl;
		}
		cout << "OUT: " << cir.getCircuitOut() << endl;;
	}
	return 0;
}