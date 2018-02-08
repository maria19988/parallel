#include <stdio.h>
#include <math.h>
#include <pthread.h>
#define STEPS 10000000
#define NUM_THREADS 4

double PI = 0.0; 
pthread_mutex_t lock;
 
void *calculatePI(void *ignored)
{
	int myNum = *((int *)ignored);
	double h = 2.0 / STEPS;
	double partial_sum = 0.0, x;&nbsp;
 
  
    for (int i = myNum; i< STEPS; i += NUM_THREADS)
	{
         x = -1 + (i + 0.5f) * h;
         partial_sum += sqrt(1.0 - x*x) * h;
    }
	pthread_mutex_lock(&lock);
	PI += partial_sum; 
	pthread_mutex_unlock(&lock);
	return 0;
}
 
int main(int argc, char **argv) {
 
	pthread_t threads[NUM_THREADS];
	int array[NUM_THREADS], i;
	pthread_mutex_init(&lock, NULL);
	for ( i = 0; i <NUM_THREADS; ++i ) 
	{
		array[i] = i;
		pthread_create(&threads[i], NULL, calculatePI, (void)&array[i]);            
	}
    for ( i = 0; i < NUM_THREADS; ++i ) 
	{
		pthread_join(threads[i], NULL);
	}
	PI *= 2.0;
	printf("Computed value of Pi: %12.9f\n", PI );
	pthread_mutex_destroy(&lock);
	return 0;
}