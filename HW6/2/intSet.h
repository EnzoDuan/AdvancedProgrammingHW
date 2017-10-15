#pragma once
#include "intSet_h.h"
void intSet::printSet()
{
	for (set<int>::iterator i = a.begin(); i != a.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void intSet::insert(int number) {
	a.insert(number);
}
set<int> intSet::operator+(const intSet& b)
{
	set<int> c;
	c = b.a;
	for (set<int>::iterator i = a.begin(); i != a.end(); i++)
		c.insert(*i);
	return c;
}
set<int> intSet::operator-(const intSet& b)
{
	set<int> c;
	c = a;
	for (set<int>::iterator i = b.a.begin(); i != b.a.end(); i++)
	{
		if (c.find(*i) != c.end())
			c.erase(*i);
	}
	return c;
}
set<int> intSet::operator&(const intSet& b)
{
	set<int> c, d;
	c = a;
	for (set<int>::iterator i = b.a.begin(); i != b.a.end(); i++)
	{
		if (c.find(*i) != c.end())
			d.insert(*i);
	}
	return d;
}