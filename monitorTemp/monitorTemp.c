/* ---------------------------------------------------------------------------------------------
* Module Name: Safe Temperature Monitoring
* File Name: monitorTemp.c
* Corresponding Header-File: monitorTemp.h
* Created on: 16.06.2023
* Original Author: Kaushiknarayanan Chandrasekaran
* Development Group: CKN GmbH
 * Project: FSQM SW Development Exercise
 * Dependencies: displayTemp() is hardware dependent,
 * 		it might be necessary to replace function for display control,
 * 		absolute maximum temperature is limited to 1000 °C / 1832 °F (default values),
 * 		can be adapted (see local constants ABS_MAXTEMP_C and ABS_MAXTEMP_F)
 *
 * Description: This file contains the functions, which are necessary for
 * safe temperature monitoring.
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
 *  calcF2C() is an auxiliary function, which calculates temperature in Fahrenheit to Celcius
*
*
* ----------------------------------------------------------------------------------------------
* Versions:
* Version: 0.1 (under development)
* Modified on: 16.06.2023
* Modified by: Kaushiknarayanan Chandrasekaran
* Description of Modifications:
* New implementation of MonitorTemp() function
*
* ----------------------------------------------------------------------------------------------*/

// Include system header files
#include <stdio.h> // stdio.h is necessary for printing/reading via standard IO
#include <math.h>  //math.h is necessary for performing mathematical operations
#include <string.h> // string.h is necessary for string operations
#include <stdlib.h> // string.h is necessary for abs operations
// Include own header files
#include "monitorTemp.h"
// Definition of local (module level) constants
// WARNING: Constants must be adapted, if temperature range shall be extended
// Default is 1000 °C / 1832 °F for absolute maximum temperature
// Absolute maximum temperature in Celsius
static const float ABS_MAXTEMP_C = 1000.0;
// Absolute maximum temperature in Fahrenheit
static const float ABS_MAXTEMP_F = 1832.0;
// Absolute minimum temperature in Celsius
static const float ABS_MINTEMP_C = -273.15;
// Absolute minimum temperature in Fahrenheit
static const float ABS_MINTEMP_F = -459.67;

// Declaration of local (module level) functions
// Note: It might be necessary to define a local (help) function for rounding of decimal (float) values...


// Function Definitions
// The name of all defined functions must correspond to the name which was defined in the header file (function prototypes)

/*---------------------------------------------------
* Definition of function MonitorTemp()
* Parameters:
*	format: char 'F' or 'C'
*	min_temp: minimum allowed temperature as float
*	max_temp: maximum allowed temperature as float
*	max_deltatemp: maximum allowed delta temperature between sensor 1 and sensor 2 as float
*	temp_sensor1: actual measured temperature of sensor 1 as float
*	temp_sensor2: actual measured temperature of sensor 2 as float
* Return value:
*	temp_ok: unsigned integer, 7 for temperature range OK, 5 for function failure (i.e. invalid values or sensor failure),
* 		3 for "out of temperature range", alarm
------------------------------------------------------*/
unsigned int MonitorTemp(char format, float min_temp, float max_temp, float max_deltatemp, float temp_sensor1, float temp_sensor2) {

	// Definition of local variables
	unsigned int temp_ok = 3; 				// Return value: result of temperature monitoring; defensive programming: initialize with value 3 (failure)


	/*Plausibility Check for the parameter 'format' */

	if((format == 'C') || (format == 'c'))
	{
		/*Overwriting the format to simplify further operations*/
		format = 'C';
	}
	else if((format == 'F') || (format == 'f'))
	{
		/*Overwriting the format to simplify further operations*/
		format = 'F';
	}
	else
	{
		/*Invalid format passed to the function*/
		temp_ok = 5;
	}

	/*Plausibility Check for the parameter 'min_temp' and 'max_temp' */

	if(((format == 'C') && (min_temp < ABS_MINTEMP_C)) || ((format == 'F') && (min_temp < ABS_MINTEMP_F)))
	{
		/*Invalid min_temp passed to the function*/
		temp_ok = 5;
	}

	if(((format == 'C') && (max_temp > ABS_MAXTEMP_C)) || ((format == 'F') && (max_temp > ABS_MAXTEMP_F)))
	{
		/*Invalid max_temp passed to the function*/
		temp_ok = 5;
	}

	if((min_temp > max_temp) || (max_temp < min_temp))
	{
		/*Invalid max_temp or min_temp passed to the function*/
		temp_ok = 5;
	}


	/*Plausibility Check for the parameter 'max_deltatemp' */

	if(max_deltatemp > (max_temp - min_temp))
	{
		/*Invalid max_deltatemp passed to the function*/
		temp_ok = 5;
	}

	/*Plausibility Check for the parameter 'temp_sensor1' */

	if(((format == 'C') && (temp_sensor1 < ABS_MINTEMP_C)) || ((format == 'F') && (temp_sensor1 < ABS_MINTEMP_F)))
	{
		/*Invalid temp_sensor1 passed to the function*/
		temp_ok = 5;
	}

	if(((format == 'C') && (temp_sensor1 > ABS_MAXTEMP_C)) || ((format == 'F') && (temp_sensor1 > ABS_MAXTEMP_F)))
	{
		/*Invalid temp_sensor1 passed to the function*/
		temp_ok = 5;
	}

	/*Plausibility Check for the parameter 'temp_sensor2' */

	if(((format == 'C') && (temp_sensor2 < ABS_MINTEMP_C)) || ((format == 'F') && (temp_sensor2 < ABS_MINTEMP_F)))
	{
		/*Invalid temp_sensor2 passed to the function*/
		temp_ok = 5;
	}

	if(((format == 'C') && (temp_sensor2 > ABS_MAXTEMP_C)) || ((format == 'F') && (temp_sensor2 > ABS_MAXTEMP_F)))
	{
		/*Invalid temp_sensor2 passed to the function*/
		temp_ok = 5;
	}

	/*Invoke CheckTemp if all the passed function parameters are valid*/
	if(temp_ok != 5)
	{
		temp_ok = CheckTemp(min_temp, max_temp, max_deltatemp, temp_sensor1, temp_sensor2);
	}

	/*Invoke DisplayTemp function to print the results*/
	DisplayTemp(format, temp_sensor1, temp_sensor2, temp_ok);

	return temp_ok;
}


