/* ---------------------------------------------------------------------------------------------
 * Module Name: Safe Temperature Monitoring
 * File Name: negative_boundary_whitebox_testing.h
 * Corresponding Source-File: negative_boundary_whitebox_testing.c
 * Created on: 16.06.2023
 * Original Author: Kaushiknarayanan Chandrasekaran
 * Development Group: CKN GmbH
 * Project: FSQM SW Development Exercise
 * Dependencies: displayTemp() is hardware dependent, it might be necessary to replace stdio.h,
 * 		absolute maximum temperature is limited to 1000 °C / 1832 °F (default values),
 * 		can be adapted (see constants ABS_MAXTEMP_C and ABS_MAXTEMP_F)
 *
 * Description: This file contains the negative boundary white box test cases for testing the Safe Temperature Monitoring module
 *

 * ----------------------------------------------------------------------------------------------
 * Versions:
 *
 * Version: 0.1 (under development)
 * Modified on: 16.06.2023
 * Modified by: Kaushiknarayanan Chandrasekaran
 * Description of Modifications:
 * Initial version, definition of functions, including standard library stdio.h
 *
 * ----------------------------------------------------------------------------------------------  */

#ifndef NEGATIVE_BOUNDARY_WHITEBOX_TESTING_H_
#define NEGATIVE_BOUNDARY_WHITEBOX_TESTING_H_

extern unsigned int PerformNegativeTest(void);

extern unsigned int PerformBoundaryTest(void);

extern unsigned int PerformWhiteBoxTest(void);

#endif /* NEGATIVE_BOUNDARY_WHITEBOX_TESTING_H_ */
