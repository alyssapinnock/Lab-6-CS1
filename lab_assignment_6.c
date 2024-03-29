/*

Lab 6 - Computer Science 1
Alyssa Pinnock
2/22/24

Instructions: Write an efficient recursive function that takes in a sorted array of numbers,
two integers, low and high, representing indexes into the array, and another integer, value,
and returns the index in the array where value is found in the array in between index low and
high, inclusive. If value is NOT found in the array in between indexes low and high, inclusive,
then the function should return -1. 

*/

#include <stdio.h>

int search(int numbers[], int low, int high, int value) 
{
	int mid;
	if(low > high){ // Checking first to make sure it is a valid range
		return -1;
	}
	if (low <= high){
		mid = (high + low)/2;
		if (numbers[mid] == value){ // Returning mid if that index is equal to value
			return mid;
		}
		else if (numbers[mid] > value){ // Searching lower part of array
			return search(numbers, low, mid - 1, value);
		}
		else // Searching higher part of array
			return search(numbers, mid + 1, high, value);
	}
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}