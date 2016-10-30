// Kevin Kan
// ECE 2620:001
// Lab4: Accessing Dynamic Arrays Through Pointers

#include <iostream>
#include <fstream>

using namespace std;

int findmax(int a, int b, int c, int d, int e){
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	if (e > max) max = e;
	return max;
}

int main(){
	int numLines = 0;				// Number of Lines in file
	int i1, i2, i3, i4, i5;		// To store numbers in line

	/* DETERMINE NUMBER OF LINES IN FILE */
	string line;
	ifstream infile("lab4_input.txt");
	if (infile.is_open()){		// Checks if file is really open
		while (getline(infile, line)){
			numLines++;
		}
		cout << "Number of lines:" << numLines << endl;
		infile.close();
	}
	else{
		cout << "Failed to read from file." << endl;
		infile.close();
		return 0;
	}

//		/* ASK USER FOR NUMBER OF LINES */
//		cout << "How many lines are in the input file?";
//		cin >>  numLines;
//		//cout << "Number of lines:" << numLines << endl;

	 
	/* DYNAMICALLY CREATE ARRAY */
	int* arrP;
	arrP = new int[numLines];

	/* READING FROM FILE */
	// ifstream infile("lab4_input.txt");
	// ifstream infile;
	infile.open("lab4_input.txt");
	if (infile.is_open()){		// Checks if file is really open
		for (int i = 0; i < numLines; i++){		// Fills array with max #s
			infile >> i1 >> i2 >> i3 >> i4 >> i5;
			*(arrP + i) = findmax(i1, i2, i3, i4, i5);
		}
		cout << "File Read Complete." << endl;
		infile.close();
	}
	else{
		cout << "Failed to read from file." << endl;
		infile.close();
		return 0;
	}
	
	/* WRITING TO FILE */
	ofstream outfile;
	outfile.open("lab4_output.txt");
	if (outfile.is_open()){
		for (int i = 0; i < numLines; i++){
			outfile << *(arrP + i) << endl;
		}
		cout << "File Write Complete." << endl;
		outfile.close();
	}
	else{
		cout << "Failed to write to file." << endl;
		outfile.close();
		return 0;
	}

	/* DELETE DYNAMICALLY CREATED ARRAY*/
	delete[] arrP;
	
	return 0;
}

