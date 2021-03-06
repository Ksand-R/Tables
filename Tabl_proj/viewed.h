#pragma once
#include "Tabl_proj.h"

class viewed_tables: public Table {
private:
	int size = 5;
	Row* array;
public:
	viewed_tables(); //+-
	~viewed_tables();									
	void print_table(); //+-
	void insert(const Row& r); //+-
	void remove(string name); // -
	Row* search(string name); //+-
	void repacking() {}; //
	Row& operator [](const int i) { return array[i]; } //+-
	friend ostream& operator << (ostream& os, const viewed_tables& t); //+
	
};
