#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#include "StringRadixSort.h"
#include "StringMergeSort.h"

using namespace std;

const int CLOCKS_PER_MILLISEC = CLOCKS_PER_SEC / 1000;

const static int LARGE_STRING_SIZES[] = { 1000000, 5000000, 10000000, 15000000,
		20000000, 25000000 };

static void testStringSorter() {
    cout << "****************** Time Test String Sorting ******************\n"
    << endl;
    long timeMerge = 0, timeRadix = 0, timeStd = 0;
    int maxLength = 25;
    for (int r = 0; r < sizeof(LARGE_STRING_SIZES) / sizeof(int); r++) {
        int size = LARGE_STRING_SIZES[r];
        string **radixSortStrings = new string*[size];
        string **mergeSortStrings = new string*[size];
        string **stdSortStrings = new string*[size];
        for (int i = 0; i < size; i++) {
            int stringLength = 1 + rand() % maxLength;
            string str = "";
            for (int j = 0; j < stringLength; j++) {
                char c = 97 + (rand() % 26);
                str += c;
            }
            radixSortStrings[i] = mergeSortStrings[i] = stdSortStrings[i] = &str;
        }
        
        long startTime = clock();
        StringMergeSort(mergeSortStrings, size).mergesort();
        timeMerge = clock() - startTime;
        
        startTime = clock();
        StringRadixSort::radixSort(radixSortStrings, size);
        timeRadix = clock() - startTime;
        
        startTime = clock();
        std::sort(stdSortStrings, stdSortStrings + size);
        timeStd = clock() - startTime;
        
        for (int i = 0; i < size - 1; i++) {
            if (mergeSortStrings[i]->compare(*mergeSortStrings[i + 1]) > 0)
                throw("Something wrong with merge sort");
            if (radixSortStrings[i]->compare(*radixSortStrings[i + 1]) > 0)
                throw("Something wrong with radix sort");
            if (stdSortStrings[i]->compare(*stdSortStrings[i + 1]) > 0)
                throw("Something wrong with C++ sort");
        }
        delete[] radixSortStrings;
        delete[] mergeSortStrings;
        delete[] stdSortStrings;
        cout << "Merge-sort time for " << size << " strings = "
        << timeMerge / CLOCKS_PER_MILLISEC
        << " (may vary with each execution)" << endl;
        cout << "Radix-sort time for " << size << " strings = "
        << timeRadix / CLOCKS_PER_MILLISEC
        << " (may vary with each execution)" << endl;
        cout << "C++ standard-sort time for " << size << " strings = "
        << timeStd / CLOCKS_PER_MILLISEC
        << " (may vary with each execution)" << endl << endl;
    }
}

int main() {
    testStringSorter();
    return 1;
}
