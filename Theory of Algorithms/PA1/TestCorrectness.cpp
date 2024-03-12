#include "InversionCounting.h"
#include "GenericMergeSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "RadixSort.h"
#include "Selection.h"
#include "MedianOfMedians.h"
#include "IntegerComparator.h"

using namespace std;

void printArray(int *A, int len) {
    if (0 == len) {
        cout << "[]";
        return;
    }
    cout << "[";
    for (int i = 0; i < len - 1; i++) {
        cout << A[i] << ", ";
    }
    cout << A[len - 1] << "]";
}

void testSorting(int *array, int n) {
    int *temp = new int[n];

    cout << "Original array:                  ";
    printArray(array, n);
    cout << endl;

    for (int i = 0; i < n; i++)
        temp[i] = array[i];
    cout << "MergeSorted array:               ";
    MergeSort(temp, n).mergesort();
    printArray(temp, n);
    cout << endl;

    for (int i = 0; i < n; i++)
        temp[i] = array[i];
    cout << "QuickSorted (median of 3) array: ";
    QuickSort::quicksortMedianOf3(temp, n);
    printArray(temp, n);
    cout << endl;

    for (int i = 0; i < n; i++)
        temp[i] = array[i];
    cout << "QuickSorted (random) array:      ";
    QuickSort::quicksortRandom(temp, n);
    printArray(temp, n);
    cout << endl;

    for (int i = 0; i < n; i++)
        temp[i] = array[i];
    cout << "RadixSorted array:               ";
    RadixSort::radixSort(temp, n);
    printArray(temp, n);
    cout << endl;
}

void testSelection(int *array, int n) {
    int *mergeArray = new int[n];
    for (int i = 0; i < n; i++)
        mergeArray[i] = array[i];
    MergeSort(mergeArray, n).mergesort();

    int *selArray = new int[n];

    cout << "*** Randomized Quick-select ***\n" << endl;

    for (int k = 1; k <= n; k++) {
        for (int j = 0; j < n; j++)
            selArray[j] = array[j];
        int answer = Selection::select(selArray, n, k);
        cout << k << "th smallest: " << selArray[answer];
        if (selArray[answer] != mergeArray[k - 1])
            cout << "; Selection code is incorrect for k = " << k << endl;
        cout << endl;
    }

    cout << "\n*** Median of Medians Quick-select ***\n" << endl;

    for (int k = 1; k <= n; k++) {
        for (int j = 0; j < n; j++)
            selArray[j] = array[j];
        int answer = Selection::select(selArray, n, k);
        cout << k << "th smallest: " << selArray[answer];
        if (selArray[answer] != mergeArray[k - 1])
            cout << "; Median of Medians code is incorrect for k = " << k << endl;
        cout << endl;
    }

    delete[] selArray;
    delete[] mergeArray;
}

static void testPartition() {
    cout << "\n****************** Two-Index Partition with Duplicates ******************\n"
            << endl;
    int array[] = { -13, -174, 19, 1, 4, 12, 100, 7, 4, 4, 10, 12, 4, 5, 6, 7,
            100, 56, 67, 13, 12, 45, 4, 4, 44, 8, 4, -10, 14, 4, -1, 97, -1009,
            4210, 4, 4, 1, 9, 17, 45, 4, -99, -845, -90, -9, 13, -13 };
    int n = sizeof(array) / sizeof(int);
    cout << "Original Array: ";
    printArray(array, n);
    cout << endl;
    int pivot = 4;
    int *partitionIndex = Partition::partition(array, 0, n - 1, pivot);
    cout << "\npivot = " << pivot << endl;
    cout << "Lower Partition Index = " << partitionIndex[0];
    cout << endl << "Upper Partition Index = " << partitionIndex[1];
    cout << endl << "\nAfter Partitioning: ";
    printArray(array, n);
    cout << endl;
}

static void testRandomizedQuickSort() {
    cout << "\n****************** Randomized Quick-Sort with Duplicates ******************\n"
            << endl;
    int array[] = { -13, -174, 19, 1, 4, 12, 100, 7, 4, 4, 10, 12, 4, 5, 6, 7,
            100, 56, 67, 13, 12, 45, 4, 4, 44, 8, 4, -10, 14, 4, -1, 97, -1009,
            4210, 4, 4, 1, 9, 17, 45, 4, -99, -845, -90, -9, 13, -13 };
    int n = sizeof(array) / sizeof(int);
    cout << "Original Array: ";
    printArray(array, n);
    cout << endl;
    QuickSort::quicksortRandom(array, n);
    cout << "After Sorting:  ";
    printArray(array, n);
    cout << endl;
}

