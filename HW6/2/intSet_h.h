#pragma once
#include<iostream>
#include<iterator>
#include<set>
using namespace std;
class intSet {
	set<int> a;
public:
	intSet() {}
	intSet(set<int> temp) {
		for (int i = 0; i < temp.size; i++)
			a.insert(*temp.begin());
		temp.erase(temp.begin());
	}

	set<int> operator+(const intSet& b);
	set<int> operator-(const intSet& b);
	set<int> operator&(const intSet& b);
	void printSet();
	void insert(int number);
};
