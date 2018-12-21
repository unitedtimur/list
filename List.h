#pragma once

#include "Node.h"
#include <cstdarg>
#include <fstream>

class list
{
public:

	list();
	list(int num, ...);
	list(const list& object);
	~list();

	void push_front(int value);

	void push_back(int value);

	void push_key(int key, int value);

	void push_index(int index, int value);

	void pop_front();

	void pop_back();

	void pop_key(int key);

	void pop_index(int index);

	node & find(int key);

	void copy();

	void clear();

	void print();

	int size();

	void add(int num, ...);

	void del(int num, ...);

	void set(int size, int limit = 100);

	void set(int* mas, int size);

	void set(const char *name);

	list & operator=(const list& object);

	list & operator+=(const list& object);

	list & operator-=(const list& object);

	node & operator[](int index);

	list operator+(const list& object);

	list operator-(const list& object);

	friend istream & operator >> (istream & is, list &);

	friend ostream & operator << (ostream & is, list &);

private:

	int Size;
	node * head, * tail;
};