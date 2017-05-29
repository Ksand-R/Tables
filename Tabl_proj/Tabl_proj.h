#pragma once
#include <string>
#include <cstdlib>
#include "Polynomial.h"


using namespace std;

struct Row {
public:
	string name;
	Polynomial* ptr_p;
	bool is__empty;

	inline Row() { name = "emp", ptr_p = nullptr; is__empty = true; }
	Row(string n, Polynomial* p);
	Row& operator =(const Row& n);
	Row(const Row& r);
	bool operator==(const Row& r);
	friend ostream& operator << (ostream& os, const Row& row);
	~Row();
};


class Table {

public: 
	int filled_rows;

	virtual void insert(const Row& r) = 0;
	virtual void remove(string name) = 0;
	virtual Row* search(string name) = 0;
	virtual void print_table() = 0;
};
              