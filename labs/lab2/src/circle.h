//Kevin Kan
//ECE 2620-001
//Lab2: Circles with classes

#ifndef _CIRCLE_H_
#define _CIRCLE_H_

class circle{
	public:
		double radius();
		double circumference();
		double area();
		void populate_classobj(double xcor1, double ycor1, double xcor2, double ycor2);

	protected:
		double distance ();

	private:
		double x1;
		double x2;
		double y1;
		double y2;
};


#endif // _CIRCLE_H_

