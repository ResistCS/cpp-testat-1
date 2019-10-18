#include "pocketcalculator.h"
#include "calc.h"
#include "sevensegment.h"

#include <cmath>
#include <exception>
#include <sstream>
#include <string>

void pocketcalculator(std::istream &in, std::ostream &out) {
	int const maxLen { 8 };
	std::string s { };
	while (std::getline(in, s)) {
		try {
			std::istringstream is { s };
			int result = calc(is);
			if (result > std::pow(10, maxLen)) {
				printLargeError(out);
			} else {
				printLargeNumber(result, out);
			}
		} catch (std::exception const &e) {
			printLargeError(out);
		}
	}
}
