#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */

int debug() {
	return 1;
}

double mag(double x, double y, double z);
double seconds(double timeS);
int close_enough(double tollerance, double point, double value);


int main(void) {
    int t;
    double  ax, ay, az, gx, gy, gz; 
	int position = 20;
	int checkOnce = 0;
	int connection = 0;
	int printFallingOnce = 0;
	int printSafeOnce = 0;
	double fallingTime = 0.0;
	double fallingDistance = 0.0;
	
	t = 0;
	ax = 0.0;
	ay = 0.0;
	az = 0.0;	
	printf("Jackson Collalti\Collalti\n");
	printf("Ok, I'm now receiving data\n");
	printf("I'm Waiting\n");
	
    while (1) {																										
        scanf("%d,%lf,%lf,%lf,%lf,%lf,%lf", &t, &gx, &gy, &gz, &ax, &ay, &az); 
		
		if (close_enough(0.1, 0.5, mag(ax, ay, az))) {
				printf("\nI'm Falling!");
			printFallingOnce = 7;
			fallingTime++;
			if (t % 100 < 10) {
				printf("!");
			}
		}
		
		if (fallingTime == 0) {
			if (printSafeOnce == 0) {
				printf("I'm safe.");
				printSafeOnce = 7;
			}
			if (t % 100 < 10) {
				printf(".");
			}
		}
		
		if (checkPosition(ax, ay, az)) {
			printf("Blegh, I'm dead");
			connection = 0;
			break;
		}
		
		if (!(close_enough(0.1, 0.5, mag(ax, ay, az))) && (fallingTime != 0)) {
			break;
		}
		

		
		on_off(triangle);
		
		checkPosition(ax, ay, az);
		
		fflush(stdout);

    }
	fflush(stdout);
	//printf("%.2lf\n", fallingTime);
	//printf("%.2lf\n", seconds(fallingTime));
	fallingDistance = seconds(fallingTime) + (9.8 * fallingTime * fallingTime * 0.5;
	printf("Ouch! I fell %.3lf meters for %.3lf seconds", fallingDistance, seconds(fallingTime));
		}


return 0;
}

/* Put your functions here */

double mag(double x, double y, double z) {	
return x * x + y * y + z * z;
}

double seconds(double timeS) {
	timeS = timeS / 100.0;
return timeS;
}

int close_enough(double tollerance, double point, double value) {
	double upperLimit = point + tollerance;
	double lowerLimit = 0.0;
	if ((value <= upperLimit) && (value >= lowerLimit)) {
		return 1;
	}
	else {
	return 0;
	}
}
