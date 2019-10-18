#include "pocketcalculator.h"
#include "sevensegment.h"
#include "calc.h"

#include <cmath>
#include <exception>
#include <string>
#include <sstream>


void pocketcalculator(std::istream &in, std::ostream &out){
	int const maxLen {8};
	std::string s{};
	while(std::getline(in, s)){
		try{
			std::istringstream stream {s};
			auto result = calc(stream);
			if(result > std::pow(10, maxLen)){
				printLargeError(out);
			} else {
				printLargeNumber(result, out);
			}

		} catch(std::exception const &e) {
			printLargeError(out);
		} catch(...){
			//Unknown
		}
	}
}
