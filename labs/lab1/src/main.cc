//KEVIN KAN
//ECE 2620-001
//LAB 1: Distance, Radius, Circumference, Area

#include <iostream>
#include <cmath>
#define PI (4*atan(1))

using namespace std;


double distance(double x1, double y1, double x2, double y2){
	//Will calculate distance between (x1, y1) and (x2, y2)
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
double radius(double rx1, double ry1, double rx2, double ry2){
	//Will calculate distance between (x1, y1) and (x2, y2)
	//Runs distance method as radius
	return distance(rx1, ry1, rx2, ry2);
}
double circumference(double radius){
	//Will calculate circumference with given radius
	return 2*PI*radius;	 
}
double area(double radius){
	// Will calculate circumference with given radius
	return PI*radius*radius;
}

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
	
	dist = distance(centerX, centerY, pointX, pointY);
	// cout << "Distance between points:" << dist << endl;

	rad = radius(centerX, centerY, pointX, pointY);
	//Provides user options to get Radius, Circumference, Area
	
	int option;
	bool exit = false;
	while (!exit){
		cout << "What would you like to do?" << endl;
		cout << " (1) Compute Radius \n (2) Computer Circumference \n (3) Compute Area \n (4) Exit" << endl;
		cin >> option;
		switch(option){
			case 1:
				cout << "Radius of the circle: " << rad << endl;
				exit = true;
				break;
			case 2:
				cout << "Circumference of the circle: " << circumference(rad) << endl;
				exit = true;
				break;
			case 3:
				cout << "Area of the circle: " << area(rad) << endl;
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
