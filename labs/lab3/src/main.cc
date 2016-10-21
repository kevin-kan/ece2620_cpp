//Kevin Kan
//ECE 2620-001
//Lab3: Circles with Templates

#include <iostream>
#include "circle.h"

using namespace std;

int main(){
	double centerX, centerY, pointX, pointY;
	double dist, rad;

/*	// Taking User input of the coordinates of the center of the circle.
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
	cout << "Point: (" << pointX << ", " << pointY << ") " << endl;*/

	circle<int> my_obj1(1, 3);
	circle<double> my_obj2(-1.5, -6.65, -0.5, 10.0);
	
	//Provides user options to get Radius, Circumference, Area
	int option;
	bool exit = false;
	while (!exit){
		cout << "What would you like to do?" << endl;
		cout << " (1) Compute Radius \n (2) Computer Circumference \n (3) Compute Area \n (4) Set new coordinates for Circle 1 \n (5) Set new coordinates for Cirle 2 \n (6) Exit" << endl;
		cin >> option;
		switch(option){
			case 1:
				cout << "Radius of circle 1: " << my_obj1.radius() << endl;
				cout << "Radius of circle 2: " << my_obj2.radius() << endl;
				exit = false;
				break;
			case 2:
				cout << "Circumference of circle 1: " << my_obj1.circumference() << endl;
				cout << "Circumference of circle 2: " << my_obj2.circumference() << endl;
				exit = false;
				break;
			case 3:
				cout << "Area of the circle 1: " << my_obj1.area() << endl;
				cout << "Area of the circle 2: " << my_obj2.area() << endl;
				exit = false;
				break;
			case 4:
				cout << "New Coordinates for circle 1:(Integers)" << endl;
				cout << "X Coordinate of Center:";
				cin >> centerX;
				cout << "Y Coordinate of Center:";
				cin >> centerY;
				cout << "X Coordinate of Point:";
				cin >> pointX;
				cout << "Y Coordinate of Point:";
				cin >> pointY;
				my_obj1.populate_classobj(centerX, centerY, pointX, pointY);
				exit = false;
				break;
			case 5:
				cout << "New Coordinates for circle 2:(Double Precision Floating Point)" << endl;
				cout << "X Coordinate of Center:";
				cin >> centerX;
				cout << "Y Coordinate of Center:";
				cin >> centerY;
				cout << "X Coordinate of Point:";
				cin >> pointX;
				cout << "Y Coordinate of Point:";
				cin >> pointY;
				my_obj2.populate_classobj(centerX, centerY, pointX, pointY);
				exit = false;
				break;
			case 6:
				cout << "Goodbye!" << endl;
				exit = true;
				break;
			default:
				cout << "Not a valid option.\n Please choose an option from the menu." << endl;
		}
	}

	
	return 0;
}

