#ifndef RADIXSORT_H_
#define RADIXSORT_H_

#include <iostream>
using namespace std;

class RadixSort {
    
private:

    static int getMax(int arr[], int n)
    {
        int mx = arr[0]; 
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > mx)
            {
                mx = arr[i]; 
            }
        }
        return mx; 
    }
    
    static void countSortOnDigits(int *A, int n, int *digits) 
    { // complete this function
        int* C = new int[n]; 
        for (int i = 0; i < n; i++)
        {
            C[i] = 0; 
        }

        int* T = new int[n]; 

        for (int i = 0; i < n; i++) 
        { 
            C[digits[i]]++; 
        }

        for (int i = 1; i < n; i++) 
        { 
            C[i] = C[i - 1] + C[i]; 
        }

        for (int i = n - 1; i >= 0; i--) 
        { 
            C[digits[i]]--;
            T[C[digits[i]]] = A[i]; 
        }

        for (int i = 0; i < n; i++) 
        { 
            A[i] = T[i]; 
        }

        delete[] C;
        delete[] T;
    }
    
    static void radixSortNonNeg(int A[], int n) 
    { // complete this function

        int M = getMax(A, n); 

        int* digits = new int[n]; 

        int e = 1; 

        while (M / e > 0)
        {
            for (int i = 0; i <= n-1; i++)
            {
                digits[i] = (A[i] / e) % n; 
            }
            countSortOnDigits(A, n, digits); 
            e = e * n; 
        }
     
        delete[] digits; 

    }
    
public:
    
    static void radixSort(int A[], int n) 
    {
        // Separate positive and negative integers
        vector<int> positive, negative;
        for (int i = 0; i < n; i++) {
            if (A[i] >= 0)
                positive.push_back(A[i]);
            else
                negative.push_back(-A[i]);
        }

        // Sort positive integers
        radixSortNonNeg(&positive[0], positive.size());

        // Sort negative integers
        radixSortNonNeg(&negative[0], negative.size());

        // Merge sorted positive and negative integers back into the original array
        int j = 0;
        for (int i = negative.size() - 1; i >= 0; i--)
            A[j++] = -negative[i];
        for (int i = 0; i < positive.size(); i++)
            A[j++] = positive[i]; 
    }
};

#endif /* RADIXSORT_H_ */
