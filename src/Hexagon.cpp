#include "../header/Hexagon.h"
#include "../header/Vector.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

double Hexagon::eps = std::numeric_limits<double>::epsilon();

void Hexagon::error(const std::string& text) const
{
    throw std::runtime_error(text);
}

void Hexagon::thisHexagon() const
{
    Point point[countPoint] = { A, B, C, D, E, F };

    for (size_t i = 0; i < countPoint; i++)
    {
        for (size_t j = i + 1; j < countPoint; j++)
        {
            if (point[i] == point[j])
            {
                error("Фигура не образует шестиугольник: Точки совпадают");
            }
        }
    }

    Vector one(A, B);
    Vector two(B, C);
    Vector three(C, D);
    Vector four(D, E);
    Vector five(E, F);
    Vector six(F, A);

    double len[countPoint] = {
        one.getLen(), two.getLen(), three.getLen(),
        four.getLen(), five.getLen(), six.getLen()
    };

    double angle[countPoint] = {
        one.getAngle(two), two.getAngle(three), three.getAngle(four),
        four.getAngle(five), five.getAngle(six), six.getAngle(one)
    };

    for (size_t i = 1; i < countPoint; i++)
    {
        if (std::fabs(len[i] - len[0]) > Hexagon::eps)
        {
            error("Фигура не образует шестиугольник: Стороны не равны");
        }
    }

    for (size_t i = 0; i < countPoint; i++)
    {
        if (std::fabs(angle[i] - 120.0) > Hexagon::eps)
        {
            error("Фигура не образует правильный шестиугольник: Угол не равен 120 градусам");
        }
    }
}

double Hexagon::fixValue(double value)
{
    if (std::fabs(value - std::round(value)) < 0.001)
    {
        value = std::round(value);
    }

    return std::round(value * 1000.0) / 1000.0;
}

Hexagon::Hexagon(const Point& A, const Point& B, const Point& C, const Point& D, const Point& E, const Point& F)
{
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
    this->E = E;
    this->F = F;

    thisHexagon();
}

Hexagon::Hexagon(const Hexagon& other)
    : A(other.A), B(other.B), C(other.C), D(other.D), E(other.E), F(other.F)
{
    thisHexagon();
}

Hexagon::Hexagon(Hexagon&& other) noexcept
    : A(std::move(other.A)),
    B(std::move(other.B)),
    C(std::move(other.C)),
    D(std::move(other.D)),
    E(std::move(other.E)),
    F(std::move(other.F))
{
    thisHexagon();
}
void Hexagon::setEps(const double value)
{
    if (value <= 0 || value > 1)
    {
        throw std::runtime_error("Недопустимое значение");
    }
    eps = value;
}

double Hexagon::getArea()
{
    Vector one(A, B);
    return fixValue(3 * std::sqrt(3.0) / 2 * one.getLen() * one.getLen());
}

double Hexagon::getPerimetr()
{
    Vector one(A, B);
    return fixValue(6 * one.getLen());
}

void Hexagon::ToString(std::ostream& os)
{
    Vector one(A, B);

    os << "Фигура: Правильный-Шестиугольник" << std::endl;
    os << "Точка A (" << A.getX() << "; " << A.getY() << ")" << std::endl;
    os << "Точка B (" << B.getX() << "; " << B.getY() << ")" << std::endl;
    os << "Точка C (" << C.getX() << "; " << C.getY() << ")" << std::endl;
    os << "Точка D (" << D.getX() << "; " << D.getY() << ")" << std::endl;
    os << "Точка E (" << E.getX() << "; " << E.getY() << ")" << std::endl;
    os << "Точка F (" << F.getX() << "; " << F.getY() << ")" << std::endl;
    os << "Длинна между точками: " << fixValue(one.getLen()) << std::endl;
}
