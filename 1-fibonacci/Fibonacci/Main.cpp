//
//  C++ lang
//  Created by this.aislan
//  Created with Visual Studio in Windows
//

#include <iostream>

#include "Support.h"

using std::cout;
using std::cin;
using std::endl;

using support::System;

int main() {

	unsigned int numbersOfFibonacci = 0;
	unsigned int aux1 = 0;
	unsigned int aux2 = 1;
	signed int numberToPrint = -1;

	// Get and validation part

	cout << "Please tell how many numbers of the fibonacci sequence you want to see:" << endl;

	do {
		if (cin.fail()) {
			cout << "Please type a number:" << endl;
			cin.clear();
			System::ignoreCinMax();
		} else if (numbersOfFibonacci > 47 || numbersOfFibonacci < 0) {
			cout << "Ops, please type a number between 0 and 47:" << endl;
			cin.clear();
			System::ignoreCinMax();
		}
		cin >> numbersOfFibonacci;
	} while (!cin.good() || numbersOfFibonacci > 47 || numbersOfFibonacci < 0);

	// Fibonnaci here

	for (; numbersOfFibonacci > 0; numbersOfFibonacci--) {
		if (numberToPrint < 1) {
			numberToPrint += 1;
		} else {
			numberToPrint = aux1 + aux2;
			aux1 = aux2;
			aux2 = numberToPrint;
		}
		cout << numberToPrint << endl;
	}

	// And end here :)
	System::pause();
	return EXIT_SUCCESS;
}