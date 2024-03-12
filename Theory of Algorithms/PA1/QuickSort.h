#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "Partition.h"
#include "Partition.h"


class QuickSort {

public:

	static void quicksortMedianOf3(int array[], int n) {
		quicksortMedianOf3(array, 0, n - 1);
	}

    static void quicksortRandom(int array[], int n) {
		quicksortRandom(array, 0, n - 1);
	}

private:

    static void quicksortMedianOf3(int array[], int left, int right) 
	{ // complete this function
		if (left < right)
		{
			int pivotIndex = Partition::generateMedianOf3Pivot(array, left, right); 
			int* partitionIndex = new int[pivotIndex]; 
			partitionIndex = Partition::partition(array, left, right, pivotIndex);
			quicksortMedianOf3(array, left, partitionIndex[0] - 1); 
			quicksortMedianOf3(array, partitionIndex[1] + 1, right); 
			delete[] partitionIndex; 
		}
		
    }

    static void quicksortRandom(int array[], int left, int right) 
	{ // complete this function
		if (left < right)
		{
			int pivotIndex = Partition::generateRandomPivot(array, left, right); 
			int* partitionIndex = new int[pivotIndex];
			partitionIndex = Partition::partition(array, left, right, pivotIndex); 
			quicksortRandom(array, left, partitionIndex[0] - 1); 
			quicksortRandom(array, partitionIndex[1] + 1, right); 
			delete[] partitionIndex; 
		}
    }
};

#endif /* QUICKSORT_H_ */
