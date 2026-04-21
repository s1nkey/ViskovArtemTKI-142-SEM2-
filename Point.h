#pragma once
#include <iostream>

/**
 * @brief Класс Point - точка на плоскости
 */
class Point
{
private:
	double x;
	double y;

	/**
	 * @brief Выбрасывает исключение
	 * @param text - Текст ошибки
	 */
	void error(std::string text);
public:
	/**
	 * @brief Конструктор, создающий точку по заданными координатами
	 * @param x - Координата по оси X
	 * @param y - Координата по оси Y
	 */
	Point(const double x = 0, const double y = 0);

	/**
	 * @brief Конструктор копирования
	 * @param other - Точка, из которой копируются координаты
	 */
	Point(const Point& other);

	/**
	 * @brief Возвращает координату точки по оси X
	 * @return Значение координаты X
	 */
	double getX();

	/**
	 * @brief Возвращает координату точки по оси Y
	 * @return Значение координаты Y
	 */
	double getY();

	/**
	 * @brief Оператор присваивания координат другой точки
	 * @param other - Точка, значения которой присваиваются текущей точке
	 */
	void operator = (const Point& other);

	/**
	 * @brief Проверяет равенство двух точек
	 * @param other - Точка для сравнения
	 * @return true, если точки равны, иначе false
	 */
	bool operator == (const Point other) const;

	/**
	 * @brief Проверяет неравенство двух точек
	 * @param other - Точка для сравнения
	 * @return true, если точки не равны, иначе false
	 */
	bool operator != (const Point other) const;

	/**
	 * @brief Выводит координаты точки в поток
	 * @param os Поток вывода
	 * @param point Точка для вывода
	 * @return Ссылка на поток вывода
	 */
	friend std::ostream& operator << (std::ostream& os, const Point& point);

	/**
	 * @brief Считывает координаты точки из потока
	 * @param is - Поток ввода
	 * @param point - Точка, в которую считываются координаты
	 * @return Ссылка на поток ввода
	 */
	friend std::istream& operator >> (std::istream& is, Point& point);
};