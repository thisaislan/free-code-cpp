#include "Support.h"

#include <iostream>

#if defined(_WIN32)
const bool WIN32 = true;
#else
const bool WIN32 = false;
#endif

using std::cout;
using std::cin;
using std::endl;

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

}