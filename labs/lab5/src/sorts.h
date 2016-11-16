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
void bubblesort(T arr[], long int size){
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
void merge(T arr[], long int first, long int last){
	long int mid = (first + last) /2;
	long int i = 0, l = first, r = mid + 1;
	T temp[last - first + 1];
	while (l <= mid && r <= last){
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
	while (l <= mid){
		temp[i] = arr[l];
		++i; ++l;
	}
	while (r <= last){
		temp[i] = arr[r];
		++i; ++r;
	}
	int b = first;
	for (int a = 0; a < last-first+1; a++){
		arr[b] = temp[a];
		b++;
	}
}

template <typename T>
void mergesortHelper(T arr[], long int begin, long int end){
	if (end - begin + 1 >= 2){
		long int mid = (begin + end) /2;
		mergesortHelper(arr, begin, mid);
		mergesortHelper(arr, mid + 1, end);
		merge(arr, begin, end);
	}
}

template <typename T>
void mergesort(T arr[], long int size){
	mergesortHelper(arr, 0, size - 1);
}