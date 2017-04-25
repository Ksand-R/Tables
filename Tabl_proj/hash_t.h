#pragma once

#include "Tabl_proj.h"
#include <list>

class hash_t : public Table {
private:
	#define SIZE 15
	list<Row>** array;
public:
	hash_t();
	~hash_t();
	unsigned int MurmurHash2(const char * key, unsigned int len);
	Polynomial* find_row(string r);
	void insert(const Row& r);
	void remove(string name);
	Row* search(string name) {
		return new Row;
		//There is no reason to return 
		//index of row, see find_row function
	}
	void repacking() {}
	void print_table();

};