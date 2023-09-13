/*-----------------------------------------------------------------------------
-					          CPRE 185 Lab 02
-	Name:Jackson Collalti
- 	Section:5
-	NetID:collalti
-	Date:9/27/22
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
int seconds(int t);
/*-----------------------------------------------------------------------------
-							 Implementation
-----------------------------------------------------------------------------*/
int main(void)
{
	int t, b1, b2, b3, b4;
	double St=0.0; 
	int timer = 0;
    double ax, ay, az, gx, gy, gz;
	double toleranceNM=1.0;
	double dist=0.0;
;
   printf("Collalti Jackson\nCollalti\n");
   printf("Ok, I'm now receiving data.\n");
	
   printf("I'm waiting.");
   scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);

	while(close_to(0.2, 1, mag(ax, ay, az))==1){
	{
	
	scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
		if(t>=timer+1000){
		printf(".");
		fflush(stdout);
		timer=t;
		}
	}
	}
	
	St = t;
	printf("\n\n   Help me! I'm falling");
	fflush(stdout);

	
	while(mag(ax, ay, az)<=4){
		scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
	if(t>=timer+200){
	printf("!");
	fflush(stdout);
	timer=t;
	}
	}

	St=(t-St)/1000.0;
	dist = 0.5 * 9.8 * (St*St);
	
		


		printf("\n\n       Ouch! I fell %.3lf meters in %.3lf seconds", dist,St);
return 0;
}

int close_to(double tolerance, double point, double value) {
	
	 if(point-tolerance<=value && value<=point+tolerance){
		return 1;
		}
	else {
		return 0;
	}
}

	
double mag(double ax, double ay, double az){
	double Mag;
	Mag = sqrt(ax * ax + ay * ay + az * az);	
}