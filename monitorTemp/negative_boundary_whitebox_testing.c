/* ---------------------------------------------------------------------------------------------
* Module Name: Negative/Boundary/Whitebox Testing for MonitorTemp()
* File Name: negative_boundary_whitebox_testing.c
* Corresponding Header-File: negative_boundary_whitebox_testing.h
* Created on: 16.06.2023
* Original Author: Kaushiknarayanan Chandrasekaran
* Development Group: CKN GmbH
* Project: FSQM SW Development Exercise (Negative/Boundary/White Box Testing Functions for MonitorTemp())
* Dependencies: MonitorTemp(), stdio.h (hardware dependent), ABS_MAXTEMP_C and ABS_MAXTEMP_F must
* be adapted if these constants are changed in monitorTemp.c
*
* Description: This file contains negative/boundary/white box testing function for MonitorTemp()
*
* PerfomNegativeTest() is a function, which carries out different tests with MonitorTemp() using
* a set of incorrect parameter values
*
* PerfomBoundaryTest() is a function, which carries out different tests with MonitorTemp() using
* a set of boundary parameter values
*
* PerfomWhiteboxTest() is a function, which carries out different tests with MonitorTemp() using
* some sub-functions with representative parameters
*
* ----------------------------------------------------------------------------------------------
* Versions:
* Version: 0.1 (under development)
* Modified on: 16.06.2023
* Modified by: Kaushiknarayanan Chandrasekaran
* Description of Modifications:
* Initial version, definition of functions, ...
*
* ----------------------------------------------------------------------------------------------*/
// Include system header files
#include <stdio.h> // stdio.h is necessary for printing/reading via standard IO
#include <string.h> // string.h is necessary for string operations
// Include own header files
#include "monitorTemp.h"
// Definition of local (module level) constants
// WARNING: Constants must be adapted, if temperature range shall be extended
// Default is 1000 °C / 1832 °F for absolute maximum temperature
// Absolute maximum temperature in Celsius
//static const float ABS_MAXTEMP_C = 1000.0;
// Absolute maximum temperature in Fahrenheit
//static const float ABS_MAXTEMP_F = 1832.0;
// Definition of global constants (only if really necessary, see coding rules)
// No globals
// Definition of global variables (should be avoided, see coding rules)
// No globals
// Definition of global and local functions (sorted by topic, if possible)


/*---------------------------------------------------------------------
* Definition of function PerformNegativeTest()
* Parameters:
* None
* Return value:
* test_complete: unsigned integer, 1 if all tests were succesful, 0 if one or more tests failed
----------------------------------------------------------------------*/

unsigned int PerformNegativeTest(void) {
	// Definition of local variables
	unsigned int temp_ok = 5; // result of temperature monitoring, valid results are 7 (temp OK)
	// 5 (sensor or function failure) or 3 (out of temperature range alarm)
	char message[40]; // String array for test result message
	unsigned int total_tests = 0; // Total number of tests
	unsigned int successful_tests = 0; // Total number of successful test
	unsigned int test_complete = 0; // 1 if all tests OK, 0 if one or more tests failed
	// For printf() function, buffer setting (no buffering)
	setvbuf(stdout, NULL, _IONBF, 0);
	// ++++++++++++++++++++++++++++++++++++++++
	// Test scripts for negative testing
	// ++++++++++++++++++++++++++++++++++++++++
	// Negative Testing (NT) with incorrect parameter values
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// First part: Test with values in Celcius
	// +++++++++++++++++++++++++++++++++++++++
	// NT1: Check temperature with absolute minimum temperature < -273.15° C
	total_tests++;
	printf("\n\nNT1: Test with absolute minimum temperature < -273.15° C\n");
	// Initialize test result message with negative test result, will only be changed if test is successful
	strcpy(message, "NT1 FAILED, Error Code: \0");
	// Parameters for MonitorTemp: Format, Min Temp, Max Temp, Max Delta, Temp Sensor 1, Temp Sensor 2
	temp_ok = MonitorTemp('C', -274.0, 80.0, 3.0, 50.0, 50.0);
	// Expected return value: 5 (Failure)
	if (temp_ok == 5) {
		strcpy(message, "NT1 SUCCESFUL, Return value: \0");
		successful_tests++;
	}
	// Print test result
	printf("\n%s%d", message, temp_ok);
	// End of NT1
	// NT2: Check temperature with absolute minimum and absolute maximum temperature < -273.15° C
	total_tests++;
	printf("\n\nNT2: Test with absolute minimum and absolute maximum temperature < -273.15° C\n");
	// Initialize test result message with negative test result, will only be changed if test is successful
	strcpy(message, "NT2 FAILED, Error Code: \0");
	// Parameters for MonitorTemp: Format, Min Temp, Max Temp, Max Delta, Temp Sensor 1, Temp Sensor 2
	temp_ok = MonitorTemp('C', -300.0, -274.0, 3.0, 50.0, 50.0);
	// Expected return value: 5 (Failure)
	if (temp_ok == 5) {
		strcpy(message, "NT2 SUCCESFUL, Return value: \0");
		successful_tests++;
	}
	// Print test result
	printf("\n%s%d", message, temp_ok);
	// End of NT2

	test_complete = (successful_tests == total_tests);

	return test_complete;
}

/*---------------------------------------------------------------------
* Definition of function PerformBoundaryTest()
* Parameters:
* None
* Return value:
* test_complete: unsigned integer, 1 if all tests were succesful, 0 if one or more tests failed
----------------------------------------------------------------------*/

