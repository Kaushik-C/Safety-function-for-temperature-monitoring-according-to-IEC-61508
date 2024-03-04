/* ---------------------------------------------------------------------------------------------
 * Module Name: Safe Temperature Monitoring
 * File Name: monitorTemp.h
 * Corresponding Source-File: monitorTemp.c
 * Created on: 16.06.2023
 * Original Author: Kaushiknarayanan Chandrasekaran
 * Development Group: CKN GmbH
 * Project: FSQM SW Development Exercise
 * Dependencies: displayTemp() is hardware dependent, it might be necessary to replace stdio.h,
 * 		absolute maximum temperature is limited to 1000 °C / 1832 °F (default values),
 * 		can be adapted (see constants ABS_MAXTEMP_C and ABS_MAXTEMP_F)
 *
 * Description: This file contains the function prototypes, which are necessary for
 * safe temperature monitoring. The implementation of the functions can be found in the
 * corresponding source file monitorTemp.c
 *
 *  monitorTemp() is the function which evaluates the temperature of two independent sensors;
 *  the function can be used on the US and European market, i.e. it can switch between °C and °F
 *
 *  checkTemp() is an auxiliary function, which checks the valid temperature range of the measured temperatures
 *
 *  displayTemp() is an auxiliary function, which shows actual temperatures and messages on a display
 *  WARNING: displayTemp() is hardware dependent!!!
 *
 *  calcC2F() is an auxiliary function, which calculates temperature in Celsius to Fahrenheit
 *
 *  calcF2C() is an auxiliary function, which calculates temeprature in Fahrenheit to Celcius
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

// Only make declarations if library hasn't been used before
#ifndef MONITORTEMP_H_
#define MONITORTEMP_H_


// #define statements
// Note: #define statements should be avoided in safety relevant software (only if other solutions are not reasonable)
// No define statements are used in monitorTemp.c

// Declaration of global constants
// Note: Global constants should not be used in safety relevant software (only if other solutions are not reasonable)
// No global constants are used in monitorTemp.c

// Declaration of global variables
// Note: Global variables should not be used in safety relevant software (only if other solutions are not reasonable)
// No global variables are used in monitorTemp.c



// Declaration of all function prototypes which shall be realized in monitorTemp.c including all parameters and return values
// Function declarations are "extern", so that the compiler only carries out a function declaration and not a definition;
// this safes memory, because memory is claimed by the compiler only, if the function is really used (and then defined) in the application.
// Further explanations for each function can be found in monitorTemp.c
extern unsigned int MonitorTemp(char format, float min_temp, float max_temp, float max_deltatemp, float temp_sensor1, float temp_sensor2);
extern unsigned int CheckTemp(float min_temp, float max_temp, float max_deltatemp, float temp_sensor1, float temp_sensor2);
extern void DisplayTemp(char format, float temp_sensor1, float temp_sensor2, unsigned int temp_ok);
extern float CalcC2F(float temp_c);
extern float CalcF2C(float temp_f);


#endif // MONITORTEMP_H_

// End of file monitorTemp.h

