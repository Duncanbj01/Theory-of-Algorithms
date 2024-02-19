#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#ifndef MERGESORT_H_
#define MERGESORT_H_

template<class T>
class GenericMergeSort {

private:

	T *array;
	T *mergedArray;
	int n;

public:

	GenericMergeSort(T *array, int n) {
		this->array = array;
		this->n = n;
		this->mergedArray = new T[n];
	}

	template<typename F>
	void mergesort(F comparator) {
		mergesort(0, n - 1, comparator);
	}

private:

	template<typename F>
	void mergesort(int left, int right, F comparator) {
		if (left == right)
			return;
		int mid = (left + right) / 2;
		mergesort(left, mid, comparator);
		mergesort(mid + 1, right, comparator);
		int i = left;
		while (i <= right) {
			mergedArray[i] = array[i];
			i++;
		}
		i = left;
		int j = mid + 1, k = left;
		while (i <= mid && j <= right)
			array[k++] =
					comparator(mergedArray[j], mergedArray[i]) ?
							mergedArray[j++] : mergedArray[i++];
		while (i <= mid)
			array[k++] = mergedArray[i++];
	}
};

#endif /* MERGESORT_H_ */
