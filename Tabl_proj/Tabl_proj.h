#pragma once
#include <string.h>
#include "Polynomial.h"
class Row {
public:
	string name;
	Polynomial* ptr_p;

	Row() { name = "emp", ptr_p = NULL; }
	Row(string n, Polynomial* p);
	Row& operator =(const Row& n);

	friend ostream& operator << (ostream& os, Row& row)
	{
		os << row.name;
		//cout << row.ptr_p->Print_poly() << endl;
		return os;
	}
	
};




class Table {
#define SIZE 15	

public: 
	//Row* array[SIZE] = {};
	//Table(){};
	int count_rows;
	
	//Row& operator [](const int i) {	return *(array[i]);}

	virtual void insert(Row* r) = 0;
	virtual void remove(string name) = 0;
	virtual int search(string name) = 0;
	virtual void repacking() = 0;
	virtual void print_table() = 0;

	/*friend ostream& operator << (ostream& os, Table& t){
		for (int i(0); i < t.count_rows; ++i) {
			cout << t.array[i]->name << "	" <<
				t.array[i]->ptr_p->Print_poly() << endl;
		}
	}*/
};
