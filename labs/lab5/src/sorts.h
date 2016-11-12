#include <iostream>
#include <fstream>
#include <time.h>

#define MAXSIZE 100

using namespace std;

template <typename T>
void printArr(T arr[], int size){
	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void bubblesort(T arr[], int size){
	T temp;
	for (int i = 0; i < size - 1; i++){
		for (int j = size-1; j > 0; j--){
			if (arr[j] < arr[j-1]){
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
				
		}
	}
}

template <typename T>
void mergesort(T arr[], int size){
	int sizeL, sizeR = size/2;
	if (size >= 2){
		if (size % 2 == 1) sizeL = size/2 + 1;
		else sizeL = size/2;
	}
	if (size >= 2){
		T arrL[sizeL];						// Left Array
		T arrR[sizeR];						// Right Array
		int i;

		for (i = 0; i < sizeL; ++i){		// Fill in left array
			arrL[i] = arr[i];
		}
		for (int j = 0; i < size; ++j){		// Fill in right array
			arrR[j] = arr[i];
			i++;
		}
		printArr (arrL, sizeL);				// For some reason, this only works with
//		printArr (arrR, sizeR);				//	  a printArr statement...
//		cout << " ";						// --> cout does not work.
		mergesort(arrL, sizeL);				// Sort the left array with mergeSort
		mergesort(arrR, sizeR);				// Sort the right array with mergeSort

		int l = 0, r = 0;
		i = 0;
		while (i < size){
			if (arrL[l] <= arrR[r]){
				arr[i] = arrL[l];
				l++;
			}
			else{
				arr[i] = arrR[r];
				r++;
			}
			i++;
		}

	}

}



