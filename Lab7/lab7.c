// 185 Lab 7
#include <stdio.h>


#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);



int main(int argc, char* argv[]) {

	/* DO NOT CHANGE THIS PART OF THE CODE */

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc > 1) {
		sscanf(argv[1], "%d", &lengthofavg);
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}


	/* PUT YOUR CODE HERE */
	int t, b1, b2, b3, b4, i;
	double gx, gy, gz, avgX, avgY, avgZ, x1, y1, z1, minX, maxX, minY, maxY, minZ, maxZ;
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t,  &gx, &gy, &gz, &b1, &b2, &b3, &b4);

	for (i = 0; i < lengthofavg; i++) {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &gx, &gy, &gz, &b1, &b2, &b3, &b4);
		updatebuffer(x, lengthofavg, gx);
		updatebuffer(y, lengthofavg, gy);
		updatebuffer(z, lengthofavg, gz);
	}
	do
	{
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &gx, &gy, &gz, &b1, &b2, &b3, &b4);
		updatebuffer(x, lengthofavg, gx);
		updatebuffer(y, lengthofavg, gy);
		updatebuffer(z, lengthofavg, gz);
		avgX = avg(x, lengthofavg);
		avgY = avg(y, lengthofavg);
		avgZ = avg(z, lengthofavg);
		maxmin(x, lengthofavg, &maxX, &minX);
		maxmin(y, lengthofavg, &maxY, &minY);
		maxmin(z, lengthofavg, &maxZ, &minZ);
		printf("%d, %10lf, %10lf, %10lf, %10lf, %10lf, %10lf, %10lf, %10lf, %10lf, %10lf, %10lf, %10lf\n",t, gx, avgX, minX, maxX, gy, avgY, minY, maxY, gz, avgZ, minZ, maxZ);
		fflush(stdout);

	} while (b4 != 1);
}

double avg(double buffer[], int num_items) {
	double sum = 0;
	int i = 0;
	double Avg = 0;
	for (i = 0; i < num_items; i++) {
		sum += buffer[i];
	}
	return (sum / num_items);
}

void maxmin(double array[], int num_items, double* max, double* min) {
	*min = array[0];
	*max = array[0];
	int i = 0;

	for (i = 0; i < num_items; ++i) {
		if (*min > array[i]) {
			*min = array[i];
		}
		if (*max < array[i]) {
			*max = array[i];
		}
	}
}

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item) {
	int i;
	for (i = 0; i < length; i++)
	{
		buffer[i + 1] = buffer[i];
	}
	buffer[0] = new_item;

}

