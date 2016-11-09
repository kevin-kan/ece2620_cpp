// Kevin Kan
// ECE 2620-001
// Lab 5: Bubble Sort & Merge Sort
#include "sorts.h"

int main(){
	ifstream infile;
	ofstream outfile;
	long i1;
	
	bool exit = false;
	int option;
	while (!exit){
		cout << "Hello, what would you like to do?" << endl;
		cout << "\t (1) Read data from input file" << endl;
		cout << "\t (2) Sort data using Bubble Sort" << endl;
		cout << "\t (3) Sort data using Merge Sort" << endl;
		cout << "\t (4) Exit" << endl;
		cin >> option;
		switch(option){
			case 1:
				cout << "Reading from input file: 'lab5_input.txt'..." << endl;
				/* DYNAMICALLY CREATE ARRAY */
				long signed int arrP[MAXSIZE];
				/* READING FROM FILE */
				infile.open("lab5_input.txt");
				if (infile.is_open()){						// Checks if file is really open
					for (int i = 0; i < MAXSIZE; i++){		// Fills array with #s
						infile >> arrP[i];
					}
					cout << "File Read Complete." << endl;
					infile.close();
					printArr(arrP, MAXSIZE);
				}
				else{
					cout << "Failed to read from file." << endl;
					infile.close();
					return 0;
				}
				break;
			case 2:
				cout << "Sorting with Bubble Sort..." << endl;
				bubblesort(arrP, MAXSIZE);
				outfile.open("lab5_bubbleout.txt");
				if (outfile.is_open()){
					for (int i = 0; i < MAXSIZE; i++){
						outfile << arrP[i] << endl;
					}
					cout << "Bubble Sort: File Write Complete." << endl;
					outfile.close();
				}
				else{
					cout << "Failed to write to file." << endl;
					outfile.close();
					return 0;
				}
				break;
			case 3:
				cout << "Sorting with Merge Sort..." << endl;
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
