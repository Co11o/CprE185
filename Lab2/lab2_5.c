/*-----------------------------------------------------------------------------
-           CPRE 185 Lab 02
- Name:
-  Section:
- NetID:
- Date:
-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
-                             Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
/*-----------------------------------------------------------------------------
-                             Defines
-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
-                             Prototypes
-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
-  Implementation
-----------------------------------------------------------------------------*/
int main()
{
    double a, b, c;
    double filler;
	printf("Type 'a' value: \n");
	scanf("%lf",&a);
	printf("Type 'b' value: \n");
	scanf("%lf",&b);
	c = ( a * a ) + ( b * b );
    /*  This next line will calculate the square root of whatever value is
        inside the parenthesis and assigns it to the variable filler. */
    filler = sqrt(c);
	printf("c = %lf",filler);
    return 0;
}