unsigned int PerformBoundaryTest(void){

	// Definition of local variables
	unsigned int temp_ok = 5; // result of temperature monitoring, valid results are 7 (temp OK)
	// 5 (sensor or function failure) or 3 (out of temperature range alarm)
	char message[40]; // String array for test result message
	unsigned int total_tests = 0; // Total number of tests
	unsigned int successful_tests = 0; // Total number of successful test
	unsigned int test_complete = 0; // 1 if all tests OK, 0 if one or more tests failed
	// For printf() function, buffer setting (no buffering)
	setvbuf(stdout, NULL, _IONBF, 0);
	// ++++++++++++++++++++++++++++++++++++++++
	// Test scripts for boundary testing
	// ++++++++++++++++++++++++++++++++++++++++
	// Boundary Testing (BT) with minimum temperature values
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// First part: Test with values in Celcius
	// +++++++++++++++++++++++++++++++++++++++
	// BT1: Check temperature with absolute minimum temperature -273.15° C
	total_tests++;
	printf("\n\nBT1: Test with absolute minimum temperature -273.15° C\n");
	// Initialize test result message with negative test result, will only be changed if test is successful
	strcpy(message, "BT1 FAILED, Error Code: \0");
	// Parameters for MonitorTemp: Format, Min Temp, Max Temp, Max Delta, Temp Sensor 1, Temp Sensor 2
	temp_ok = MonitorTemp('C', -273.15, 80.0, 3.0, -273.15, -272.0);
	// Expected return value: 5 (Failure)
	if (temp_ok == 7) {
		strcpy(message, "BT1 SUCCESFUL, Return value: \0");
		successful_tests++;
	}
	// Print test result
	printf("\n%s%d", message, temp_ok);
	// End of BT1

	// NT2: Check temperature with absolute minimum and absolute maximum temperature < -273.15° C
	total_tests++;
	printf("\n\nBT2: Test with absolute minimum and absolute maximum temperature  -273.15° C\n");
	// Initialize test result message with negative test result, will only be changed if test is successful
	strcpy(message, "BT2 FAILED, Error Code: \0");
	// Parameters for MonitorTemp: Format, Min Temp, Max Temp, Max Delta, Temp Sensor 1, Temp Sensor 2
	temp_ok = MonitorTemp('C', -273.15, 80, 3.0, -272.0, -273.15);
	// Expected return value: 5 (Failure)
	if (temp_ok == 7) {
		strcpy(message, "BT2 SUCCESFUL, Return value: \0");
		successful_tests++;
	}
	// Print test result
	printf("\n%s%d", message, temp_ok);
	// End of BT2

	test_complete = (successful_tests == total_tests);

	return test_complete;
}

/*---------------------------------------------------------------------
* Definition of function PerformWhiteBoxTest()
* Parameters:
* None
* Return value:
* test_complete: unsigned integer, 1 if all tests were succesful, 0 if one or more tests failed
----------------------------------------------------------------------*/

unsigned int PerformWhiteBoxTest(void){

	// Definition of local variables
//	unsigned int temp_ok = 5; // result of temperature monitoring, valid results are 7 (temp OK)
	float temp_f = 0;
	// 5 (sensor or function failure) or 3 (out of temperature range alarm)
	char message[40]; // String array for test result message
	unsigned int total_tests = 0; // Total number of tests
	unsigned int successful_tests = 0; // Total number of successful test
	unsigned int test_complete = 0; // 1 if all tests OK, 0 if one or more tests failed
	// For printf() function, buffer setting (no buffering)
	setvbuf(stdout, NULL, _IONBF, 0);

	// ++++++++++++++++++++++++++++++++++++++++
	// Test scripts for White box testing
	// ++++++++++++++++++++++++++++++++++++++++
	// White Box Testing (WBT)
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// First part: calcC2F
	// +++++++++++++++++++++++++++++++++++++++
	// WBT1: Check calcC2F returns expected temperature value
	total_tests++;
	printf("\n\n WBT1: Test to convert celcius to Fahrenheit using calcC2F function\n");
	// Initialize test result message with negative test result, will only be changed if test is successful
	strcpy(message, "WBT1 FAILED, Temperature: ° F\0");
	// Parameters for MonitorTemp: Format, Min Temp, Max Temp, Max Delta, Temp Sensor 1, Temp Sensor 2
	temp_f = CalcC2F(20.0);
	// Expected return value: 5 (Failure)
	if (temp_f == 68.0) {
		strcpy(message, "WBT1 SUCCESFUL, Return value: ° F\0");
		successful_tests++;
	}
	// Print test result
	printf("\n%s%f", message, temp_f);
	// End of WBT1

	// WBT2: Check calcC2F returns expected temperature value
	total_tests++;
	printf("\n\n WBT2: Test to convert celcius to Fahrenheit using calcC2F function\n");
	// Initialize test result message with negative test result, will only be changed if test is successful
	strcpy(message, "WBT2 FAILED, Temperature: ° F\0");
	// Parameters for MonitorTemp: Format, Min Temp, Max Temp, Max Delta, Temp Sensor 1, Temp Sensor 2
	temp_f = CalcC2F(0.0);
	// Expected return value: 5 (Failure)
	if (temp_f == 32.0) {
		strcpy(message, "WBT2 SUCCESFUL, Return value: ° F\0");
		successful_tests++;
	}
	// Print test result
	printf("\n%s%f", message, temp_f);
	// End of WBT2

	test_complete = (successful_tests == total_tests);
	return test_complete;

}

