/*
*
* by UnitedTimur (c) 2018
*
*/

#include "Node.h"

node::node(int Val, node * Prev, node * Next, node * ptrForThis, bool toTheEnd) : value(Val), previous(Prev), next(Next)
{
	if (ptrForThis != nullptr)
	{
		(toTheEnd ? ptrForThis->next : ptrForThis->previous) = this;
	}
}

node::node(const node& tmp)
{
	if (this != &tmp)
	{
		value = tmp.value;
		next = tmp.next;
		previous = tmp.previous;
	}
}

node& node::operator=(const node & tmp)
{
	if (this != &tmp)
	{
		value = tmp.value;
		next = tmp.next;
		previous = tmp.previous;
	}
	return *this;
}

int node::get_value()
{
	return value;
}

node * node::get_next()
{
	return next;
}

node * node::get_previous()
{
	return previous;
}

void node::set_value(int value)
{
	this->value = value;
}

void node::set_next(node* next)
{
	this->next = next;
}

void node::set_previous(node * previous)
{
	this->previous = previous;
}