static void testMedianOf3QuickSort() {
    cout << "\n****************** Median of 3 Quick-Sort with Duplicates ******************\n"
            << endl;
    int array[] = { -13, -174, 19, 1, 4, 12, 100, 7, 4, 4, 10, 12, 4, 5, 6, 7,
            100, 56, 67, 13, 12, 45, 4, 4, 44, 8, 4, -10, 14, 4, -1, 97, -1009,
            4210, 4, 4, 1, 9, 17, 45, 4, -99, -845, -90, -9, 13, -13 };
    int n = sizeof(array) / sizeof(int);
    cout << "Original Array: ";
    printArray(array, n);
    cout << endl;
    QuickSort::quicksortRandom(array, n);
    cout << "After Sorting:  ";
    printArray(array, n);
    cout << endl;
}

static void testRadixSort() {
    cout << "\n****************** Radix-sort with Duplicates ******************\n"
            << endl;
    int array[] = { -13, -174, 19, 1, 4, 12, 100, 7, 4, 4, 10, 12, 4, 5, 6, 7,
            100, 56, 67, 13, 12, 45, 4, 4, 44, 8, 4, -10, 14, 4, -1, 97, -1009,
            4210, 4, 4, 1, 9, 17, 45, 4, -99, -845, -90, -9, 13, -13 };
    int n = sizeof(array) / sizeof(int);
    cout << "Original Array: ";
    printArray(array, n);
    cout << endl;
    RadixSort::radixSort(array, n);
    cout << "After Sorting:  ";
    printArray(array, n);
    cout << endl;
}

static void testRandomizedSelect() {
    cout << "\n****************** Randomized Quick-Select with Duplicates ******************\n"
            << endl;
    int array[] = { -13, -174, 19, 1, 4, 12, 100, 7, 4, 4, 10, 12, 4, 5, 6, 7,
            100, 56, 67, 13, 12, 45, 4, 4, 44, 8, 4, -10, 14, 4, -1, 97, -1009,
            4210, 4, 4, 1, 9, 17, 45, 4, -99, -845, -90, -9, 13, -13 };
    int n = sizeof(array) / sizeof(int);
    cout << "Original Array: ";
    printArray(array, n);
    cout << endl;
    int *temp = new int[n];
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < n; i++)
            temp[i] = array[i];
        printf("%dth smallest number is %d\n", k,
               temp[Selection::select(temp, n, k)]);
    }
    delete[] temp;
}

static void testMedianOfMediansSelect() {
    cout << "\n****************** Median of Medians with Duplicates ******************\n"
            << endl;
    int array[] = { -13, -174, 19, 1, 4, 12, 100, 7, 4, 4, 10, 12, 4, 5, 6, 7,
            100, 56, 67, 13, 12, 45, 4, 4, 44, 8, 4, -10, 14, 4, -1, 97, -1009,
            4210, 4, 4, 1, 9, 17, 45, 4, -99, -845, -90, -9, 13, -13 };
    int n = sizeof(array) / sizeof(int);
    cout << "Original Array: ";
    printArray(array, n);
    cout << endl;
    int *temp = new int[n];
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < n; i++)
            temp[i] = array[i];
        printf("%dth smallest number is %d\n", k,
               temp[MedianOfMedians::select(temp, n, k)]);
    }
    delete[] temp;
}

void testInversions(int *array, int n) {
    cout << "*** Inversion Counting ***\n"
            << endl;
    cout << "Array is: ";
    printArray(array, n);
    InversionCounting invCount(array, n);
    cout << endl << "Number of inversions is: " << invCount.countInversions()
            << endl;
}

int main()
{
    srand(clock());
    cout << "*** Sorting/Selection Test Without Duplicates ***\n" << endl;
    int sorting[] = { 19, 1, 12, 100, 7, 8, 4, -10, 14, -1, 97, -1009, 4210 };
    int n = sizeof(sorting) / sizeof(int);
    int *selection = new int[n];
    for (int i = 0; i < n; i++)
        selection[i] = sorting[i];

    testSorting(sorting, n);
    cout << endl;

    testSelection(selection, n);
    delete[] selection;
    
    testPartition();
    testRandomizedQuickSort();
    testMedianOf3QuickSort();
    testRadixSort();
    testRandomizedSelect();
    testMedianOfMediansSelect();

    cout << endl;
    testInversions(sorting, n);
    string s; 
    cin >> s; 
    return 0; 
}
