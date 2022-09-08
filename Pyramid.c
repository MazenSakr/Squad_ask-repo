#include <stdio.h>

#define arr_size 9
void main (void)
{
    char arr [arr_size]= {' '} ;
    unsigned char height ,  shape ,  center = 4 ,right=0 , left=0 ; 
    printf("Enter the height of the pyramid : ") ;scanf("%d",&height) ;
 if ((height <=5) && (height >=2))
 {
    printf("Enter the shape to write the pyramid :") ;
    fflush(stdin) ;
    scanf("%c",&shape) ;
     while (height > 0) // printing line by line depending on height entered
        {   
    
        arr[center+right] = shape ; 
        arr [center-left] =shape ;
        right++ ;
        left++ ;
        for (int counter = 0 ;counter<arr_size ;counter++) // print the array
        {
            printf("%c",arr[counter]) ;
        }
        printf("\n") ;
        height -- ;
        }
}
else 
{
 printf("Invalid Height !!!\n") ;
}

}