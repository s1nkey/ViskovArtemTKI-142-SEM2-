#pragma once

/**
 * @brief Класс Node - узел циклического односвязного списка
 */
class Node
{
private:
	int data;
	Node* next;

public:
	/**
	 * @brief Конструктор, создающий узел списка
	 * @param data - значение узла
	 * @param next - указатель на следующий узел
	 */
	Node(const int data = 0, Node* const next = nullptr);

	/**
	 * @brief Возвращает значение узла
	 * @return Значение узла
	 */
	int getData() const;

	/**
	 * @brief Устанавливает значение узла
	 * @param data - новое значение узла
	 */
	void setData(const int data);

	/**
	 * @brief Возвращает указатель на следующий узел
	 * @return Указатель на следующий узел
	 */
	Node* getNext() const;

	/**
	 * @brief Устанавливает указатель на следующий узел
	 * @param next - указатель на следующий узел
	 */
	void setNext(Node* const next);
};
