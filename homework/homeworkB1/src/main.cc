// Kevin Kan
// ECE 2620:001
// Post Homework B1

#include <iostream>

using namespace std;

double fact(double x){ //solves for x!
	double prod = 1;
	for (int i = 1; i <=x; ++i){
		prod = prod * i;
	}
	return prod;
}

double binomialCoeff(int n, int p){ //solves for the binomial coefficient for method 1
	return fact(n)/(fact(p) * fact(n-p));
}

void pascalsTriangle1(int n){ //method 1
	for (int i = 0; i< n; ++i){
		for (int j = 0; j<= i; ++j){
			cout << binomialCoeff(i, j) << "\t";
		}
		cout << endl;
	}
}

int main(){
	int size = 22;
	double pascal[size][size];
	size = 16;
	int option;
	bool exit = false;
	while (!exit){
		cout << "Pascal's Triangle!" << endl;
		cout << " (1) Method 1 \n (2) Method 2 \n (3) Set size (default 16; max 22 for demonstration/viewing purposes) \n (4) Exit" << endl;
		cin >> option;
		switch(option){
			case 1:
				pascalsTriangle1(size);
				exit = false;
				break;
			case 2:
				for (int i = 0; i< size; i++){
					for (int j = 0; j< size; j++){
						if (j == 0) pascal[i][j] = 1; //first numbers are 1s
						if (i == j) pascal[i][j] = 1; //last numbers are 1s
						if (i > 1) pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
					}
				}
				//Prints bottom left triangle of the array
				for (int i = 0; i < size; ++i){
					for (int j = 0; j < size; ++j){
						if (i >= j) cout << pascal[i][j] << "\t";
					}
					cout << endl;
				}
				exit = false;
				break;
			case 3:
				cout << "Input new size:"<< endl;
				cin >> size;
				exit = false;
				break;
			case 4:
				cout << "Goodbye!" << endl;
				exit = true;
				break;
			default:
				cout << "Not a valid option.\n Please choose an option from the menu." << endl;
		}
	}

	
	return 0;
}

