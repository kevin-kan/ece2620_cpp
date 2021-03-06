//Kevin Kan
//ECE 2620-001
//Lab2: Circles with Classes

#include "circle.h"
#include <cmath>
#define PI (4*atan(1))


void circle::populate_classobj(double xcor1, double ycor1, double xcor2, double ycor2){
	x1 = xcor1;
	y1 = ycor1;
	x2 = xcor2;
	y2 = ycor2;
}
double circle::distance(){
	//Will calculate distance between (x1, y1) and (x2, y2)
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
double circle::radius(){
	//Will calculate distance between (x1, y1) and (x2, y2)
	//Runs distance method as radius
	return distance();
}
double circle::circumference(){
	//Will calculate circumference with given radius
	return 2*PI*radius();	
}
double circle::area(){
	// Will calculate circumference with given radius
	return PI*radius()*radius();
}
	                         



