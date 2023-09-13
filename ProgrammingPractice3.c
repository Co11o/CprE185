
/*         Jackson Collalti

        collalti@iastate.edu (Should be your isu email)

        CPRE 185 Section 5  (change to your class and section)

Programming Practice 3

         <Reflection 1 What were you trying to learn or achieve?>

                I had the goal of creating a palindrome detecting program. This was made with the intention of reversing a
				string. The program also uses swapping elements in order to reverse. 

        <Reflection 2 Were you successful? Why or Why not?>

				I was successful I not only learned how to reverse a string I managed to get it to work. If I were to redo the
				program I would change some things but I still got the program to work at a basic level.

<Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>

        I would change the program to not be case sensative because currently the input has to be mirrored case. 
		for example Pup would be reversed to puP and strcmp views the strings as different.

<Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>

        The hardest part was the for loop. I had issues with getting the last element set for the reversed because the 
		stringlength would change depending on the word.


*/


#include <stdio.h>
#include <string.h>
 
void main(){
//Get word input
 char str[10];
    printf("Enter Word (Less than 10 characters): ");
    scanf("%s", str);
 //If to big
    int strSize = strlen(str);
    if (strSize > 10) {
        printf("\nError");
        return 0;
    }
//Reverse
    char strReversed[10];
    for (int i = strSize - 1; i >= 0; --i) {
        strReversed[strSize - 1 - i] = str[i];
    }
//Output of input and reversed input
	printf("Initial Word: %s\n",str);
	printf("Reversed: %s",strReversed);
//if yes
    if (strcmp(str, strReversed) == 0) {
        printf("\n%s is a palindrome", str);
    }
//if No
    else {
        printf("\n%s is not a palindrome", str);
    }
    return 0;
}