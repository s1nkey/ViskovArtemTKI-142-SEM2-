#include <gtest/gtest.h>

#include "../header/Point.h"
#include "../header/Vector.h"
#include "../header/Hexagon.h"

/**
 * @brief Проверяет конструктор точки и методы получения координат
 */
TEST(PointTest, Constructor_And_Getters)
{
	Point p(3.5, -2.1);

	EXPECT_DOUBLE_EQ(p.getX(), 3.5);
	EXPECT_DOUBLE_EQ(p.getY(), -2.1);
}

/**
 * @brief Проверяет конструктор копирования точки
 */
TEST(PointTest, Copy_Constructor)
{
	Point p1(1.2, 4.8);
	Point p2(p1);

	EXPECT_DOUBLE_EQ(p2.getX(), 1.2);
	EXPECT_DOUBLE_EQ(p2.getY(), 4.8);
}

/**
 * @brief Проверяет оператор присваивания точки
 */
TEST(PointTest, Assignment_Operator)
{
	Point p1(7.0, -3.0);
	Point p2;

	p2 = p1;

	EXPECT_DOUBLE_EQ(p2.getX(), 7.0);
	EXPECT_DOUBLE_EQ(p2.getY(), -3.0);
}

/**
 * @brief Проверяет оператор равенства точек
 */
TEST(PointTest, Equality_Operator)
{
	Point p1(2.0, 5.0);
	Point p2(2.0, 5.0);
	Point p3(2.0, 5.1);

	EXPECT_TRUE(p1 == p2);
	EXPECT_FALSE(p1 == p3);
}

/**
 * @brief Проверяет оператор неравенства точек
 */
TEST(PointTest, Inequality_Operator)
{
	Point p1(2.0, 5.0);
	Point p2(2.0, 5.0);
	Point p3(1.0, 5.0);

	EXPECT_FALSE(p1 != p2);
	EXPECT_TRUE(p1 != p3);
}

/**
 * @brief Проверяет оператор вывода точки в поток
 */
TEST(PointTest, Output_Operator)
{
	Point p(1.5, -2.5);
	std::ostringstream os;

	os << p;

	EXPECT_EQ(os.str(), "(1.5; -2.5)");
}

/**
 * @brief Проверяет оператор ввода точки из потока
 */
TEST(PointTest, Input_Operator)
{
	Point p;
	std::istringstream is("3.25 -4.75");

	is >> p;

	EXPECT_DOUBLE_EQ(p.getX(), 3.25);
	EXPECT_DOUBLE_EQ(p.getY(), -4.75);
}

/**
 * @brief Проверяет обработку некорректного ввода точки
 */
TEST(PointTest, Input_Operator_Invalid_Data)
{
	Point p;
	std::istringstream is("abc def");

	EXPECT_THROW(is >> p, std::runtime_error);
}

/**
 * @brief Проверяет вычисление длины вектора
 */
TEST(VectorTest, Length)
{
	Point A(0.0, 0.0);
	Point B(3.0, 4.0);
	Vector v(A, B);

	EXPECT_DOUBLE_EQ(v.getLen(), 5.0);
}

/**
 * @brief Проверяет вычисление площади и периметра правильного шестиугольника
 */
TEST(HexagonTest, Area_And_Perimeter)
{
	Hexagon::setEps(0.01);

	Point A(1.0, 0.0);
	Point B(0.5, 0.866025);
	Point C(-0.5, 0.866025);
	Point D(-1.0, 0.0);
	Point E(-0.5, -0.866025);
	Point F(0.5, -0.866025);

	Hexagon h(A, B, C, D, E, F);

	EXPECT_NEAR(h.getPerimetr(), 6.0, 1e-2);
	EXPECT_NEAR(h.getArea(), 2.598, 1e-2);
}

/**
 * @brief Проверяет установку корректного значения погрешности
 */
TEST(HexagonTest, SetEps_Correct_Value)
{
	EXPECT_NO_THROW(Hexagon::setEps(0.1));
	EXPECT_NO_THROW(Hexagon::setEps(0.01));
}

/**
 * @brief Проверяет обработку некорректного значения погрешности
 */
TEST(HexagonTest, SetEps_Incorrect_Value)
{
	EXPECT_THROW(Hexagon::setEps(0.0), std::runtime_error);
	EXPECT_THROW(Hexagon::setEps(-0.5), std::runtime_error);
	EXPECT_THROW(Hexagon::setEps(1.5), std::runtime_error);
}

/**
 * @brief Проверяет вывод информации о правильном шестиугольнике в поток
 */
TEST(HexagonTest, ToString_Output)
{
	Hexagon::setEps(0.01);

	Point A(1.0, 0.0);
	Point B(0.5, 0.866);
	Point C(-0.5, 0.866);
	Point D(-1.0, 0.0);
	Point E(-0.5, -0.866);
	Point F(0.5, -0.866);

	Hexagon h(A, B, C, D, E, F);

	std::ostringstream os;
	h.ToString(os);

	std::string result = os.str();

	EXPECT_NE(result.find("Фигура: Правильный-Шестиугольник"), std::string::npos);
	EXPECT_NE(result.find("Точка A"), std::string::npos);
	EXPECT_NE(result.find("Точка F"), std::string::npos);
	EXPECT_NE(result.find("Длинна между точками"), std::string::npos);
}
