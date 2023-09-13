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
	double St; 
	int timer = 0;
    double ax, ay, az, gx, gy, gz;
	double toleranceNM=1.0;
	double dist=0.0;
    double diffT = 0.0;
    double tempT=0.0;
    double velo;
    double position=0.0;
    double percentDif=0.0;
   printf("Collalti Jackson\nCollalti\n");
   printf("Ok, I'm now receiving data.\n");
	
   printf("I'm waiting.");
   scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );

	while(mag(ax,ay,az)<=.4){
	{
	
	scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
		if(t>=timer+1000){
		printf(".");
		fflush(stdout);
		timer=t;
		}
	}
	}
	St = 0.0;
	St = t;
	printf("\n\n   Help me! I'm falling");
	fflush(stdout);
	tempT = St;
    velo = 0.0;
	
	while(mag(ax,ay,az)<=.9){
		scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf", &t, &ax, &ay, &az, &gx, &gy, &gz);
	if(t>=timer+200){
	printf("!");
	fflush(stdout);
	timer=t;
		}
        diffT = (t - tempT) / 1000.0;
        velo = velo + 9.8 * (1 - mag(ax, ay, az)) * (diffT);
        position = position + velo * (diffT);
        tempT = t;
        fflush(stdout);
	}

	St=(t-St)/1000.0;
	dist = 0.5 * 9.8 * (St*St);
	
		
	    percentDif = (1 - position / dist) * 100;

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


