#include "InversionCounting.h"
#include "GenericMergeSort.h"
#include "MedianOfMedians.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "RadixSort.h"
#include "Selection.h"
#include "ClosestPairOfPoints.h"
#include "IntegerComparator.h"

using namespace std;

const int CLOCKS_PER_MILLISEC = CLOCKS_PER_SEC / 1000;

const static int LARGE_POINT_SIZES[] = { 10, 50, 100, 500, 1000, 2000, 5000,
		10000, 20000, 50000, 100000 };

void testIfSorted(int A[], int len, char s) {
	for (int i = 0; i < len - 1; i++)
		if (A[i] > A[i + 1]) {
			if (s == 'M')
				throw("MergeSort code is incorrect");
			else if (s == '3')
				throw("QuickSort (median of 3) code is incorrect");
			else if (s == 'Q')
				throw("QuickSort (randomized) code is incorrect");
			else if (s == 'R')
				throw("RadixSort code is incorrect");
		}
}

int getRandom() {
	return (rand() - RAND_MAX / 2) * 2 / 3;
}

void compareSorting() {
	cout
			<< "Length, MergeSort, QuickSort (median of 3), QuickSort (randomized), RadixSort"
			<< endl;
	double mergeAvg = 0, quickMedianOf3Avg = 0, quickRandomAvg = 0,
			radixRandomAvg = 0;
	int numExec = 0;
	for (int num = 500000; num <= 50000000; num *= 1.3) {
		int *array = new int[num];
		int *temp = new int[num];
		for (int i = 0; i < num; i++)
			array[i] = getRandom();

		double timeStart, timeEnd;

		for (int i = 0; i < num; i++)
			temp[i] = array[i];
		timeStart = clock();
		MergeSort(temp, num).mergesort();
		timeEnd = clock();
		testIfSorted(temp, num, 'M');
		mergeAvg += (timeEnd - timeStart);
		cout << num << ", " << (timeEnd - timeStart) / CLOCKS_PER_MILLISEC;

		for (int i = 0; i < num; i++)
			temp[i] = array[i];
		timeStart = clock();
		QuickSort::quicksortMedianOf3(temp, num);
		timeEnd = clock();
		testIfSorted(temp, num, '3');
		quickMedianOf3Avg += (timeEnd - timeStart);
		cout << ", " << (timeEnd - timeStart) / CLOCKS_PER_MILLISEC;

		for (int i = 0; i < num; i++)
			temp[i] = array[i];
		timeStart = clock();
		QuickSort::quicksortRandom(temp, num);
		timeEnd = clock();
		testIfSorted(temp, num, 'Q');
		quickRandomAvg += (timeEnd - timeStart);
		cout << ", " << (timeEnd - timeStart) / CLOCKS_PER_MILLISEC;

		for (int i = 0; i < num; i++)
			temp[i] = array[i];
		timeStart = clock();
		RadixSort::radixSort(temp, num);
		timeEnd = clock();
		testIfSorted(temp, num, 'R');
		radixRandomAvg += (timeEnd - timeStart);
		cout << ", " << (timeEnd - timeStart) / CLOCKS_PER_MILLISEC << endl;

		numExec++;
		delete[] array;
		delete[] temp;
	}
	numExec *= CLOCKS_PER_MILLISEC;
	cout << "\nMergeSort average time is: " << mergeAvg / numExec << " millisecs" << endl;
	cout << "QuickSort (median of 3) average time is: "
			<< quickMedianOf3Avg / numExec << " millisecs" << endl;
	cout << "QuickSort (randomized) average time is: "
			<< quickRandomAvg / numExec << " millisecs" << endl;
	cout << "RadixSort average time is: " << radixRandomAvg / numExec
			<< " millisecs" << endl;
}

