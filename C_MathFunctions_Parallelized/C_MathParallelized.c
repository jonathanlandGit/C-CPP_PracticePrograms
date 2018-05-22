#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

/*
@author Jonathan Land

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

int NUM_THREADS = 2;

struct args_struct
{
    double* arr;
    int position;
    int size;
    double max;
    int sum;
    double standardDeviation;
    double mean;
};

void* randomArrayThread(void* args)
{
    //casting args into arguments and casting it
    //can have arguments before we fill up to send
    struct args_struct* arguments = args;
    
    //method to change up the values each function call
    //srand((unsigned int)time(NULL));
    
    //give one memory space
    double* p = arguments->arr + arguments->position;
    
    for(int i = arguments->position; i < arguments->position + arguments->size; i++)
    {
        *p = ((double) rand() / RAND_MAX) *  arguments->max;;
        p++;
        //printf("Thread %d - position %d\n", (int)pthread_self(), i);
    }
    return NULL;
}

void random_array(double array[], int size, double max)
{
    //we want to break up population of this array depending on threads
    //own thread ID
    pthread_t thread_ids [ NUM_THREADS ];
    
    //reserve memory for structure/object
    //each thread gets object unique to it
    struct args_struct args [ NUM_THREADS ];

    //starts threads
    //first thread would be 0 and thread 2 would start at 50
    for (int t = 0; t < NUM_THREADS; t++)
    {
        //take existing and parse according to #of threads there are
        
        //size - size of this piece of the array
        args[t].size = size / NUM_THREADS;
        //max - max value passed in of each el
        args[t].max = max;
        //actual pointer to the array[]
        args[t].arr = array;
        //position - start postion of the array for this thread
        args[t].position = t * args[t].size;

        printf("Arguments: %d %f %d\n",   args[t].size, args[t].max, args[t].position);
        
        //pass pointer to thread ID, NULL - thread attibutes (if necessary),
        //pointer to the method, pointer to arguments we're passing
        if (pthread_create (&thread_ids [t], NULL , &randomArrayThread, (void*)&args[t]) != 0)
        {
            printf("Thread fail: ");
        }
    }
    
    for (int t = 0; t < NUM_THREADS; t++)
    {
        //we're waiting for threads to finish and tries
        //to join to all the threads
        printf("Attaching to thread %d", t);
        pthread_join(thread_ids[t], NULL);
    }
}

void* sumArr(void* args)
{
    //casting args into arguments and casting it
    //can have arguments before we fill up to send
    struct args_struct* arguments = args;
    
    //method to change up the values each function call
    //srand((unsigned int)time(NULL));
    
    //give one memory space
    double* p = arguments->arr + arguments->position;
    int sum;
    
    for(int i = arguments->position; i < arguments->position + arguments->size; i++)
    {
        sum = *p + sum;
        p++;
        //printf("Thread %d - position %d\n", (int)pthread_self(), i);
    }
    //assignment found sum to argument
    arguments->sum = sum;
    return NULL;
}

double sum(double array[], int size)
{
    //variable to hold sum
    double sum = 0;
    
    //we want to break up population of this array depending on threads
    //own thread ID
    pthread_t thread_ids [ NUM_THREADS ];
    
    //reserve memory for structure/object
    //each thread gets object unique to it
    struct args_struct args [ NUM_THREADS ];
    
    //starts threads
    //first thread would be 0 and thread 2 would start at 50
    for (int t = 0; t < NUM_THREADS; t++)
    {
        //take existing and parse according to #of threads there are
        
        //size - size of this piece of the array
        args[t].size = size / NUM_THREADS;
        
        //actual pointer to the array[]
        args[t].arr = array;
        
        //position - start postion of the array for this thread
        args[t].position = t * args[t].size;
        
        printf("Arguments: %d %f %d\n",   args[t].size, args[t].max, args[t].position);
        
        //pass pointer to thread ID, NULL - thread attibutes (if necessary),
        //pointer to the method, pointer to arguments we're passing
        if (pthread_create (&thread_ids [t], NULL , &sumArr, (void*)&args[t]) != 0)
        {
            printf("Thread fail: ");
        }
    }
    
    for (int t = 0; t < NUM_THREADS; t++)
    {
        //we're waiting for threads to finish and tries
        //to join to all the threads
        printf("Attaching to thread %d", t);
        pthread_join(thread_ids[t], NULL);
        sum += args[t].sum;
    }
    return sum;
}

void* stdDevArr(void* args)
{
    //casting args into arguments and casting it
    //can have arguments before we fill up to send
    struct args_struct* arguments = args;
    
    //method to change up the values each function call
    //srand((unsigned int)time(NULL));
    
    //give one memory space
    double* p = arguments->arr + arguments->position;
    double standardDeviation;
    double sum, mean;
    
    for(int i = arguments->position; i < arguments->position + arguments->size; i++)
    {
        sum = *p + sum;
        p++;
        
        mean = *p + sum/i;
        p++;

        standardDeviation = *p + pow(array[i] - mean, 2);
        p++;
        //printf("Thread %d - position %d\n", (int)pthread_self(), i);
    }
    //assignment found sum to argument
    arguments->standardDeviation = standardDeviation;
    return NULL;
}

double stdev(double array[], int size)
{
    //variable to hold sum
    double sum = 0.0, mean;
    double standardDeviation = 0.0;
    
    //we want to break up population of this array depending on threads
    //own thread ID
    pthread_t thread_ids [ NUM_THREADS ];
    
    //reserve memory for structure/object
    //each thread gets object unique to it
    struct args_struct args [ NUM_THREADS ];
    
    //starts threads
    //first thread would be 0 and thread 2 would start at 50
    for (int t = 0; t < NUM_THREADS; t++)
    {
        //take existing and parse according to #of threads there are
        
        //size - size of this piece of the array
        args[t].size = size / NUM_THREADS;
        
        //actual pointer to the array[]
        args[t].arr = array;
        
        //position - start postion of the array for this thread
        args[t].position = t * args[t].size;
        
        printf("Arguments: %d %f %d\n",   args[t].size, args[t].max, args[t].position);
        
        //pass pointer to thread ID, NULL - thread attibutes (if necessary),
        //pointer to the method, pointer to arguments we're passing
        if (pthread_create (&thread_ids [t], NULL , &stdDevArr, (void*)&args[t]) != 0)
        {
            printf("Thread fail: ");
        }
    }
    
    for (int t = 0; t < NUM_THREADS; t++)
    {
        //we're waiting for threads to finish and tries
        //to join to all the threads
        printf("Attaching to thread %d", t);
        pthread_join(thread_ids[t], NULL);
        sum += args[t].sum;
        mean = args[t].mean;
        standardDeviation = args[t].standardDeviation;
    }
    return sqrt(standardDeviation/size);
}

/*
double stdev(double array[], int size)
{
    //for standard deviation we have to get the (1) mean; (2) then
    //for each number subtract the mean and square the result (squared difference);
    //(3) get avg of those squared differences
    double sum = 0.0, mean;
    double standardDeviation = 0.0;

    //include both inside thread
    for(int i = 0; i < size; ++i)
    {
        sum += array[i];
    }
    
    //find the mean
    mean = sum/size;
    
    //substract the mean square the result
    for(int i = 0; i < size; i++)
    {
        standardDeviation += pow(array[i] - mean, 2);
    }
    
    //get avg of squared differences
    //inclue double inside
    return sqrt(standardDeviation/size);
}
 */

 void smooth(double array[], int size, double w)
 {
     for (int i = 1; i < size-1; i++)
     {
         double newValue = array[i] * w + ((array[i-1] + array[i+1])*(1-w))/2;
         array[i] = newValue;
     }
 }


