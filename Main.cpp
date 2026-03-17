
#include "Class Right Triangle.h"

/**
* @brief Считывает значение введённое с клавиатуры
* @return Значение введённое с клавиатуры, если оно считано правильно
*/
const double GetSide(void);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
*/
int main(void)
{
	system("chcp 1251");
	system("CLS");

	cout << "Введите первую сторону треугольника: ";
	const double side_one = GetSide();

	cout << "Введите вторую сторону треугольника: ";
	const double side_two = GetSide();

	RightTriangle A(side_one, side_two);

	cout << "Радиус описанной окружности: " << A.RadiusCircle() <<
		endl << "Площадь описанной окружности: " << A.AreaCircle() <<
		endl;

	return 0;
}

const double GetSide(void)
{
	double number = 0;
	cin >> number;
	if (cin.fail())
	{
		cout << "Ошибка ввода!";
		exit(1);
	}
	return number;
}
