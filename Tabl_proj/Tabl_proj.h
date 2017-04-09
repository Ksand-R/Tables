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

	Row() { name = "emp", ptr_p = NULL; }
	Row(string n, Polynomial* p);
	Row& operator =(const Row& n);
	friend ostream& operator << (ostream& os, const Row& row);
	
	
};


class Table {


public: 
	//unsigned int SIZE;
	int filled_rows;

	virtual void insert(const Row& r) = 0;
	virtual void remove(string name) = 0;
	virtual int search(string name) = 0;
	virtual void repacking() = 0;
	virtual void print_table() = 0;

	/*friend ostream& operator << (ostream& os, Table& t) {
		for (int i(0); i < t.count_rows; ++i) {
			cout << t.array[i]->name << "	" <<
				t.array[i]->ptr_p->Print_poly() << endl;
		}
	}*/
};
