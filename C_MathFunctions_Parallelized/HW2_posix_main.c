#include "headerHW2.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

/*
    @author Jonathan Land
    2/6/18
    This program was written for a Parallel Algorithms/HPC class I took.
    Basically, this program parallelizes the code in the file C_MathFunctions.

    The program does the following:
    1. Parallelizes a randomized array
    2. Parallelizes a sum function on the randomized array
    3. Parallelizes a function to find the standard deviation of the array
    4. Show how the array is smoothed which requires determining
	    (a) the standard deviation to get the mean
	    (b) then subtracting the mean and squaring the result (squared difference)
            (c) and then getting the avg of those squared differences
*/

double origStdevArr(double array[], int size);

int main(void)
{
    //change in other c program
    int NUM_THREADS = 1;

    double b;
    double c;
    
    //test arraySize for class = 100000000
    //may need to change in random_array also
    int arraySize = 100000000;
    //malloc(sizeof(int)
    double* arr = malloc(arraySize*sizeof(double))
    
    float smoothA = .10;
    //double arr[arraySize];
    
    printf("          Homework 2 Synopsis: \n");
    printf("=========================================== \n");
    printf("\n");
    printf("Total number of threads: %d\n", NUM_THREADS);
    printf("Size of array: %d\n", arraySize);
    printf("Weight of smooth: %f\n", smoothA);
    printf("\n");
    printf("=========================================== \n");
    
    //timing for random array
    printf("\n");
    printf("Creating the Array \n");
    printf("\n");
    
    struct timeval  tv1, tv2;
    gettimeofday(&tv1, NULL);
    random_array(arr, arraySize, 10);
    gettimeofday(&tv2, NULL);
    
    printf("\n");
    printf(">>Total time to create array: %f seconds\n", (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));
    printf("\n");
    printf("=========================================== \n");
    
    //use to check range of values
    /*
     for (int i = 0; i < arraySize; i++)
     {
         printf("%f " , arr[i]);
     }
     */
    
    printf("\n");
    
    //timing of sum array
    printf("Summing the Array \n");
    printf("\n");
    
    struct timeval tv3, tv4;
    gettimeofday(&tv3, NULL);
    b = sum(arr, arraySize);
    gettimeofday(&tv4, NULL);
    
    printf("\n");
    printf(">>Sum of the array: %1f\n", b);
    printf (">>Total time to calcuate the sum of the array: %f seconds\n",
            (double) (tv4.tv_usec - tv3.tv_usec) / 1000000 +
            (double) (tv4.tv_sec - tv3.tv_sec));
    printf("\n");
    printf("=========================================== \n");
    
    //standard deviation (parallelized)
    printf("\n");
    printf("Standard Deviation of the Array(parallelized) \n");
    printf("\n");
    
    struct timeval  tv5, tv6;
    gettimeofday(&tv5, NULL);
    c = stdev(arr, arraySize);
    gettimeofday(&tv6, NULL);
    printf("\n>>Standard deviation of parallelized array: %lf\n", c);
    printf (">>Total time to calcuate parallelized standard deviation: %f seconds\n",
            (double) (tv6.tv_usec - tv5.tv_usec) / 1000000 +
            (double) (tv6.tv_sec - tv5.tv_sec));
    
    //standard deviation (original)
    double c1;
    struct timeval  tv7, tv8;
    gettimeofday(&tv7, NULL);
    c1 = origStdevArr(arr, arraySize);
    gettimeofday(&tv8, NULL);
    printf("\n>>Standard deviation of original/serial array: %lf\n", c);
    printf("\n>>Result of original/serial standard deviation (i.e., HW1): %lf\n", c1);
    printf (">>Total time to calculate original/serial standard deviation: %f seconds\n",
            (double) (tv8.tv_usec - tv7.tv_usec) / 1000000 +
            (double) (tv8.tv_sec - tv7.tv_sec));
    printf("\n");
    printf("=========================================== \n");
    
    //smothing array
    printf("\n");
    printf("Smoothing the Array \n");
    
    //use to check els being smoothed
    //printf("Arrays before smooth: \n" );
    /*
     for (int i = 0; i < arraySize; i++)
     {
     printf("%f ", arr[i]);
     }
     */
    printf("\n");
    
    struct timeval  tv9, tv10;
    gettimeofday(&tv9, NULL);
    smooth(arr, arraySize, smoothA);
    gettimeofday(&tv10, NULL);
    /*
     for (int i = 0; i < arraySize; i++)
     {
        printf("%f ", arr[i]);
     }
     */
    
    printf ("Total time to calcuate parallelized array after smooth: %f seconds\n",
            (double) (tv10.tv_usec - tv9.tv_usec) / 1000000 +
            (double) (tv10.tv_sec - tv9.tv_sec));

    //if neeeded code///
    /*
     printf("Smooth: \n");
     
     for (int i = 0; i < arraySize; i++)
     {
         printf("%f " , arr[i]);
     }
     
     printf("\n");
    //timing for smooth
    //gettimeofday(&time5, NULL);
     
     for (int i = 0; i < 10; i++)
     {
     //smooth(arr, arraySize, smooth);
         d = stdev(arr, arraySize);
         printf("\nStandard deviation of array after smooth: %lf", d);
     }
    //gettimeofday(&time5, NULL);
    */
    free(arr);
    return 0;
}
