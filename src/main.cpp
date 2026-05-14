#include <cstdlib>
#include <iostream>

#include "../header/CircularList.h"

/**
 * @brief Точка входа в программу
 * @return 0 или 1, в зависимости от корректности выполнения
 */
int main()
{
	system("chcp 1251");

	try
	{
		CircularList list{ 1, 2, 3 };

		std::cout << "Исходный список: " << list.ToString() << std::endl;

		list.pushBack(4);
		list.removeValue(2);
		list.change(3, 30);

		std::cout << "Итоговый список: " << list.ToString() << std::endl;
	}
	catch (const std::exception& error)
	{
		std::cerr << "Ошибка: " << error.what() << std::endl;
	}

	return 0;
}
