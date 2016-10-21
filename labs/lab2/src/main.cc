//Kevin Kan
//ECE 2620-001
//Lab2: Circles with Classes

#include <iostream>
#include "circle.h"

using namespace std;

int main(){
	double centerX, centerY, pointX, pointY;
	double dist, rad;

	// Taking User input of the coordinates of the center of the circle.
	cout << "X Coordinate of Center:";
	cin >> centerX;
	cout << "Y Coordinate of Center:";
	cin >> centerY;

	// Taking User input of the coordinates of a point on the circle.
	cout << "X Coordinate of Point:";
	cin >> pointX;
	cout << "Y Coordinate of Point:";
	cin >> pointY;
	
	cout << "Center: (" << centerX << ", " << centerY << ") ";
	cout << "Point: (" << pointX << ", " << pointY << ") " << endl;

	circle myCircle;
	myCircle.populate_classobj(centerX, centerY, pointX, pointY);
	
	//Provides user options to get Radius, Circumference, Area
	int option;
	bool exit = false;
	while (!exit){
		cout << "What would you like to do?" << endl;
		cout << " (1) Compute Radius \n (2) Computer Circumference \n (3) Compute Area \n (4) Exit" << endl;
		cin >> option;
		switch(option){
			case 1:
				cout << "Radius of the circle: " << myCircle.radius() << endl;
				exit = true;
				break;
			case 2:
				cout << "Circumference of the circle: " << myCircle.circumference() << endl;
				exit = true;
				break;
			case 3:
				cout << "Area of the circle: " << myCircle.area() << endl;
				exit = true;
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

