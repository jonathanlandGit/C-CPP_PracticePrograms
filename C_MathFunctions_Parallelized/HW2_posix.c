#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>

/*
 * Jonathan Land
 * 2/6/18
 */

int NUM_THREADS = 1;

struct args_struct
{
    double* arr;
    int position;
    int size;
    double max;
    double sum;
    double standardDeviation;
    double mean;
    double w;
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
    //have to break up population of this array depending on threads
    pthread_t thread_ids [ NUM_THREADS ];
    
    //reserve memory for structure/object
    //each thread gets object unique to it
    struct args_struct args [ NUM_THREADS ];
    
    //starts threads
    //first thread would be 0 and thread 2 would start at 50 if we were doing 100 array
    for (int t = 0; t < NUM_THREADS; t++)
    {
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
        //pointer to the method, pointer to arguments passing
        if (pthread_create (&thread_ids [t], NULL , &randomArrayThread, (void*)&args[t]) != 0)
        {
            printf("Thread fail: ");
        }
    }
    
    for (int t = 0; t < NUM_THREADS; t++)
    {
        //this is where we're waiting for threads to finish and tries
        //to join to all the threads
        printf("Attaching to thread %d\n", t);
        pthread_join(thread_ids[t], NULL);
    }
}

void* sumArr(void* args)
{
    //casting args into arguments
    //so that we will have arguments before we fill up to send
    struct args_struct* arguments = args;
    
    //give memory space for this
    double* p = arguments->arr + arguments->position;
    
    double sum = 0.0;
    
    for(int i = arguments->position; i < arguments->position + arguments->size; i++)
    {
        sum += (double)*p;
        p++;
        //printf("Sum: %f\n", sum);
    }
    //assignment found sum to argument
    arguments->sum = sum;
    return NULL;
}

double sum(double array[], int size)
{
    //variable to hold sum
    double sum = 0;
    
    //want to break up population of this array depending on threads
    //own thread ID
    pthread_t thread_ids [ NUM_THREADS ];
    
    //reserve memory for structure/object
    //each thread gets object unique to it
    struct args_struct args [ NUM_THREADS ];
    
    //starts threads
    for (int t = 0; t < NUM_THREADS; t++)
    {
        //size - size of this piece of the array
        args[t].size = size / NUM_THREADS;
        
        //actual pointer to the array[]
        args[t].arr = array;
        
        //position - start postion of the array for this thread
        args[t].position = t * args[t].size;
        
        printf("Arguments: %d %d\n",   args[t].size, args[t].position);
        
        //pass pointer to thread ID, NULL - thread attibutes (if necessary),
        //pointer to the method, pointer to arguments we're passing
        if (pthread_create (&thread_ids [t], NULL , &sumArr, (void*)&args[t]) != 0)
        {
            printf("Thread fail: ");
        }
    }
    
    for (int t = 0; t < NUM_THREADS; t++)
    {
        //we're waiting for threads to finish
        printf("Attaching to thread %d\n", t);
        pthread_join(thread_ids[t], NULL);
        sum += args[t].sum;
    }
    return sum;
}

void* stdDevArr(void* args)
{
    struct args_struct* arguments = args;
    
    double* p = arguments->arr + arguments->position;
    double standardDeviation = 0.0;
    
    for(int i = arguments->position; i < arguments->position + arguments->size; i++)
    {
        standardDeviation += pow(*p - arguments->mean, 2);
        //printf("Thread %d Standard Dev: %f\n" , (int)pthread_self(),standardDeviation);
        p++;
        //printf("Thread %d - position %d\n", (int)pthread_self(), i);
    }
    //assignment found sum to argument
    arguments->standardDeviation = standardDeviation;
    return NULL;
}

double stdev(double array[], int size)
{
    double sum = 0.0;
    double standardDeviation = 0.0;
    
    pthread_t thread_ids [ NUM_THREADS ];
    
    for(int i = 0; i < size; i++)
    {
        sum += array[i];
       // printf("Val = %f  Sum is: %f\n", array[i], sum);
    }
    
    //reserve memory for structure/object
    //each thread gets object unique to it
    struct args_struct args [ NUM_THREADS ];
    
    for (int t = 0; t < NUM_THREADS; t++)
    {
        //size - size of this piece of the array
        args[t].size = size / NUM_THREADS;
        
        //actual pointer to the array[]
        args[t].arr = array;
        
        //position - start postion of the array for this thread
        args[t].position = t * args[t].size;
        
        args[t].mean = sum /size;
        
        printf("Arguments: %d %f %d %f \n",   args[t].size, args[t].max, args[t].position, args[t].mean);
        
        //pass pointer to thread ID, NULL - thread attibutes (if necessary),
        //pointer to the method, pointer to arguments we're passing
        if (pthread_create (&thread_ids [t], NULL , &stdDevArr, (void*)&args[t]) != 0)
        {
            printf("Thread fail: ");
        }
    }
    
    for (int t = 0; t < NUM_THREADS; t++)
    {
        //waiting for threads to finish
        printf("Attaching to thread %d\n", t);
        pthread_join(thread_ids[t], NULL);
        standardDeviation += args[t].standardDeviation;
    }
    return sqrt(standardDeviation/size);
}

//included to show the time difference (note: included as prototype in this program, not in .h)
double origStdevArr(double array[], int size)
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

//original code in prev HW that was used as guide

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

void* smoothArr(void* args) //smoothArr
{
    //casting args into arguments and casting it
    //can have arguments before we fill up to send
    struct args_struct* arguments = args;
        
    double* p = arguments->arr + arguments->position+1;
        
    for(int i = arguments->position + 1; i < (arguments->position + arguments->size)-1; i++)
    {
        //decrementing the pointer
        double newValue = *p * arguments->w + ((*(p-1) + *(p+1))*(1-arguments->w))/2;
        
        *p = newValue;
        //now increase
        p++;
        //printf("Thread %d - position %d\n", (int)pthread_self(), i);
    }
    return NULL;
}

void smooth(double array[], int size, double w)
{
    pthread_t thread_ids [ NUM_THREADS ];

    struct args_struct args [ NUM_THREADS ];
    
    for (int t = 0; t < NUM_THREADS; t++)
    {
        args[t].size = size / NUM_THREADS;
        args[t].arr = array;
        args[t].w = w;
        args[t].position = t * args[t].size;

        pthread_create(&thread_ids[t],NULL,smoothArr,&args[t]);
    }
    
    for (int t = 0; t < NUM_THREADS; t++)
    {
        pthread_join(thread_ids[t],NULL);
    }
}
