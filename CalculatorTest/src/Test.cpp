#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "calc.h"
#include "sevensegment.h"
#include "pocketcalculator.h"

#include <sstream>

//*********************************
//CALC
//
//ohne stream
void test_one_plus_one() {
  auto result = calc(1, 1, '+');
  ASSERT_EQUAL(2, result);
}

void test_one_times_one(){
	auto result = calc(1, 1, '*');
	ASSERT_EQUAL(1,result);
}

void test_four_through_two(){
	auto result = calc(4,2, '/');
	ASSERT_EQUAL(2, result);
}

void test_one_minus_one(){
	auto result = calc(1,1, '-');
	ASSERT_EQUAL(0, result);
}

void test_four_modulo_two(){
	auto result = calc(4,2, '%');
	ASSERT_EQUAL(0, result);
}

void test_one_minus_three(){
	auto result = calc(1,3, '-');
	ASSERT_EQUAL(-2, result);
}

void test_one_times_minusone(){
	auto result = calc(1,-1, '*');
	ASSERT_EQUAL(-1, result);
}

void test_one_times_zero(){
	auto result = calc(1,0, '*');
	ASSERT_EQUAL(0, result);
}



//mit stream
void test_stream_one_plus_one(){
	std::istringstream input{"1+1"};
	auto result = calc(input);
	ASSERT_EQUAL(2, result);
}

void test_stream_one_plus_one_ws(){
	std::istringstream input{"1 + 1"};
	auto result = calc(input);
	ASSERT_EQUAL(2, result);
}

void test_stream_three_times_2(){
	std::istringstream input{"3 * 2"};
	auto result = calc(input);
	ASSERT_EQUAL(6, result);
}

void test_stream_4_through_2(){
	std::istringstream input{"4 / 2"};
	auto result = calc(input);
	ASSERT_EQUAL(2, result);
}

void test_stream_one_minus_three(){
	std::istringstream input{"1 - 3"};
	auto result = calc(input);
	ASSERT_EQUAL(-2, result);
}

void test_stream_four_modulo_two(){
	std::istringstream input{"4 % 2"};
	auto result = calc(input);
	ASSERT_EQUAL(0, result);
}

void test_stream_divide_by_zero(){
	std::istringstream input{"4 / 0"};
	ASSERT_THROWS(calc(input), std::invalid_argument);
}
//*********************************************************

//*********************************************************
//PRINT
//
void testPrintLargeDigitZero() {
  std::ostringstream output{};
  printLargeDigit(0, output);
  ASSERT_EQUAL(" - \n"
		  	   "| |\n"
		  	   "   \n"
		  	   "| |\n"
		  	   " - \n", output.str());
}


void testPrintLargeNumberTwelve(){
	std::ostringstream output{};
	printLargeNumber(12, output);
	ASSERT_EQUAL(	"    - \n"
					"  |  |\n"
					"    - \n"
					"  ||  \n"
					"    - \n", output.str());
}


void testPrintLargeNumberMinusTwelve(){
	std::ostringstream output{};
	printLargeNumber(-12, output);
	ASSERT_EQUAL(	"       - \n"
					"     |  |\n"
					"---    - \n"
					"     ||  \n"
					"       - \n", output.str());
}
//************************************************************
// pocketcalc
//************************************************************

void testPocketcalc(){
	std::ostringstream output{};
	std::istringstream input{"3*4"};
	pocketcalculator(input, output);
	ASSERT_EQUAL(		"    - \n"
						"  |  |\n"
						"    - \n"
						"  ||  \n"
						"    - \n", output.str());
}


void testPocketcalcMinus(){
	std::ostringstream output{};
	std::istringstream input{"-3*4"};
	pocketcalculator(input, output);
	ASSERT_EQUAL(		"       - \n"
						"     |  |\n"
						"---    - \n"
						"     ||  \n"
						"       - \n", output.str());
}



//*************************************************************

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(test_one_plus_one));
	s.push_back(CUTE(test_one_times_one));
	s.push_back(CUTE(test_four_through_two));
	s.push_back(CUTE(test_one_minus_one));
	s.push_back(CUTE(test_stream_one_plus_one));
	s.push_back(CUTE(test_stream_four_modulo_two));
	s.push_back(CUTE(test_stream_one_minus_three));
	s.push_back(CUTE(test_stream_4_through_2));
	s.push_back(CUTE(test_stream_three_times_2));
	s.push_back(CUTE(test_stream_one_plus_one_ws));
	s.push_back(CUTE(test_one_times_minusone));
	s.push_back(CUTE(test_one_times_zero));
	s.push_back(CUTE(test_four_modulo_two));
	s.push_back(CUTE(test_one_minus_three));
	s.push_back(CUTE(test_stream_divide_by_zero));
	s.push_back(CUTE(testPrintLargeDigitZero));
	s.push_back(CUTE(testPrintLargeNumberTwelve));
	s.push_back(CUTE(testPrintLargeNumberMinusTwelve));
	s.push_back(CUTE(testPocketcalc));
	s.push_back(CUTE(testPocketcalcMinus));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
