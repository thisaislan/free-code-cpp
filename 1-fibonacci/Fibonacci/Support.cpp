#include "Support.h"

#include <iostream>
#include <limits>

#if defined(_WIN32)
const bool WIN32 = true;
#else
const bool WIN32 = false;
#endif

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;

namespace support {

	void System::pause() {
		if (WIN32) {
			system("pause");
		} else {
			cin.clear();
			cout << "Press enter to continue...";
			cin.ignore();
		}
	}

	void System::ignoreCinMax() {
		cin.ignore(numeric_limits<int>::max(), '\n');
	}

}