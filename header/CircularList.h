#pragma once

#include <cstddef>
#include <initializer_list>
#include <string>

#include "../header/Node.h"

/**
 * @brief Класс CircularList - циклический односвязный список целых чисел
 */
class CircularList
{
private:
	Node* head;
	size_t size;

	/**
	 * @brief Выбрасывает исключение
	 * @param text - текст ошибки
	 */
	void error(const std::string& text) const;

	/**
	 * @brief Возвращает узел по индексу
	 * @param index - индекс элемента
	 * @return Указатель на узел
	 */
	Node* getNodeAt(const size_t index) const;

	/**
	 * @brief Возвращает последний узел списка
	 * @return Указатель на последний узел
	 */
	Node* getLast() const;

	/**
	 * @brief Копирует элементы из другого списка
	 * @param other - список для копирования
	 */
	void copyList(const CircularList& other);

public:
	/**
	 * @brief Конструктор, создающий пустой список
	 */
	CircularList();

	/**
	 * @brief Конструктор, создающий список из набора значений
	 * @param values - набор значений
	 */
	CircularList(const std::initializer_list<int> values);

	/**
	 * @brief Конструктор копирования
	 * @param other - список, из которого копируются элементы
	 */
	CircularList(const CircularList& other);

	/**
	 * @brief Конструктор перемещения
	 * @param other - список, из которого перемещаются элементы
	 */
	CircularList(CircularList&& other) noexcept;

	/**
	 * @brief Деструктор
	 */
	~CircularList();

	/**
	 * @brief Оператор присваивания
	 * @param other - список для копирования
	 * @return Ссылка на текущий список
	 */
	CircularList& operator = (const CircularList& other);

	/**
	 * @brief Оператор перемещающего присваивания
	 * @param other - список для перемещения
	 * @return Ссылка на текущий список
	 */
	CircularList& operator = (CircularList&& other) noexcept;

	/**
	 * @brief Выполняет циклический сдвиг влево
	 * @param count - количество сдвигов
	 * @return Ссылка на текущий список
	 */
	CircularList& operator <<= (const size_t count);

	/**
	 * @brief Выполняет циклический сдвиг вправо
	 * @param count - количество сдвигов
	 * @return Ссылка на текущий список
	 */
	CircularList& operator >>= (const size_t count);

	/**
	 * @brief Возвращает список со сдвигом влево
	 * @param count - количество сдвигов
	 * @return Новый список
	 */
	CircularList operator << (const size_t count) const;

	/**
	 * @brief Возвращает список со сдвигом вправо
	 * @param count - количество сдвигов
	 * @return Новый список
	 */
	CircularList operator >> (const size_t count) const;

	/**
	 * @brief Добавляет элемент в начало списка
	 * @param value - значение элемента
	 */
	void pushFront(const int value);

	/**
	 * @brief Добавляет элемент в конец списка
	 * @param value - значение элемента
	 */
	void pushBack(const int value);

	/**
	 * @brief Вставляет элемент по индексу
	 * @param index - индекс вставки
	 * @param value - значение элемента
	 */
	void insertAt(const size_t index, const int value);

	/**
	 * @brief Удаляет элемент по индексу
	 * @param index - индекс элемента
	 */
	void removeAt(const size_t index);

	/**
	 * @brief Удаляет первый элемент с заданным значением
	 * @param value - значение для удаления
	 * @return true если элемент удален, иначе false
	 */
	bool removeValue(const int value);

	/**
	 * @brief Ищет элемент по значению
	 * @param value - значение для поиска
	 * @return Индекс элемента или -1
	 */
	int find(const int value) const;

	/**
	 * @brief Изменяет первый элемент с заданным значением
	 * @param oldValue - старое значение
	 * @param newValue - новое значение
	 * @return true если элемент изменен, иначе false
	 */
	bool change(const int oldValue, const int newValue);

	/**
	 * @brief Возвращает значение элемента по индексу
	 * @param index - индекс элемента
	 * @return Значение элемента
	 */
	int getAt(const size_t index) const;

	/**
	 * @brief Устанавливает значение элемента по индексу
	 * @param index - индекс элемента
	 * @param value - новое значение элемента
	 */
	void setAt(const size_t index, const int value);

	/**
	 * @brief Возвращает количество элементов
	 * @return Количество элементов
	 */
	size_t getSize() const;

	/**
	 * @brief Проверяет список на пустоту
	 * @return true если список пуст, иначе false
	 */
	bool isEmpty() const;

	/**
	 * @brief Очищает список
	 */
	void clear();

	/**
	 * @brief Возвращает список в виде строки
	 * @return Строка со значениями списка
	 */
	std::string ToString() const;
};
