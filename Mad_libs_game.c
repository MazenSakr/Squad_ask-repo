#include <stdio.h>


void main (void)
{   char colour [20] ;
    char pluralnoun [20] ;
    char celebrity [30] ;
    printf("enter colour :") ;
    scanf("%s",colour) ;
    printf("enter Plural noun :") ;
    scanf("%s",pluralnoun) ;
    printf("enter celebrity name :") ;
    fflush(stdin) ;
    scanf("%[^\n]s",celebrity) ;

    printf("my hair is %s\n",colour) ;

    printf("i will eat all the %s \n",pluralnoun) ;

    printf("i will invite %s for lunch \n",celebrity) ;


}
