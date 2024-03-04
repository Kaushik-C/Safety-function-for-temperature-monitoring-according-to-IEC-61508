/* ---------------------------------------------------------------------------------------------
* Module Name: Statistical Code Coverage Testing for MonitorTemp()
* File Name: statistical_codecov_testing.c
* Corresponding Header-File: statistical_codecov_testing.h
* Created on: 16.06.2023
* Original Author: Kaushiknarayanan Chandrasekaran
* Development Group: CKN GmbH
* Project: FSQM SW Development Exercise (Statistical Code Coverage Testing Functions for MonitorTemp())
* Dependencies: MonitorTemp(), stdio.h (hardware dependent)
*
* Description: This file contains black box testing function for MonitorTemp()
*
* PerfomBlackBoxTest() is a function, which carries out different tests with MonitorTemp() using
* a set of representative values, respectively
*
* ----------------------------------------------------------------------------------------------
* Versions:
* Version: 0.1 (under development)
* Modified on: 16.06.2023
* Modified by: Kaushiknarayanan Chandrasekaran
* Description of Modifications:
* 2 statistical code coverage tests were implemented

*
* ----------------------------------------------------------------------------------------------*/
// Include system header files
#include <stdio.h> // stdio.h is necessary for printing/reading via standard IO
#include <string.h> // string.h is necessary for string operations
// Include own header files
#include "monitorTemp.h"
// Definition of global constants (only if really necessary, see coding rules)
// No globals
// Definition of global variables (should be avoided, see coding rules)
// No globals
// Definition of global and local functions (sorted by topic, if possible)

/*---------------------------------------------------
* Definition of function PerformStatisticalTest()
* Parameters:
* None
* Return value:
* test_complete: unsigned integer, 1 if all tests were succesful, 0 if one or more tests failed
------------------------------------------------------*/
unsigned int PerformStatisticalTest(void) {
	// Definition of local variables
	unsigned int temp_ok = 5; // result of temperature monitoring, valid results are 7 (temp OK)
	// 5 (sensor or function failure) or 3 (out of temperature range alarm)
	char message[40]; // String array for test result message
	unsigned int total_tests = 0; // Total number of tests
	unsigned int successful_tests = 0; // Total number of successful test

	unsigned int test_complete = 0; // 1 if all tests OK, 0 if one or more tests failed
	// For printf() function, buffer setting (no buffering)
	setvbuf(stdout, NULL, _IONBF, 0);
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Test scripts for statistical testing
	// statistical testing (robustness tests), code coverage testing (decision coverage)
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Statistical tests (ST) with several representative values (positive testing)
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// First part: Test with values in Celcius
	// +++++++++++++++++++++++++++++++++++++++
	// ST1: Check temperature with representative values, temperature range OK
	total_tests++;
	printf("\n\nST1: Test with representative values, temperature range OK\n");
	// Initialize test result message with negative test result, will only be changed if test is successful
	strcpy(message, "ST1 FAILED, Error Code: \0");
	// Parameters for MonitorTemp: Format, Min Temp, Max Temp, Max Delta, Temp Sensor 1, Temp Sensor 2
	temp_ok = MonitorTemp('C', -273.15, 1000.0, 3.0, 55.1, 57.6);
	// Expected return value: 7
	if (temp_ok == 7) {
		strcpy(message, "ST1 SUCCESFUL, Return value: \0");
		successful_tests++;
	}
	// Print test result
	printf("\n%s%d", message, temp_ok);
	// End of ST1

	// ST2: Check temperature with representative values, temperature range OK
	total_tests++;
	printf("\n\nST2: Test with representative values, temperature range OK\n");
	// Initialize test result message with negative test result, will only be changed if test is successful
	strcpy(message, "ST2 FAILED, Error Code: \0");
	// Parameters for MonitorTemp: Format, Min Temp, Max Temp, Max Delta, Temp Sensor 1, Temp Sensor 2
	temp_ok = MonitorTemp('C', -273.15, 1000.0, 6.0, 89.6, 94.2);
	// Expected return value: 7
	if (temp_ok == 7) {
		strcpy(message, "ST2 SUCCESFUL, Return value: \0");
		successful_tests++;
	}
	// Print test result
	printf("\n%s%d", message, temp_ok);
	// End of ST2

	test_complete = (successful_tests == total_tests);

	return test_complete;
}

/*---------------------------------------------------
* Definition of function PerformCodeCoverageTest()
* Parameters:
* None
* Return value:
* test_complete: unsigned integer, 1 if all tests were succesful, 0 if one or more tests failed
------------------------------------------------------*/
unsigned int PerformCodeCoverageTest(void) {
	// Definition of local variables
	unsigned int temp_ok = 5; // result of temperature monitoring, valid results are 7 (temp OK)
	// 5 (sensor or function failure) or 3 (out of temperature range alarm)
	char message[40]; // String array for test result message
	unsigned int total_tests = 0; // Total number of tests
	unsigned int successful_tests = 0; // Total number of successful test

	unsigned int test_complete = 0; // 1 if all tests OK, 0 if one or more tests failed
	// For printf() function, buffer setting (no buffering)
	setvbuf(stdout, NULL, _IONBF, 0);
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Test scripts for statistical testing
	// statistical testing (robustness tests), code coverage testing (decision coverage)
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// Code Coverage tests (CCT) with several representative values (positive testing)
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// First part: Test with values in Celcius
	// +++++++++++++++++++++++++++++++++++++++
	// CCT1: Check temperature with representative values, temperature range OK
	total_tests++;
	printf("\n\nCCT1: Test with representative values, temperature range OK\n");
	// Initialize test result message with negative test result, will only be changed if test is successful
	strcpy(message, "CCT1 FAILED, Error Code: \0");
	// Parameters for MonitorTemp: Format, Min Temp, Max Temp, Max Delta, Temp Sensor 1, Temp Sensor 2
	temp_ok = MonitorTemp('C', -273.15, 1000.0, 8.0, 55.1, 62);
	// Expected return value: 7
	if (temp_ok == 7) {
		strcpy(message, "CCT1 SUCCESFUL, Return value: \0");
		successful_tests++;
	}
	// Print test result
	printf("\n%s%d", message, temp_ok);
	// End of CCT1

	// CCT: Check temperature with representative values, temperature range OK
	total_tests++;
	printf("\n\nCCT2: Test with representative values, temperature range OK\n");
	// Initialize test result message with negative test result, will only be changed if test is successful
	strcpy(message, "CCT2 FAILED, Error Code: \0");
	// Parameters for MonitorTemp: Format, Min Temp, Max Temp, Max Delta, Temp Sensor 1, Temp Sensor 2
	temp_ok = MonitorTemp('C', -273.15, 1000.0, 4.0, 90.2, 94.2);
	// Expected return value: 7
	if (temp_ok == 7) {
		strcpy(message, "CCT2 SUCCESFUL, Return value: \0");
		successful_tests++;
	}
	// Print test result
	printf("\n%s%d", message, temp_ok);
	// End of CCT2

	test_complete = (successful_tests == total_tests);

	return test_complete;

}
