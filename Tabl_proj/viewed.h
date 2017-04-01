#pragma once
#include "Tabl_proj.h"

class viewed_tables: public Table {
private:
	int size = 5;
	Row* array[5];
public:
	viewed_tables(); //+-
	~viewed_tables();
	void print_table(); //+-
	void insert(const Row& r); //+-
	void remove(string name); // -
	Polynomial search(string name); //+-
	void repacking() {}; //
	void realloc_() {}; //
	Row& operator [](const int i) { return *(array[i]); } //+-

	friend ostream& operator << (ostream& os, const viewed_tables& t); //+

};
