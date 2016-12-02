// Kevin Kan
// ECE 2620-001
// Lab 5: Bubble Sort & Merge Sort

/* ********************************************* */
// Bubble/Merge sort report found in README file 
//  ../lab5/README
/* ********************************************* */

#include "sorts.h"

int main(){
	ifstream infile;
	ofstream bubbleOut, mergeOut;
	long signed int arrB[MAXSIZE];
	long signed int arrM[MAXSIZE];
	double startT, endT, diffT;
	long int numLines, i;
	string line;
	bool doneReading = false;
	
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
				/* READING FROM FILE */
				infile.open("lab5_input.txt");
				if (infile.is_open()){								// Checks if file is really open
					i = 0;
					while(!infile.eof() && i < MAXSIZE){			// stops at end of file or if MAXSIZE reached
						infile >> arrB[i];
						arrM[i] = arrB[i];
						i++;
					}
					numLines = i - 1;
					cout << "numLines = " << numLines << endl;
					cout << "File Read Complete." << endl;
					infile.close();
					doneReading = true;
				}
				else{
					cout << "Failed to read from file." << endl;
					infile.close();
					return 0;
				}
				break;
			case 2:
				if (doneReading){
					cout << "Sorting with Bubble Sort..." << endl;
					startT = clock();
					bubblesort(arrB, numLines);
					endT = clock();
					diffT = (endT - startT)/CLOCKS_PER_SEC;
					bubbleOut.open("lab5_bubbleout.txt");
					if (bubbleOut.is_open()){
						for (i = 0; i < numLines; i++){
							bubbleOut << arrB[i] << endl;
						}
						cout << "Bubble Sort: File Write Complete." << endl;
						cout << "Time to sort: " << diffT << " seconds." << endl;
						bubbleOut.close();
					}
					else{
						cout << "Failed to write to file." << endl;
						bubbleOut.close();
						return 0;
					}
					break;
				}
				else{
					cout << "Please read from the file first." << endl;
					break;
				}
			case 3:
				if (doneReading){
					cout << "Sorting with Merge Sort..." << endl;
					startT = clock();
					mergesort(arrM, numLines);
					endT = clock();
					diffT = (endT - startT)/CLOCKS_PER_SEC;
					mergeOut.open("lab5_mergeout.txt");
					//cout << "merge outfile open" << endl;	 //for debug purposes
					if (mergeOut.is_open()){
						for (i = 0; i < numLines; i++){
							mergeOut << arrM[i] << endl;
						}
						cout << "Merge Sort: File Write Complete." << endl;
						cout << "Time to sort: " << diffT << " seconds." << endl;
						mergeOut.close();
					}
					else{
						cout << "Failed to write to file." << endl;
						mergeOut.close();
						return 0;
					}
					break;
				}
				else{
					cout << "Please read from the file first." << endl;
					break;
				}
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

