#include<stdio.h>


void main (void)
{ double Num1,Num2,Num3 ;
 printf("enter 3 numbers as Num1 Num2 Num3 :") ;
 scanf("%lf %lf %lf",&Num1,&Num2,&Num3) ;
 double sum = Num1+Num2+Num3 ;
 double Average = sum/3.0 ;
    printf("the sum of three numbers = %.2lf \n",sum) ;
    printf("the average of three numbers = %.2lf \n",Average) ;



}
