
#include <stdio.h>

double add(double Num1, double Num2);
double subtract(double Num1,double Num2);
double divide(double Num1, double Num2);
double multiply(double Num1, double Num2);

void main(void)
{   double result ;
	double Num1 , Num2;
	char Operation ;
	printf("Enter First Number: "); scanf("%lf", &Num1);
	printf("Enter Second Number: ");scanf("%lf", &Num2);
	printf("enter operation ( + , - , * , / ) :");
	fflush(stdin) ;
	scanf("%c", &Operation);
	switch (Operation)
	{   case '+' :
            printf("the result is :%.2f ",add(Num1,Num2));
            break;
        case '-' :
            printf("the result is :%.2f ",subtract(Num1,Num2));
            break;
        case '*' :
            printf("the result is :%.2f ",multiply(Num1,Num2));
            break;
        case '/' :
            if (Num2 == 0)
                printf("Invalid operation\n") ;
             else
             {
                printf("the result is :%.2f ",divide(Num1,Num2));
             }
            break;

        default :
            {
            printf("invalid Operation\n") ;
            }
	}


}

double add(double Num1, double Num2)
{
	return (Num1+Num2) ;
}

double subtract(double Num1, double Num2)
{
	return (Num1 - Num2);
}

double divide(double Num1, double Num2)
{
	return (Num1 / Num2);
}
double multiply(double Num1, double Num2)
{
	return (Num1 * Num2) ;
}
