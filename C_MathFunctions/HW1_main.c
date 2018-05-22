#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double b;
    double c;
    int arraySize = 5;
    double d;

    double arr[arraySize];
    
    printf("Elements in the array: ");
    random_array(arr, arraySize, 100);
    
    printf("\n");

    b = sum(arr, arraySize);
    
    printf("\nSum of the array: %1f\n", b);
    
    c = stdev(arr, arraySize);
    
    printf("\nStandard deviation of the array: %lf\n", c);
    
    smooth(arr, arraySize, .10);
    
    printf("\nSmooth: ");

    for (int i = 0; i < arraySize; i++)
    {
        printf("%f " , arr[i]);
    }
    
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        smooth(arr, arraySize, .10);
        d = stdev(arr, arraySize);
        printf("\nStandard deviation of array after smooth: %lf", d);
    }
    return 0;
}
