#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*

@author Jonathan Land
3/2018 

The following C program is a compilation of serial C functions that perform 
mathematical operations.  

There is s separate file containing a main routine that uses the library to 
generate a small-ish array of random values and show that the standard deviation
lowers as the array is smoothed.

I have included the text file as well. 
*/

void random_array(double array[], int size, double max)
{
    //method to change up the values each function call
    srand((unsigned int)time(NULL));
    
    //loop through the array within the range set by
    //size increasing each index by 1
    for(int i = 0; i < size; i++)
    {
        //set random values at each index upon each iteration
        array[i] = ((double) rand() / RAND_MAX) * max;
        
        //print the array values
        printf("%f ", array[i]);
    }
}

double sum(double array[], int size)
{
    //variable to hold sum
    double sum = 0;
    
    //loop through set size of array
    //and add each index to sum
    for(int i = 0; i < size; i++)
    {
        sum = array[i] + sum;
    }
    
    //print the sum
    return sum;
}

double stdev(double array[], int size)
{
    double sum = 0.0, mean;
    double standardDeviation = 0.0;
    
    for(int i = 0; i < size; ++i)
    {
        sum += array[i];
    }
    
    mean = sum/size;
    
    for(int i = 0; i < size; i++)
    {
        standardDeviation += pow(array[i] - mean, 2);
    }
    
    //get avg of squared differences
    return sqrt(standardDeviation/size);
}

 void smooth(double array[], int size, double w)
{
     for (int i = 1; i < size-1; i++)
     {
         double newValue = array[i] * w + ((array[i-1] + array[i+1])*(1-w))/2;
         array[i] = newValue;
     }
 }


