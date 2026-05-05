#pragma once

#include "../header/Point.h"

/**
 * @brief Класс Vector - вектор на плоскости, заданный двумя точками
 */
class Vector
{
private:
	Point A;
	Point B;
public:
	/**
	 * @brief Конструктор, создающий вектор по двум точкам
	 * @param A - Начальная точка вектора
	 * @param B - Конечная точка вектора
	 */
	Vector(const Point& A, const Point& B);

	/**
	 * @brief Вычисляет длину вектора
	 * @return Длина вектора
	 */
	double getLen() const;

	/**
	 * @brief Вычисляет угол между текущим вектором и другим вектором
	 * @param other - Другой вектор, с которым вычисляется угол
	 * @return Угол между векторами в радианах
	 */
	double getAngle(const Vector& other) const;
};
