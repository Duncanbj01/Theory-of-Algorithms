#ifndef SELECTION_H_
#define SELECTION_H_

#include "Partition.h"

class Selection {

public:

	static int select(int *array, int n, int k) 
	{
		return select(array, 0, n - 1, k);
	}

private:

    static int select(int *array, int left, int right, int k) 
	{ // complete this function

		if (left == right)
		{
			return left;
		}

		int pivotIndex = Partition::generateRandomPivot(array, left, right);
		int* partitionIndexes = new int[k];
		partitionIndexes = Partition::partition(array, left, right, pivotIndex);

		if (k >= partitionIndexes[0] + 1 && k <= partitionIndexes[1] + 1)
		{
			return partitionIndexes[0]; 
		}
		else if (k < partitionIndexes[0] + 1)
		{
			return select(array, left, partitionIndexes[0] - 1, k); 
		}
		else
		{
			return select(array, partitionIndexes[1] + 1, right, k); 
		}

		delete[] partitionIndexes; 
    }
};

#endif /* SELECTION_H_ */
