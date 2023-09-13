/*  Jackson Collalti
    collalti@iastate.edu
    CprE185 Section 5
    Programming Practice 1
    <Relfection 1 What were you trying to learn or achieve?>
    I was trying to get more comfortable with char's snf 
    <Relfection 2 Were you successful? Why or Why not?>

    <Relfection 3 Would you do anything differently if starting this program over?>

    <Relfection 4 Think about the most important thing you learned when writing this piece of code.
    What was it and expalin why it was significant.>
*/
#include <stdio.h>
#include <math.h>

double numA, numB;
char Oper;
double Out;
double mult(double numA, double numB);
double div(double numA, double numB);
double add(double numA, double numB);
double sub(double numA, double numB);

int main(){
printf("Print number 1 followed by a space\n");
printf("then type the first letter of the operation you want to complete followed by a space\n");
printf("Finally type your last number\n");
while(1){
scanf("%lf %c %lf", &numA, &Oper, &numB);
if(Oper == 'd' || Oper == 'D' || Oper == '/'){

printf("%lf %c %lf = %lf", numA, Oper, numB, out);
}
if(Oper == 'm' || Oper == 'M' || Oper == '*'){

printf("%lf %c %lf = %lf", numA, Oper, numB, out);
}
if(Oper == 'a' || Oper == 'A' || Oper == '+'){

printf("%lf %c %lf = %lf", numA, Oper, numB, out);
}
if(Oper == 'S' || Oper == 's' || Oper == '-'){
    
printf("%lf %c %lf = %lf", numA, Oper, numB, out);
}
}
}

double mult(double numA, double numB){
Out = numA * numB;
}

double div(double numA, double numB){
Out = numA / numB;
}

double add(double numA, double numB){
Out = numA + numB;
}

double sub(double numA, double numB){
Out = numA - numB;
}


