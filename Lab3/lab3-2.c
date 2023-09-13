/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */
 int numButtons(int bx,int bc,int bs,int bt) {
	int pressedButtons;
	pressedButtons = bx + bc + bs + bt;
}

int main(void) {
	int bx;//button x
    int bc;//buttom circle
    int bs;//button square
    int bt;//button triangle
	
	while(1)
	{
   scanf("%d, %d, %d, %d",&bt,&bc,&bx,&bs);
   {
   printf("The number of buttons being pressed is %d\n",numButtons(bx,bc,bs,bt));
    fflush(stdout);
    }
	}
return 0;
}

/* Put your functions here */