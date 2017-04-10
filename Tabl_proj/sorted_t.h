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
	int search(string name); //+-
	void repacking() {
	
		for (int i(0); i < curr_pos; ++i) {
			if (array[i].is__empty) {
				for (int j(i); j < curr_pos; ++j) {
					array[j] = array[j+1];
				}
				
				array[curr_pos] = Row("cleaned", new Polynomial);
				curr_pos--;
				
			}
			
	}




	}; //
	void realloc_() {}; //
	int get_curr_pos(){
		return curr_pos;
	}
	Row& operator [](const int i) { return array[i]; } //+-
	friend ostream& operator << (ostream& os, const sorted_t& t);
};