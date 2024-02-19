#ifndef INVERSIONCOUNTING_H_
#define INVERSIONCOUNTING_H_

class InversionCounting {

	int *array;
	int *mergedArray;
	int n;

public:

	InversionCounting(int *array, int n) {
		this->array = array;
		this->n = n;
		mergedArray = new int[n];
	}

	~InversionCounting() {
		delete[] mergedArray;
	}

	int countInversions() {
		mergedArray = new int[n];
		return countInversions(0, n - 1);
	}

	int bruteForce() {
		int count = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (array[i] > array[j])
					count++;
		return count;
	}

private:

    int countInversions(int left, int right) {
        if (left == right)
            return 0;
        int mid = left + (right - left) / 2;
        int count = countInversions(left, mid);
        count += countInversions(mid + 1, right);
        
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right) {
            if (array[i] <= array[j])
                mergedArray[k++] = array[i++];
            else {
                count += (mid - i + 1);
                mergedArray[k++] = array[j++];
            }
        }
        while (i <= mid)
            mergedArray[k++] = array[i++];
        while (j <= right)
            mergedArray[k++] = array[j++];
        
        k = left;
        while (k <= right) {
            array[k] = mergedArray[k];
            k++;
        }
        return count;
    }
};

#endif /* INVERSIONCOUNTING_H_ */
