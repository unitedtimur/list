#pragma once

#include <iostream>

using namespace std;

class node
{
public:

	node(int Val = 0, node* Prev = nullptr, node* Next = nullptr, node* ptrForThis = nullptr, bool toTheEnd = true);

	node(const node& object);

	int get_value();

	node* get_next();

	node* get_previous();

	void set_value(int Value);

	void set_next(node* Next);

	void set_previous(node* Previous);

	node & operator=(const node& object);

private:
	int value;
	node * next, *previous;
};