// 185 lab6.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate 
//This function scans a line of DS4 data, and returns
//  True when the square button is pressed
//  False Otherwise
//This function is the ONLY place scanf is allowed to be used
//POST: it modifies its arguments to return values read from the input line.
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C);

// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the DS4 in radians
// if x_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the DS4 in radians
// if y_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);


// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number);

int main()
{
	double x, y, z;			// magnitude values of x, y, and z
	int b_Triangle, b_X, b_Square, b_Circle;	// variables to hold the button statuses
	double roll_rad, pitch_rad;		// value of the roll measured in radians
	int scaled_value; 	// value of the roll adjusted to fit screen display

	int t;
	int num,number,y_max,i;
	char use;
	//insert any beginning needed code here
	int RP=1;
	do
	{
		read_line(&x ,&y,&z,&t,&b_X,&b_Triangle,&b_Square,&b_Circle);	
	 	// Get line of input
		//RP=1 roll, RP=2 pitch
		if (b_Triangle==1) {	
			RP=1;
		}
		if(b_X==1) {
				RP=2;
			}
		
			if(RP==1)
			{
				roll_rad = roll(x);
				scaled_value = scaleRadsForScreen(roll_rad);
				graph_line(scaled_value);
			}
			if (RP==2) {
				pitch_rad = pitch(y);
				scaled_value = scaleRadsForScreen(pitch_rad);
				graph_line(scaled_value);
			}

		fflush(stdout);
	} while (b_Square==0); 
	return 0;
}
int read_line(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* b_Square, int* Button_RIGHT) {
	scanf("%d,%lf,%lf,%lf,%d,%d,%d,%d,%d,%d",time,a_x, a_y,a_z, Button_UP,Button_DOWN,b_Square,Button_RIGHT,&b5,&j);
	if(*b_Square==1) {
		return 1;
	}
	else {
		return 0;
	}
}
double roll(double x_mag) {
	if(x_mag<-1) {
		x_mag=-1;
	}
	if (x_mag>1) {
		x_mag=1;
	}

	return asin(x_mag);
	
}
double pitch(double y_mag) {
	if(y_mag<-1) {
		y_mag=-1;
	}
	if(y_mag>1) {
		y_mag=1;
	}
	
	return asin(y_mag);
}
int scaleRadsForScreen(double rad) 
{
	return rad*(39/(PI/2));
}

void print_chars(int num, char use) {
	int i;
	for (i=0; i<num; i++) {
		printf("%c", use);
	}
}

void graph_line(int number) {

int i = 0;

if (number < 0){

i = number + 40;

print_chars( i,  ' ');

print_chars( -number, 'r');

}

else if ( number > 0) {

print_chars( 40,  ' ');

print_chars( number, 'l');


}

else{

print_chars( 40,  ' ');

print_chars ( 1, '0');

}

print_chars(1, '\n');

}