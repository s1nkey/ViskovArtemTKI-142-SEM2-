#include "../header/Hexagon.h"
#include "../header/Point.h"

/**
 * @brief Считывает допустимую погрешность и устанавливает её для класса Hexagon
 */
void getEpsilon();

/**
* @param countPoint - количество точек шестиугольника
*/
enum C
{
	countPoint = 6
};

/**
 * @brief Точка входа в программу
 * @return 0 или 1, в зависимости от корректности выполнения
 */
int main()
{
	try
	{
		getEpsilon();
		std::cout << std::endl;

		std::cout << "Введите 12 координат с указанной выше точностью:" << std::endl;

		Point points[countPoint];
		std::string numbers[countPoint] = { "первой", "второй", "третьей" , "четвёртой" , "пятой", "шестой" };
		for (size_t i = 0; i < countPoint; i++)
		{
			std::cout << " Введите координаты " << numbers[i] << " точки (x;y): ";
			std::cin >> points[i];
		}

		system("CLS");

		Hexagon First(points[0], points[1], points[2], points[3], points[4], points[5]);
		First.ToString(std::cout);
		std::cout << "Площадь: " << First.getArea() << std::endl;
		std::cout << "Периметр: " << First.getPerimetr() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Ошибка: " << e.what() << std::endl;
	}
	return 0;
}

void getEpsilon()
{
	double epsilon = std::numeric_limits<double>::epsilon();
	std::cout << "Установите допустимую точность координат (например 0.01): ";
	std::cin >> epsilon;
	if (std::cin.fail())
	{
		throw std::runtime_error("Недопустимое значение");
	}
	Hexagon::setEps(epsilon);
}