/*------------------------------------------------------------
* Definition of function CheckTemp()
* Parameters:
*	min_temp: minimum allowed temperature as float
*	max_temp: maximum allowed temperature as float
*	max_deltatemp: maximum allowed delta temperature between sensor 1 and sensor 2 as float
*	temp_sensor1: actual measured temperature of sensor 1 as float
*	temp_sensor2: actual measured temperature of sensor 2 as float
* Return value:
*	temp_ok: unsigned integer, 7 for temperature range OK, 5 for function failure (i.e. invald values or sensor failure),
*		3 for "out of temperature range", alarm
--------------------------------------------------------------*/
unsigned int CheckTemp(float min_temp, float max_temp, float max_deltatemp, float temp_sensor1, float temp_sensor2) {

	// Definition of local variable
	unsigned int temp_ok = 5; 				// Return value: Result of temperature range check and verification of delte between sensors
											// Defensive programming: initialize with value 5 (failure)

	/*rounding to 2 decimal places*/
	temp_sensor1 = roundf(temp_sensor1 * 100) / 100;
	temp_sensor2 = roundf(temp_sensor2 * 100) / 100;

	if((abs(temp_sensor1) - abs(temp_sensor2)) > max_deltatemp)
	{
		temp_ok = 3;	//alarm
	}
	else if((temp_sensor1 < min_temp) || (temp_sensor2 < min_temp))
	{
		temp_ok = 3;	//alarm
	}
	else if((temp_sensor1 > max_temp) || (temp_sensor2 > max_temp))
	{
		temp_ok = 3;	//alarm
	}
	else
	{
		temp_ok = 7;	//temperature range OK
	}

	return temp_ok;
}


/*---------------------------------------------------------------------
* Definition of function DisplayTemp()
* WARNING: DisplayTemp() is hardware dependent!!!
* Parameters:
*	format: char 'F' or 'C'
*	temp_sensor1: actual measured temperature of sensor 1 as float
*	temp_sensor2: actual measured temperature of sensor 2 as float
*	temp_ok: unsigned integer, 7 for temperature range OK, 5 for function failure (i.e. invald values or sensor failure),
*		3 for "out of temperature range", alarm
* Return value: none
 * ------------------------------------------------------------------- */
void DisplayTemp(char format, float temp_sensor1, float temp_sensor2, unsigned int temp_ok) {

	// definition of local variables
	float temp_f;					// Temperature in Fahrenheit
	float temp_c;					// Temperature in Celsius
	char message[40];				// String array for message on display


	if(format == 'C')
	{
		temp_c = (temp_sensor1 + temp_sensor2) / 2;
		temp_f = CalcC2F(temp_c);

		printf("actual temperature in chosen format: %f °%C\n",temp_c,format);
		printf("temperature in the respective other format: %f °F\n",temp_f);
	}
	else	/*allowed temperature formats have already been validated in MonitorTemp*/
	{
		temp_f = (temp_sensor1 + temp_sensor2) / 2;
		temp_c = CalcF2C(temp_f);

		printf("actual temperature in chosen format: %f °%C",temp_f,format);
		printf("temperature in the respective other format: %f °C\n",temp_c);
	}

	if(temp_ok == 3)
	{
		strcpy(message, "Temperature range OK \0");
	}
	else if(temp_ok == 5)
	{
		strcpy(message, "Function error \0");
	}
	else
	{
		strcpy(message, "alarm \0");
	}

	printf("\n%s", message);
}



/* -----------------------------------------------
* Definition of function CalcC2F()
* Parameters:
*	tempC: temperature in Celsius as float
* Return value:
*	tempF: temperature in Fahrenheit as float
------------------------------------------------- */
float CalcC2F(float temp_c) {

	// Definition of local variable
	float temp_f = 0;				// Return value, temperature in Fahrenheit


	temp_f = (temp_c * 9/5) + 32;


	return temp_f;

}


/*--------------------------------------------
* Definition of function CalcF2C()
*	Parameters:
*	temp_f: temperature in Fahrenheit as float
* Return value:
*	temp_c: temperature in Celsius as float
---------------------------------------------*/
float CalcF2C(float temp_f) {

	// Definition of local variable
	float temp_c = 0;				// Return value, temperature in Fahrenheit

	temp_c = ((temp_f - 32) * (5/9));

	return temp_c;

}




// Definition of local (module level) functions
// Local help functions may be defined here.



// End of file monitorTemp.c
