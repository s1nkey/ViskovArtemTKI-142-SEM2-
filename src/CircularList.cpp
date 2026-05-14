#include "../header/CircularList.h"

#include <stdexcept>

void CircularList::error(const std::string& text) const
{
	throw std::runtime_error(text);
}

Node* CircularList::getNodeAt(const size_t index) const
{
	if (index >= size)
	{
		error("Индекс выходит за границы списка");
	}

	Node* current = head;

	for (size_t i = 0; i < index; i++)
	{
		current = current->getNext();
	}

	return current;
}

Node* CircularList::getLast() const
{
	if (isEmpty())
	{
		return nullptr;
	}

	Node* current = head;

	while (current->getNext() != head)
	{
		current = current->getNext();
	}

	return current;
}

void CircularList::copyList(const CircularList& other)
{
	Node* current = other.head;

	for (size_t i = 0; i < other.size; i++)
	{
		pushBack(current->getData());
		current = current->getNext();
	}
}

CircularList::CircularList()
{
	head = nullptr;
	size = 0;
}

CircularList::CircularList(const std::initializer_list<int> values) : CircularList()
{
	for (const int value : values)
	{
		pushBack(value);
	}
}

CircularList::CircularList(const CircularList& other) : CircularList()
{
	copyList(other);
}

CircularList::CircularList(CircularList&& other) noexcept
{
	head = other.head;
	size = other.size;

	other.head = nullptr;
	other.size = 0;
}

CircularList::~CircularList()
{
	clear();
}

CircularList& CircularList::operator = (const CircularList& other)
{
	if (this != &other)
	{
		clear();
		copyList(other);
	}

	return *this;
}

CircularList& CircularList::operator = (CircularList&& other) noexcept
{
	if (this != &other)
	{
		clear();

		head = other.head;
		size = other.size;

		other.head = nullptr;
		other.size = 0;
	}

	return *this;
}

CircularList& CircularList::operator <<= (const size_t count)
{
	if (size > 1)
	{
		const size_t shift = count % size;

		for (size_t i = 0; i < shift; i++)
		{
			head = head->getNext();
		}
	}

	return *this;
}

CircularList& CircularList::operator >>= (const size_t count)
{
	if (size > 1)
	{
		const size_t shift = count % size;
		*this <<= size - shift;
	}

	return *this;
}

CircularList CircularList::operator << (const size_t count) const
{
	CircularList result(*this);
	result <<= count;
	return result;
}

CircularList CircularList::operator >> (const size_t count) const
{
	CircularList result(*this);
	result >>= count;
	return result;
}

void CircularList::pushFront(const int value)
{
	Node* node = new Node(value);

	if (isEmpty())
	{
		node->setNext(node);
		head = node;
	}
	else
	{
		Node* last = getLast();
		node->setNext(head);
		last->setNext(node);
		head = node;
	}

	size++;
}

void CircularList::pushBack(const int value)
{
	Node* node = new Node(value);

	if (isEmpty())
	{
		node->setNext(node);
		head = node;
	}
	else
	{
		Node* last = getLast();
		node->setNext(head);
		last->setNext(node);
	}

	size++;
}

void CircularList::insertAt(const size_t index, const int value)
{
	if (index > size)
	{
		error("Индекс выходит за границы списка");
	}

	if (index == 0)
	{
		pushFront(value);
		return;
	}

	if (index == size)
	{
		pushBack(value);
		return;
	}

	Node* previous = getNodeAt(index - 1);
	Node* node = new Node(value, previous->getNext());
	previous->setNext(node);

	size++;
}

void CircularList::removeAt(const size_t index)
{
	if (index >= size)
	{
		error("Индекс выходит за границы списка");
	}

	if (size == 1)
	{
		delete head;
		head = nullptr;
		size = 0;
		return;
	}

	Node* deleted = nullptr;

	if (index == 0)
	{
		Node* last = getLast();
		deleted = head;
		head = head->getNext();
		last->setNext(head);
	}
	else
	{
		Node* previous = getNodeAt(index - 1);
		deleted = previous->getNext();
		previous->setNext(deleted->getNext());
	}

	delete deleted;
	size--;
}

bool CircularList::removeValue(const int value)
{
	const int index = find(value);

	if (index == -1)
	{
		return false;
	}

	removeAt(static_cast<size_t>(index));
	return true;
}

int CircularList::find(const int value) const
{
	Node* current = head;

	for (size_t i = 0; i < size; i++)
	{
		if (current->getData() == value)
		{
			return static_cast<int>(i);
		}

		current = current->getNext();
	}

	return -1;
}

bool CircularList::change(const int oldValue, const int newValue)
{
	const int index = find(oldValue);

	if (index == -1)
	{
		return false;
	}

	setAt(static_cast<size_t>(index), newValue);
	return true;
}

int CircularList::getAt(const size_t index) const
{
	return getNodeAt(index)->getData();
}

void CircularList::setAt(const size_t index, const int value)
{
	getNodeAt(index)->setData(value);
}

size_t CircularList::getSize() const
{
	return size;
}

bool CircularList::isEmpty() const
{
	return size == 0;
}

void CircularList::clear()
{
	while (!isEmpty())
	{
		removeAt(0);
	}
}

std::string CircularList::ToString() const
{
	std::string result = "[";
	Node* current = head;

	for (size_t i = 0; i < size; i++)
	{
		result += std::to_string(current->getData());

		if (i + 1 < size)
		{
			result += ", ";
		}

		current = current->getNext();
	}

	result += "]";
	return result;
}
