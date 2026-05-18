#include <cstdlib>

#include <gtest/gtest.h>

#include "../header/CircularList.h"

/**
 * @brief Проверяет создание списка и вывод в строку
 */
TEST(CircularListTest, Constructor_And_ToString)
{
	CircularList list{ 1, 2, 3 };

	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(list.getSize(), 3);
	EXPECT_EQ(list.ToString(), "[1, 2, 3]");
}

/**
 * @brief Проверяет добавление элементов в список
 */
TEST(CircularListTest, Push_Front_And_Back)
{
	CircularList list;

	list.pushFront(2);
	list.pushFront(1);
	list.pushBack(3);

	EXPECT_EQ(list.ToString(), "[1, 2, 3]");
}

/**
 * @brief Проверяет вставку и удаление элементов
 */
TEST(CircularListTest, Insert_And_Remove)
{
	CircularList list{ 1, 3 };

	list.insertAt(1, 2);
	list.removeValue(3);

	EXPECT_EQ(list.ToString(), "[1, 2]");
}

/**
 * @brief Проверяет поиск и изменение элемента
 */
TEST(CircularListTest, Find_And_Change)
{
	CircularList list{ 10, 20, 30 };

	EXPECT_EQ(list.find(20), 1);
	EXPECT_TRUE(list.change(20, 25));
	EXPECT_EQ(list.ToString(), "[10, 25, 30]");
}

/**
 * @brief Проверяет циклический сдвиг списка
 */
TEST(CircularListTest, Shift_List)
{
	CircularList list{ 1, 2, 3 };

	list <<= 1;
	EXPECT_EQ(list.ToString(), "[2, 3, 1]");

	list >>= 1;
	EXPECT_EQ(list.ToString(), "[1, 2, 3]");
}

/**
 * @brief Проверяет копирование списка
 */
TEST(CircularListTest, Copy_List)
{
	CircularList first{ 1, 2, 3 };
	CircularList second(first);

	second.setAt(0, 10);

	EXPECT_EQ(first.ToString(), "[1, 2, 3]");
	EXPECT_EQ(second.ToString(), "[10, 2, 3]");
}
