#include "sevensegment.h"

#include <algorithm>
#include <ostream>
#include <vector>
#include <string>
#include <iterator>


std::vector<std::vector<std::string>> getDigits(){
	std::vector<std::string> const zero { 	" - ", "| |", "   ", "| |", " - " };
	std::vector<std::string> const one {  	"   ", "  |", "   ", "  |", "   " };
	std::vector<std::string> const two { 	" - ", "  |", " - ", "|  ", " - " };
	std::vector<std::string> const three { 	" - ", "  |", " - ", "  |", " - " };
	std::vector<std::string> const four { 	"   ", "| |", " - ", "  |", "   " };
	std::vector<std::string> const five { 	" - ", "|  ", " - ", "  |", " - " };
	std::vector<std::string> const six { 	" - ", "|  ", " - ", "| |", " - " };
	std::vector<std::string> const seven { 	" - ", "  |", "   ", "  |", "   " };
	std::vector<std::string> const eight { 	" - ", "| |", " - ", "| |", " - " };
	std::vector<std::string> const nine { 	" - ", "| |", " - ", "  |", " - " };
	std::vector<std::string> const minus { 	"   ", "   ", " - ", "   ", "   " };
	std::vector<std::vector<std::string>> const digits { zero, one, two, three, four, five, six, seven, eight, nine, minus };
	return digits;

}




void printLargeNumber(int i, std::ostream &out){
	std::vector<std::string> output{5, ""};
	std::vector<int> numbers{};
	auto digits = getDigits();


	if (i < 0){
		numbers.push_back(10);
		i *= -1;
	}

	std::string input = std::to_string(i);
	for (char &c: input){
		numbers.push_back(c - '0');
	}

	for(auto x: numbers){
		int count = 0;
		for (std::string s: digits[x]){
			output[count].append(s);
			++count;
		}
	}

	std::copy(output.begin(), output.end(), std::ostream_iterator<std::string>(out, "\n"));
}




void printLargeDigit(int i, std::ostream &out){
	std::vector<std::string> dig = getDigits()[i];
	std::copy(dig.begin(), dig.end(), std::ostream_iterator<std::string>(out, "\n"));

}



void printLargeError(std::ostream &out){
	out <<	" -             \n"
			"|              \n"
			" -  -  -  -  - \n"
			"|  |  |  | ||  \n"
			" -        -    \n";
}

