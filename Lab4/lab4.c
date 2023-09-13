/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/
	int close_to (double tolerance, double point, double value);
	double mag(double ax, double ay, double az);
	
 
/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
	double tolerance, point, value;
	int Value;
/*
	Data
	Up gy=1
	Down gy=-1
	Left gx =1
	Right gx =-1
	Away gz =1
	Foward gz =-1
*/
	double mag(double ax, double ay, double az);
	
    while (b1 != 1) {
    scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
	double tolerancePass = 0.03;
	double tolerancePass2 = .5;
	double toleranceFail = 0.70;
	double pointN = -1.0;
	double pointP = 1.0;
	double pointZ = 0.0;
		if(close_to (toleranceFail, pointZ, gx) == 1){

	}
		else if((close_to (tolerancePass, pointP, gx) == 1) && (value != 1)){
		printf("Left\n");
		value = 1;
		
	}
	    else if((close_to (tolerancePass2, pointN, gx) == 1) && (value != 2)){
		printf("Right\n");
		value = 2;
	}

	if(close_to (toleranceFail, pointZ, gy) == 1){

	}
		else if((close_to (tolerancePass, pointP, gy) == 1) && (value != 3)){
		printf("Up\n");
		value = 3;
		
	}
	    else if((close_to (tolerancePass, pointN, gy) == 1) && (value != 4)){
		printf("Down\n");
		value = 4;
	}
	
	
	if(close_to (toleranceFail, pointZ, gz) == 1){

	}
		else if((close_to (tolerancePass2, pointP, gz) == 1) && (value != 5)){
		printf("Away\n");
		value = 5;

	}
	    else if((close_to (tolerancePass, pointN, gz) == 1) && (value != 6)){
		printf("Towards\n");
		value = 6;
	}

    // printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */
    //   printf("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);
	/*
		if(mag(ax, ay, az) >= 0.05){
		printf("DualShock4 is moving\n");
		}
		else{
		printf("DualShock4 isn't moving\n");
		}
	*/
		/* It would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
         (lab 3).  You will also need to copy your prototypes and functions to the appropriate sections
         in this program. */

       //printf("At %d ms, the acceleration's magnitude was: %f\n", t, mag(ax, ay, az));
		fflush(stdout);
    }

    return 0;
}

/* Put your functions here */
	int close_to (double tolerance, double point, double value){
	if(abs(value - point) >= tolerance){
	return 0;
	}
	if(abs(value - point) <= tolerance){
	return 1;
	}
	}
	
	double mag(double ax, double ay, double az){
	double Mag;
	Mag = sqrt(ax * ax + ay * ay + az * az);
	
}
