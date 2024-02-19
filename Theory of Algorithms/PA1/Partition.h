#ifndef PARTITION_H_
#define PARTITION_H_

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;

class Partition {

public:

	static void swap(int array[], int x, int y) {
		int temp = array[x];
		array[x] = array[y];
		array[y] = temp;
	}

	static int generateRandomPivot(int array[], int left, int right) {
		return left + rand() % (right - left + 1);
	}

	static int generateMedianOf3Pivot(int array[], int left, int right) {
		int mid = (left + right) / 2;

		if (array[left] > array[mid])
			swap(array, left, mid);

		if (array[left] > array[right])
			swap(array, left, right);

		if (array[mid] > array[right])
			swap(array, mid, right);

		return mid;
	}

    static int* partition(int array[], int left, int right, int pivotIndex) 
	{ // complete this function
		int i = left; 
		int lowerPartitionIndex = left; 
		int upperPartitionIndex = right; 
		int pivotValue = array[pivotIndex];
		
		while (i <= upperPartitionIndex)
		{
			if (array[i] < pivotValue)
			{
				swap(array, i, lowerPartitionIndex); 
				i++; 
				lowerPartitionIndex++; 
			}
			else if (array[i] > pivotValue)
			{
				swap(array, i, upperPartitionIndex); 
				upperPartitionIndex--; 
			}
			else
			{
				i++; 
			}
		}

		int partitionIndexes[] = { lowerPartitionIndex, upperPartitionIndex }; 
		return partitionIndexes; 
    }
};

#endif /* PARTITION_H_ */
