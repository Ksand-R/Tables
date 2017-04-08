#pragma once
#include <iostream>
#include <cstdio>
#include <limits>
#include "Monom.h"
using namespace std;

class Polynomial {
private:
	Monom* head;
	Monom* tail;
	int size; // counter of amount of monoms

public:
	Polynomial();
	Polynomial(const Polynomial& p);
	void Input_poly();
	void bubble_sort();
	void swap_(Monom* m1, Monom* m2);
	void add_monom_in_tail(Monom* m);
	void del_monom(Monom *ptr2);
	const Polynomial& operator = (const Polynomial &p);
	Polynomial operator + (Polynomial p);
	Polynomial operator - (Polynomial m);
	Polynomial operator * (double d);
	Polynomial operator * (Monom m);
	Polynomial operator * (Polynomial m);
	void Print_poly();
	void bring_similar();
	bool operator==(const Polynomial& rhs) const;
	~Polynomial();
	friend ostream& operator << (ostream& os, const Polynomial& p);
};
