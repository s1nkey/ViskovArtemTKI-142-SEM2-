#pragma once
#include <string>
#include <iostream>

using namespace std;

/**
* @brief Класс прямоугольного треугольника
*/
class RightTriangle
{
private:
	/**
	* @param leg_one - длинна первого катета
	*/
	double leg_one;

	/**
	* @param leg_two - длинна второго катета
	*/
	double leg_two;


	/**
	* @brief Функция проверки задания треугольника
	* @param leg_one - длинна первого катета
	* @param leg_two - длинна второго катета
	*/
	void CheckTriangle(const double leg_one, const double leg_two);

public:

	/**
	* @brief Конструктор по-умолчанию, задаёт стороны как 3 и 4
	*/
	RightTriangle();

	/**
	* @brief Конструктор, задаёт стороны как значения, которые передал пользователь
	* @param leg_one - значение длинны первого катета
	* @param leg_two - значение длинны второго катета
	*/
	RightTriangle(const double leg_one, const double leg_two);

	/**
	* @brief Рассчитывает радиус описанной окружности
	* @return Радиус описанной окружности
	*/
	double RadiusCircle() const;

	/**
	* @brief Рассчитывает площадь описанной окружности
	* @return Площадь описанной окружности
	*/
	double AreaCircle() const;
};
