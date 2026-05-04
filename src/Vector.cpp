#include "../header/Vector.h"
#include <math.h>

Vector::Vector(const Point& A, const Point& B)
{
    this->A = A;
    this->B = B;
}

double Vector::getLen() const
{
    return sqrt(pow(B.getX() - A.getX(), 2) + pow(B.getY() - A.getY(), 2));
}

double Vector::getAngle(const Vector& other) const
{
    double x1 = B.getX() - A.getX();
    double y1 = B.getY() - A.getY();

    double x2 = other.B.getX() - other.A.getX();
    double y2 = other.B.getY() - other.A.getY();

    double scalar = x1 * x2 + y1 * y2;
    double len1 = sqrt(x1 * x1 + y1 * y1);
    double len2 = sqrt(x2 * x2 + y2 * y2);

    if (len1 <= std::numeric_limits<double>::epsilon() || len2 <= std::numeric_limits<double>::epsilon())
    {
        throw std::runtime_error("Невозможно вычислить угол: нулевой вектор");
    }

    double cosValue = scalar / (len1 * len2);

    if (cosValue > 1.0) cosValue = 1.0;
    if (cosValue < -1.0) cosValue = -1.0;

    return acos(cosValue);
}
