#include "Support.h"

#include <iostream>
#include <limits>
#include <chrono>
#include <thread>

#if defined(_WIN32)
const bool WIN32 = true;
#else
const bool WIN32 = false;
#endif

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

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

	void System::pauseAndClear() {
		pause();
		clear();
	}

	void System::ignoreCinMax() {
		cin.ignore(numeric_limits<int>::max(), '\n');
	}

	void System::clear() {
		(WIN32) ? system("cls") : system("clear");
	}

	void System::sleep(unsigned int timeInMilliseconds) {
		sleep_for(milliseconds(timeInMilliseconds));
	}


}