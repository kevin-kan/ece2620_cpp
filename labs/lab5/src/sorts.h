
#include <iostream>
#include <fstream>

#define MAXSIZE 23

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