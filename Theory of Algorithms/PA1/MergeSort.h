#ifndef MergeSort_h
#define MergeSort_h

class MergeSort {
    
private:
    
    int *mergedArray;
    int *array;
    int n;
    
public:
    
    MergeSort(int *array, int n) {
        this->array = array;
        this->mergedArray = new int[n];
        this->n = n;
    }
    
    ~MergeSort() {
        delete[] mergedArray;
    }
    
    void mergesort() {
        mergesort(0, n - 1);
    }
    
private:
    
    void mergesort(int left, int right) {
        if (left == right)
            return;
        int mid = left + (right - left) / 2;
        mergesort(left, mid);
        mergesort(mid + 1, right);
        
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right) {
            if (array[i] <= array[j])
                mergedArray[k++] = array[i++];
            else
                mergedArray[k++] = array[j++];
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
    }
};

#endif /* MergeSort_h */
