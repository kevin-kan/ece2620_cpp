#include <iostream>
#include <fstream>
#include <time.h>

#define MAXSIZE 2100000

using namespace std;

template <typename T>
void printArr(T arr[], long int size){		//Written for debugging purposes
	for (long int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void bubblesort(T arr[], long int size){	//Bubble Sort algorithm
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
void merge(T arr[], long int first, long int last){ //Merging for MergeSort
	long int mid = (first + last) /2;
	long int i = 0, l = first, r = mid + 1;
	T temp[last - first + 1];
	while (l <= mid && r <= last){		// compare numbers
		if (arr[l] < arr[r]){
			temp[i] = arr[l];
			l++;
		}
		else{
			temp[i] = arr[r];
			r++;
		}
		i++;
	}
	while (l <= mid){					//fill in what's remaining in left side
		temp[i] = arr[l];
		++i; ++l;
	}
	while (r <= last){					//fill in what's remaining in right side
		temp[i] = arr[r];
		++i; ++r;
	}
	long int b = first;
	for (long int a = 0; a < last-first+1; a++){	//put the sorted #s into original array
		arr[b] = temp[a];
		b++;
	}
}

template <typename T>
void mergesortHelper(T arr[], long int begin, long int end){	//MergeSort Algorithm
	if (end - begin + 1 >= 2){
		long int mid = (begin + end) /2;
		mergesortHelper(arr, begin, mid);		//left half
		mergesortHelper(arr, mid + 1, end);		//right half
		merge(arr, begin, end);					//put together at the end.
	}
}

template <typename T>
void mergesort(T arr[], long int size){			//So that mergesort can be called the same way as bubblesort
	mergesortHelper(arr, 0, size - 1);			
}