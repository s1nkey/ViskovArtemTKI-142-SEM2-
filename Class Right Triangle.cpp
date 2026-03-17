#include "Class Right Triangle.h"
#define _USE_MATH_DEFINES
#include <math.h>

void RightTriangle::CheckTriangle(const double leg_one, const double leg_two)
{
	if (leg_one <= 0 || leg_two <= 0)
	{
		cerr << "Заданы недопустимые значения, фигура не образует прямоугольный треугольник!" << endl;
		exit(1);
	}
}

RightTriangle::RightTriangle()
{
	leg_one = 3;
	leg_two = 4;
}

RightTriangle::RightTriangle(const double leg_one, const double leg_two)
{
	this->leg_one = leg_one;
	this->leg_two = leg_two;
	CheckTriangle(leg_one, leg_two);
}

double RightTriangle::RadiusCircle() const
{
	return sqrt(pow(leg_one, 2) + pow(leg_two, 2)) / 2.0;
}

double RightTriangle::AreaCircle() const
{
	return pow(RadiusCircle(), 2) * M_PI;
}
