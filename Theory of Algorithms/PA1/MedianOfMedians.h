#include "Partition.h"
#include <cmath>

#ifndef MedianOfMedians_h
#define MedianOfMedians_h

class MedianOfMedians {
    
private:
    
    static void insertionSort(int *arr, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int j = i, temp = arr[j];
            while (j > left && temp < arr[j - 1]) {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = temp;
        }
    }
    
public:
    
    static int select(int *array, int n, int k) {
        return select(array, 0, n - 1, k);
    }
    
private:
    
    static int select(int *array, int left, int right, int k) 
    { // complete this function
        if ((right - left + 1) <= 5)
        {
            insertionSort(array, left, right);
            {
                return k - 1; 
            }
        }
        int n = (right - left + 1); 

        //possible break point
        int* Median = new int[n / 5.0]; 

        for (int i = left, r = 0; i <= right; i = i + 5)
        {
            //possible break point
            int j = min(i + 4, right); 
            insertionSort(array, i, j); 
            Median[r++] = array[(i + j) / 2]; 
        }

        //possible break point
        int mom = Median[select(Median, 0, (n / 5) - 1, (n / 5) / 2)]; 

        int momIndex = 0; 

        for (int i = left; i <= right; i += 5)
        {
            int j = min(i + 4, right); 
            momIndex = (i + j) / 2; 
            if (array[momIndex] == mom)
            {
                break; 
            }
        }
        
        int* partitionIndexes = new int[momIndex];
        partitionIndexes = Partition::partition(array, left, right, momIndex);
        if (k == partitionIndexes[0] + 1 && k <= partitionIndexes[1] + 1)
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
    }
};

#endif /* MedianOfMedians_h */
