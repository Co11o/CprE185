/*  Jackson Collalti
collalti@iastate.edu
CPRE 185 Section 5
Programming Practice 2
  <Reflection 1 What were you trying to learn or achieve?>
                On exam 1 the last question said that we couldn't use arrays. My goal is to get a working version of the final problem using arrays.

  <Reflection 2 Were you successful? Why or Why not?>

       I was successful, sort of, I completed the code without relizing that the array had to go throuhg a function. During this process I constantly  ran into errors of Invalid operands to binary expression ('double' and 'double *'). After some Google searches I found that this is caused by in my case by dividing a pointer with a double. I tried to get my arrays to not be pointers but would get errors. As seen in the code I created a lot of variables most of them probably weren't needed.
  <Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>

        The main thing I'd change would be the format of the output. The current output does each set of number and prints.
        I would change that such that the only thing printed would be the final statement. This would be a shorter output
        The reason I had the print every pair was for checking to see where something went wrong.

  <Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it   was significant.>

        Although I don't totally understand I learned about about the issues of using pointers with other data types. This because an issue when trying to add a double of previous sum with pointers to get a new sum. Even if the code didn't go exactly as I wanted it, I feel the most important thing I learn was using this website. It's a lot easier than using notepad or visual studio and compiling and running on Cygwin. I believe this website is good for short coding but I think it would be harder to use with multi function programs.
*/
#include <stdio.h>
double Sum(double* val[], double* val2[], int numRows) {
    int i;
    double sum = 0.0;
    for (i = 0; i < numRows; i++) {
        sum = val[i][i + 1];
    }
    return sum;
}
int main(void) {
    int numRows = 0;
    int i;
    double left = 0.0;
    double right = 0.0;
    double mean = 0.0;
    int matches = 0;
    int ign = 0;
    double Nsum = 0.0;
    double NSum = 0.0;
    double Avg = 0.0;
    int tempI = 0;
    scanf(" %d", &numRows);
    double userVal[numRows];
    for (i = 0; i < numRows; i++) {
        scanf(" %lf %lf", &left, &right);
        userVal[i] = left;
        userVal[(i + 1)] = right;
        if (left == 0 && right == 0) {
            ign = ign + 1;
        }
        if (left == right && left != 0) {
            matches = matches + 1;
        }
        if (i == 0) {
            tempI = 2;
        }
        if (i == 1) {
            tempI = 4;
        }
        if (i == 2) {
            tempI = 6;
        }

        Nsum = Nsum + left + right;
        NSum = Sum(&userVal[i], &userVal[i + 1], numRows);
        Avg = Nsum / tempI;
        printf("%.3lf, %.3lf ", left, right);
        printf("\n %d matches, %d ignored\n", matches, ign);
        printf("%.3lf Average ", Avg);
    }

    return 0;
}