void compareSelection() {
	double momAvg = 0, randomAvg = 0, sortedAvg = 0;
	int numExec = 0;
	cout << "Length, Selection via RadixSort, Randomized Selection, Median of Medians Selection" << endl;
	for (int num = 500000; num <= 50000000; num *= 1.3) {
		int *array = new int[num];
		int *radix = new int[num];
		for (int i = 0; i < num; i++)
			radix[i] = array[i] = getRandom();

		double timeStart, timeEnd;
		int *K = new int[(int) log(num)];
		int lenK = (int) log(num);
		for (int i = 0; i < lenK; i++) {
			K[i] = rand() % num;
		}

		timeStart = clock();
		RadixSort::radixSort(radix, num);
		timeEnd = clock();
		sortedAvg += (timeEnd - timeStart) * lenK;
		cout << num << ", " << (timeEnd - timeStart) / CLOCKS_PER_MILLISEC;

		double selTime = 0, momTime = 0;
		int *selArray = new int[num];

		for (int i = 0; i < lenK; i++) {
			for (int j = 0; j < num; j++)
				selArray[j] = array[j];

			timeStart = clock();
			int answer = Selection::select(selArray, num, K[i]);
			timeEnd = clock();

			selTime += (timeEnd - timeStart);
			if (selArray[answer] != radix[K[i] - 1])
				throw("Selection code is incorrect");
		}
        
        for (int i = 0; i < lenK; i++) {
            for (int j = 0; j < num; j++)
                selArray[j] = array[j];
            
            timeStart = clock();
            int answer = MedianOfMedians::select(selArray, num, K[i]);
            timeEnd = clock();
            
            momTime += (timeEnd - timeStart);
            if (selArray[answer] != radix[K[i] - 1])
                throw("Median of Medians code is incorrect");
        }
        
		randomAvg += selTime;
        momAvg += momTime;
		numExec += lenK;
		cout << ", " << selTime / (CLOCKS_PER_MILLISEC * lenK);
        cout << ", " << momTime / (CLOCKS_PER_MILLISEC * lenK) << endl;

		delete[] K;
		delete[] radix;
		delete[] array;
		delete[] selArray;
	}
	numExec *= CLOCKS_PER_MILLISEC;
	cout << "\nSelection using RadixSort average time is: "
			<< sortedAvg / numExec << " millisecs" << endl;
	cout << "Selection using random pivot average time is: "
			<< randomAvg / numExec << " millisecs" << endl;
    cout << "Selection using Median of Medians average time is: "
            << momAvg / numExec << " millisecs" << endl;
}

void compareInversion() {
	double mergeSortAvg = 0, bruteForceAvg = 0;
	int numExec = 0;
	cout << "Length, BruteForce Inversion, MergeSort Inversion" << endl;
	for (int num = 10000; num <= 300000; num *= 1.3) {
		int *array = new int[num];
		for (int i = 0; i < num; i++)
			array[i] = getRandom();

		double timeStart, timeEnd;
		InversionCounting invCount(array, num);

		timeStart = clock();
		int count = invCount.bruteForce();
		timeEnd = clock();
		bruteForceAvg += (timeEnd - timeStart);
		cout << num << ", " << (timeEnd - timeStart) / CLOCKS_PER_MILLISEC;

		timeStart = clock();
		if (count != invCount.countInversions())
			throw("Inversion Counting code is incorrect");
		timeEnd = clock();
		mergeSortAvg += (timeEnd - timeStart);
		cout << num << ", " << (timeEnd - timeStart) / CLOCKS_PER_MILLISEC
				<< endl;
		numExec++;
		delete[] array;
	}
	numExec *= CLOCKS_PER_MILLISEC;
	cout << "\nBruteForce average time is: " << bruteForceAvg / numExec
			<< " millisecs" << endl;
	cout << "MergeSort Inversion average time is: " << mergeSortAvg / numExec
			<< " millisecs" << endl;
}

static void testClosestPoints() {
	for (int i = 0; i < sizeof(LARGE_POINT_SIZES) / sizeof(int); i++) {
		int numPoints = LARGE_POINT_SIZES[i];
		Point **points = new Point*[numPoints];
		for (int j = 0; j < numPoints; j++)
			points[j] = new Point(rand() % 1000000, rand() % 1000000);

		long startTime = clock();
		Point **bruteForce = ClosestPairOfPoints().bruteForce(points,
				numPoints);
		long timeBruteForce = clock() - startTime;

		startTime = clock();
		Point **nlogn = ClosestPairOfPoints().findClosestPair(points,
				numPoints);
		long timenlogn = clock() - startTime;

		double distBruteForce = bruteForce[0]->distance(bruteForce[1]);
		double distnlogn = nlogn[0]->distance(nlogn[1]);
		if (distBruteForce == distnlogn) {
			cout << "Time to find closest pair among " << numPoints
					<< " points using brute-force strategy = "
					<< timeBruteForce / CLOCKS_PER_MILLISEC
					<< " (may vary with each execution)" << endl;
			cout << "Time to find closest pair among " << numPoints
					<< " points using divide & conquer strategy = "
					<< timenlogn / CLOCKS_PER_MILLISEC
					<< " (may vary with each execution)" << endl;
			cout << endl;
		} else
			throw("Something is wrong!");

		for (int j = 0; j < numPoints; j++)
			delete points[j];
		delete[] points;
	}
}

int main() {
	srand(clock());
	cout << "*** Time Test Sorting ***\n" << endl;
	compareSorting();
	cout << "\n*** Time Test Selection ***\n" << endl;
	compareSelection();
	cout << "\n*** Time Test Inversion ***\n" << endl;
	compareInversion();
	cout
			<< "\n****************** Time Test Closest Pair of Points ******************\n"
			<< endl;
	testClosestPoints();
}
