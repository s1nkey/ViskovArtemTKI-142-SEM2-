#include "../header/Point.h"
#include <math.h>

void Point::error(const std::string text)
{
	throw std::runtime_error(text);
}

Point::Point(const double x, const double y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
}

Point::Point(Point&& other) noexcept
{
	x = other.x;
	y = other.y;

	other.x = 0;
	other.y = 0;
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

void Point::operator = (const Point& other)
{
	this->x = other.x;
	this->y = other.y;
}

bool Point::operator == (const Point other) const
{
	return ((fabs(this->x - other.x) <= std::numeric_limits<double>::epsilon())
		&& (fabs(this->y - other.y) <= std::numeric_limits<double>::epsilon()));
}

bool Point::operator != (const Point other) const
{
	return !(*this == other);
}

std::ostream& operator << (std::ostream& os, const Point& point)
{
	os << "(" << point.x << "; " << point.y << ")";
	return os;
}

std::istream& operator >> (std::istream& is, Point& point)
{
	double x = 0;
	double y = 0;
	is >> x >> y;
	if (is.fail())
	{
		point.error("Ошибка ввода");
	}
	point.x = x;
	point.y = y;

	return is;
}
