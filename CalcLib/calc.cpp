#include "calc.h"
#include <stdexcept>
#include <istream>

int calc(std::istream &input) {
	int rhs{};
	int lhs {};
	char c {};
	input >> lhs >> c >> rhs;
	if(input){
	return calc(lhs, rhs, c);
	}
	throw std::invalid_argument{"Invalid format of calculation"};
}

int calc(int lhs, int rhs, char op) {
	int r{};
	switch(op){
		case '+':
			r =  lhs + rhs;
			break;
		case '-':
			r = lhs - rhs;
			break;
		case '/':
			if (rhs == 0){
				throw std::invalid_argument{"You can not divide with 0."};
			}
			r = lhs / rhs;
			break;
		case '*':
			r = lhs * rhs;
			break;
		case '%':
			if (rhs == 0){
				throw std::invalid_argument{"You can not modulo with 0."};
			}
			r = lhs % rhs;
			break;
		default:
			throw std::invalid_argument{"Wrong Operator"};
	}
	return r;
}
