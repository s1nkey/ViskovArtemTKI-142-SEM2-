#pragma once
#include "../header/Polygon.h"
#include "../header/Point.h"

/**
 * @brief Класс Hexagon - правильный шестиугольник
 */
class Hexagon : public Polygon
{
private:
	/**
	 * @brief Точки, задающие вершины правильного шестиугольника
	 */
	Point A, B, C, D, E, F;

	/**
	 * @brief Допустимая погрешность при проверке шестиугольника
	 */
	static double eps;

	/**
	 * @brief Выбрасывает исключение
	 * @param text - Текст ошибки
	 */
	void error(std::string text);

	/**
	 * @brief Проверяет, образуют ли точки правильный шестиугольник
	 */
	void thisHexagon();

	/**
	 * @brief Округляет значение с учётом установленной точности
	 * @param value - Значение для округления
	 * @return Округлённое значение
	 */
	double fixValue(double value);
public:
	/**
	 * @brief Конструктор, создающий правильный шестиугольник по шести точкам
	 * @param A - Первая точка
	 * @param B - Вторая точка
	 * @param C - Третья точка
	 * @param D - Четвёртая точка
	 * @param E - Пятая точка
	 * @param F - Шестая точка
	 */
	Hexagon(const Point A, const Point B, const Point C, const Point D, const Point E, const Point F);

	/**
	 * @brief Устанавливает допустимую погрешность
	 * @param value - Значение погрешности
	 */
	static void setEps(double value);

	/**
	 * @brief Вычисляет площадь правильного шестиугольника
	 * @return Площадь правильного шестиугольника
	 */
	double getArea() override;

	/**
	 * @brief Вычисляет периметр правильного шестиугольника
	 * @return Периметр правильного шестиугольника
	 */
	double getPerimetr() override;

	/**
	 * @brief Выводит информацию о правильном шестиугольнике в поток
	 * @param os - Поток вывода
	 */
	void ToString(std::ostream& os) override;
};
