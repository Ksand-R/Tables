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
	unsigned int MurmurHash2(char * key, unsigned int len);
	Polynomial* find_ptr(string r){}
	void insert(const Row& r){}
	void remove(string name){}
	int search(string name) { return 0; }
	void repacking(){}
	void print_table() {}

};