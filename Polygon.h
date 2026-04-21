#pragma once
#include <iostream>

/**
 * @brief Абстрактный класс Polygon - многоугольник
 */
class Polygon
{
public:
	/**
	 * @brief Вычисляет площадь многоугольника
	 * @return Площадь многоугольника
	 */
	virtual double getArea() = 0;

	/**
	 * @brief Вычисляет периметр многоугольника
	 * @return Периметр многоугольника
	 */
	virtual double getPerimetr() = 0;

	/**
	 * @brief Выводит информацию о многоугольнике в поток
	 * @param os - Поток вывода
	 */
	virtual void ToString(std::ostream& os) = 0;

	/**
	 * @brief Виртуальный деструктор класса Polygon
	 */
	virtual ~Polygon() = default;
};