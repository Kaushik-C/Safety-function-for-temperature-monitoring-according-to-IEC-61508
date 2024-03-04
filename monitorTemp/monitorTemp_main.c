/* -------------------------------------------------------------------------------------
 * Module Name: Test Safe Temperature Monitoring
 * File Name: monitorTemp_main.c
 * Created on: 16.06.2023
 * Original Author: Kaushiknarayanan Chandrasekaran
 * Development Group: Unicorn Testing GmbH
 * Project: FSQM SW Development Exercise
 * Dependencies: none
 *
 * Description: This file contains the main function which only will
 * be used for testing and debugging the software functions defined in monitorTemp.h
 *
 * -------------------------------------------------------------------------------------
 * Versions:
 *
 * Version: 0.1 (under development)
 * Modified on: 16.06.2023
 * Description of Modifications:
 * Initial version, definition of main function, including monitorTemp.h
 *
 * ------------------------------------------------------------------------------------- */


// Include system header files
#include <stdio.h>					// stdio.h is necessary for printing/reading via standard IO

// Include own header files
// The module to be tested shall be included here
#include "monitorTemp.h"
// If test functions are defined within own libraries, these headers must be included:
#include "blackboxtesting.h"
#include "negative_boundary_whitebox_testing.h"
#include "statistical_codecov_testing.h"


/* -----------------------------------------------------------
* Main function
* The main function will be used for testing and debugging only
* 	Parameters: none
* 	Return value: 0
* -----------------------------------------------------------*/
int main(void) {

	// Definition of local variables
	unsigned int test_result = 0;		// Contains the test result; 1: Test OK, 0: Test failed

	// For printf() function, buffer setting (no buffering)
	setvbuf(stdout, NULL, _IONBF, 0);

	// The following tests will only work if the test functions are defined according to the following function names.
	// If own test function names are applied, the following source code must be modified.
	// Test functions may be defined in own libraries or in this source code file after the main function.
	// Black Box Tests
	test_result = PerformBlackBoxTest();
	printf("\n\nResult of Black Box Tests: %d (1: OK, 0: Fail)\n\n\n", test_result);

	// Negative Tests
	test_result = PerformNegativeTest();
	printf("\n\nResult of Negative Tests: %d (1: OK, 0: Fail)\n\n\n", test_result);

	// Boundary Tests
	test_result = PerformBoundaryTest();
	printf("\n\nResult of Boundary Tests: %d (1: OK, 0: Fail)\n\n\n", test_result);

	// White Box Tests
	test_result = PerformWhiteBoxTest();
	printf("\n\nResult of White Box Tests: %d (1: OK, 0: Fail)\n\n\n", test_result);

	// Code Coverage Tests
	test_result = PerformCodeCoverageTest();
	printf("\n\nResult of Code Coverage Tests: %d (1: OK, 0: Fail)\n\n\n", test_result);

	// Statistical Tests
	test_result = PerformStatisticalTest();
	printf("\n\nResult of Statistical Tests: %d (1: OK, 0: Fail)\n\n\n", test_result);

	return 0;

}


// End of file monitorTemp_main.c
