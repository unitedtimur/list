/*
*
* by UnitedTimur (c) 2018
*
*/

#include "List.h"

list::list() : head(new node), tail(new node)
{
	head->set_next(tail);
	tail->set_previous(head);
	Size = 0;
}

list::list(int num, ...) :
	head(new node),
	tail(new node)
{
	head->set_next(tail);
	tail->set_previous(head);
	Size = 0;

	if (num > 0)
	{
		int value;

		va_list argptr;

		va_start(argptr, num);

		for (; num; num--)
		{
			value = va_arg(argptr, int);
			push_back(value);
		}

		va_end(argptr);
	}
}

list::list(const list& tmp) :
	head(new node),
	tail(new node)
{
	head->set_next(tail);
	tail->set_previous(head);
	Size = 0;

	*this = tmp;
}

void list::push_front(int value)
{
	head->set_next(new node(value, head, head->get_next(), head->get_next(), false)), Size++;
}

void list::push_back(int value)
{
	tail->set_previous(new node(value, tail->get_previous(), tail, tail->get_previous())), Size++;
}

void list::push_key(int key, int value)
{
	node * temp = head->get_next();

	for (; temp->get_value() != key && temp != tail; temp = temp->get_next());

	if (temp != tail)
	{
		temp->set_next(new node(value, temp, temp->get_next(), temp->get_next(), false)), Size++;
	}
	else
	{
		push_back(value);
	}
}

void list::push_index(int index, int value)
{
	node * temp = head->get_next();

	for (int i = 0; i < index && temp != tail; temp = temp->get_next(), i++);

	if (temp != tail)
	{
		temp->set_previous(new node(value, temp->get_previous(), temp, temp->get_previous())), Size++;
	}
	else
	{
		push_back(value);
	}
}

void list::pop_front()
{
	if (head->get_next() != tail)
	{
		node* temp = head->get_next();
		head->set_next(temp->get_next());
		temp->get_next()->set_previous(head);
		Size--;
		delete temp;
	}
}

void list::pop_back()
{
	if (head->get_next() != tail)
	{
		node* temp = tail->get_previous();
		tail->set_previous(temp->get_previous());
		temp->get_previous()->set_next(tail);
		Size--;
		delete temp;
	}
}

void list::pop_key(int key)
{
	node * temp = head->get_next();

	for (; temp->get_value() != key && temp != tail; temp = temp->get_next());

	if (temp != tail)
	{
		temp->get_previous()->set_next(temp->get_next());
		temp->get_next()->set_previous(temp->get_previous());
		Size--;
		delete temp;
	}
}

void list::pop_index(int index)
{
	node* temp = head->get_next();

	for (int i = 0; i != index && temp != tail; temp = temp->get_next(), i++);

	if (temp != tail)
	{
		temp->get_previous()->set_next(temp->get_next());
		temp->get_next()->set_previous(temp->get_previous());
		Size--;
		delete temp;
	}
}

node & list::find(int key)
{
	tail->set_value(0);

	node * ptr = head->get_next();

	for (; ptr->get_value() != key && ptr != tail; ptr = ptr->get_next());

	return *ptr;
}

void list::copy()
{
	node* theEnd = tail->get_previous();

	for (node* ptr = head->get_next(); ptr != theEnd->get_next(); ptr = ptr->get_next())
	{
		push_back(ptr->get_value());
	}
}

void list::clear()
{
	while (head->get_next() != tail)
		pop_back();
}

void list::print()
{
	for (node* temp = head->get_next(); temp != tail; temp = temp->get_next())
		std::cout << temp->get_value() << ' ';
}

int list::size()
{
	return Size;
}

void list::add(int num, ...)
{
	int value;
	va_list argptr;

	va_start(argptr, num);

	for (; num; num--)
	{
		value = va_arg(argptr, int);
		push_back(value);
	}

	va_end(argptr);
}

void list::del(int num, ...)
{
	int value;
	va_list argptr;

	va_start(argptr, num);

	for (; num; num--)
	{
		value = va_arg(argptr, int);
		pop_key(value);
	}

	va_end(argptr);
}

void list::set(int size, int limit)
{
	for (int i = 0; i < size; i++)
	{
		push_back((rand() % limit) * (rand() % 3 ? 1 : -1));
	}
}

void list::set(int* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		push_back(mas[i]);
	}
}

void list::set(const char * name)
{
	ifstream file(name);

	if (file.is_open())
	{
		int value;

		while (!file.eof())
		{
			file >> value;

			push_back(value);
		}
	}

	file.close();
}

list & list::operator=(const list& tmp)
{
	if (this != &tmp)
	{
		clear();

		for (node* temp = tmp.head->get_next(); temp != tmp.tail; temp = temp->get_next())
		{
			push_back(temp->get_value());
		}
	}
	return *this;
}

list & list::operator+=(const list& tmp)
{
	for (node* temp = tmp.head->get_next(); temp != tmp.tail; temp = temp->get_next())
	{
		push_back(temp->get_value());
	}

	return *this;
}

list & list::operator-=(const list& tmp)
{
	for (node* temp = tmp.head->get_next(); temp != tmp.tail; temp = temp->get_next())
	{
		pop_key(temp->get_value());
	}

	return *this;
}

node & list::operator[](int index)
{
	head->set_value(0);
	tail->set_value(0);

	node * ptr = head;

	if (index >= 0)
	{
		ptr = ptr->get_next();

		for (int i = 0; i < index && ptr != tail; ptr = ptr->get_next(), i++);
	}
	return *ptr;
}

list list::operator+(const list& tmp)
{
	list temp(*this);

	temp += tmp;

	return temp;
}

list list::operator-(const list& tmp)
{
	list temp(*this);

	temp -= tmp;

	return temp;
}

istream& operator >> (istream & os, list &tmp)
{
	int value = 0;

	os >> value;

	tmp.push_back(value);

	return os;
}

ostream& operator << (ostream & is, list &tmp)
{
	for (node* temp = tmp.head->get_next(); temp != tmp.tail; temp = temp->get_next())
	{
		is << "[" << temp->get_value() << "] ";
	}

	return is;
}

list::~list()
{
	while (head != nullptr)
	{
		tail = head;
		head = head->get_next();
		delete tail;
	}
}
