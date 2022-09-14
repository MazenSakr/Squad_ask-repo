/* Documentation
 ---------------------------------------------------
 | File Name : Shape drawer
 | Editors : Sama Adam, Mohamed Ahme,Mazen Sakr.
 | Description : a program that draws shapes based on input
 ---------------------------------------------------
*/

// INCLUDES :
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning (disable : 4996)
/********************************************/


// Declarations :
void drawCircle(float);
void drawSquare(int);
void drawRightTriangle(int);
void drawPyramid(int);
struct polygon
{
    int height;
    char type;
};
/********************************************/


// MAIN

int main(void) {

    struct polygon shape;
    shape.type = 'A';

    printf("This is a program that draws a shape according to input\nChoose a shape from(C circle, S square, T right triangle, P pyramid)\n");

    while (1)
    {
        scanf(" %c", &shape.type);
        shape.type = toupper(shape.type);
        if (shape.type == 'C' || shape.type == 'S' || shape.type == 'P' || shape.type == 'T')
        {
            break;
        }
        printf("Invalid Input, please input a valid choice\n");
    }


    switch (shape.type)
    {
    case 'C':
        printf("Enter diameter: ");
        while (1)
        {
            scanf(" %d", &shape.height);
            shape.type = toupper(shape.height);
            if (shape.height > 0)
            {
                break;
            }
            printf("Invalid Input, please input a valid number\n");
        }
        drawCircle(shape.height);
        break;

    case 'S':
        printf("Enter side length: ");
        while (1)
        {
            scanf(" %d", &shape.height);
            shape.type = toupper(shape.height);
            if (shape.height > 0)
            {
                break;
            }
            printf("Invalid Input, please input a valid number\n");
        }
        drawSquare(shape.height);
        break;

    case 'T':
        printf("Enter max height: ");
        while (1)
        {
            scanf(" %d", &shape.height);
            shape.type = toupper(shape.height);
            if (shape.height > 0)
            {
                break;
            }
            printf("Invalid Input, please input a valid number\n");
        }
        drawRightTriangle(shape.height);
        break;

    case 'P':
        printf("Enter max height: ");
        while (1)
        {
            scanf(" %d", &shape.height);
            shape.type = toupper(shape.height);
            if (shape.height > 0)
            {
                break;
            }
            printf("Invalid Input, please input a valid number\n");
        }
        drawPyramid(shape.height);
        break;

    default:
        exit(1);
        break;
    }
    return 0;
}
/************************************************************/

// Functions :
void drawCircle(float Diameter)
{
    float rad = Diameter / 2 - 0.5, tol = rad / 3;

    for (float x = -rad; x <= rad; x++)
    {
        for (float y = -rad; y <= rad; y++)
        {
            if (x * x + y * y - rad * rad <= tol)

                printf("* ");

            else
                printf("  ");
        }
        printf("\n");
    }
}
void drawPyramid(int height)
{
    int space = 2 * height - 1;
    for (int x = 1; x <= height; x++)
    {
        for (int y = 0; y < space; y++)
        {
            printf(" ");
        }
        for (int shape = 0; shape < 2 * x - 1; shape++)
        {
            printf(" *");
        }
        printf("\n");
        space -= 2;
    }
}
void drawRightTriangle(int height)
{
    for (int x = 1; x <= height; x++)
    {
        for (int y = 0; y < x; y++)
        {
            printf(" *");
        }
        printf("\n");
    }
}
void drawSquare(int height)
{
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < height; y++)
        {
            printf(" *");
        }
        printf("\n");
    }
}
/************************************************************/