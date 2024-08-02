#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 10000

void generateRandomSortedArray(int [], int, int *, int *);
void printArray(int [], int);
int binarySearch(int [], int, int);
int linearSearch(int [], int, int);



int main(void)
{
	int array [ARR_SIZE], min, max, target, i, position;
	double elapsedTimeBinary = 0, elapsedTimeLinear = 0, startTime;
	clock_t t;
	generateRandomSortedArray(array, ARR_SIZE, &min, & max);

	// search random 100000 target numbers
	for(i = 0; i < 100000; i++)
	{
		// pick a random number between max and min
        target=min+rand()%(max-min);
		// start the timer
        startTime=(double)clock();
		// call binary search do not control if we find the target item.
        binarySearch(array,ARR_SIZE,target);
		// calculate the elapsed time
        elapsedTimeBinary+=(double)clock()-startTime;
		// start the timer for linear search
        startTime=(double)clock();
		// call linear search do not control if we find the target item.
        linearSearch(array,ARR_SIZE,target);
		// calculate the elapsed time
        elapsedTimeLinear+=(double)clock()-startTime;
	}
	// report the elapsed times for both. use CLOCKS_PER_SEC to get seconds.//1 saniyede kac sayi okuyabiliri soyler
        printf("%.10lf second for binary\n",(double)elapsedTimeBinary/CLOCKS_PER_SEC);
        printf("%.10lf second for linear\n",(double)elapsedTimeLinear/CLOCKS_PER_SEC);
	return 0;
}

void generateRandomSortedArray(int array[], int size, int *min, int *max)
{
	// srand
	srand(time(NULL));
	array[0] = 0;
	int i = 0, randomNumber;
	while(i < size)
	{
		int lowerBound = i * 2;
		int upperBound = 1 + lowerBound * 2;
		// as long as you generate a randomNumber which is less than the number at i-th index
		while( array[i] > (randomNumber = lowerBound + rand() % (upperBound - lowerBound) ) )
			;//keeps me in the loop by doing nothing
		// I got a random number which is greater than i-th number
		array[i+1] = randomNumber;
		// now, "i" can be incremented
		i++;
	}
	*min = array[0];
	*max = array[size-1];
}


void printArray(int array[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");
}


int binarySearch(int array[], int size, int target)
{
int low=0,high=size-1;
int mid;
while(low<=high)
{
   mid=(low+high)/2;
   if(array[mid]==target)
    return mid;
   else if(array[mid])
    return high=mid-1;
   else low=mid+1;
}

return -1;
}

int linearSearch(int array[], int size, int target)//It controls from the bass to the end
{
    int i;
for(i=0;i<size;i++)
    {
    if(array[i]==target)
    return i;
    }
return -1;
}
