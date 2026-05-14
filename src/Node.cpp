#include "../header/Node.h"

Node::Node(const int data, Node* const next)
{
	this->data = data;
	this->next = next;
}

int Node::getData() const
{
	return data;
}

void Node::setData(const int data)
{
	this->data = data;
}

Node* Node::getNext() const
{
	return next;
}

void Node::setNext(Node* const next)
{
	this->next = next;
}
