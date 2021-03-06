#pragma once
#include "Tabl_proj.h"

class sorted_t : public Table {
private:
	int size = 15;
	int curr_pos;
	Row* array;

public:
	sorted_t();
	~sorted_t();
	void print_table(); //+-
	void insert(const Row& r); //+-
	void remove(string name); // -
	Row* search(string name) { return NULL; }
	int binsearch(string name); //+-
	void repacking();
	inline int get_curr_pos(){return curr_pos;}
	Row& operator [](const int i) { return array[i]; } //+-
	friend ostream& operator << (ostream& os, const sorted_t& t);
};