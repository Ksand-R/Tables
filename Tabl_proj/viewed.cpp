#pragma once	
#include "viewed.h"
#include <stdexcept>
using namespace std;

viewed_tables::viewed_tables() {
	Row* array = new Row[5];
	for(int i(0); i < size; i++){
// cant alloc memory for the fields of struct Row
		(array[i]).is__empty = true;
		(array[i]).ptr_p = NULL;
		(array[i]).name = "emp";
	}
	filled_rows = 0;
}

viewed_tables::~viewed_tables() {
	delete[] array;
	filled_rows = 0;
}

void viewed_tables::insert(const Row& r){
	bool same_name = false;
	for (int i(0); i < filled_rows; ++i) {
		if (r.name == (*array[i]).name) {
			same_name = true;
			throw std::logic_error(" This name is already exists ");
			cout << " Input error ";
		}
	}
	if (same_name == false) {
		filled_rows++;
	
	if (filled_rows < size)
	{
		*array[filled_rows] = r;
	}
	else {
		size = size + 10 + ((int)0.3*filled_rows);
		realloc(array, sizeof(size));
		*array[filled_rows] = r;
	}	
	}
	else {
		exit(1);
	}
} //print into console!
void viewed_tables::print_table(){
	for (int i(0); i < filled_rows; ++i) {
		cout << array[i] << endl;
	}
}

void viewed_tables::remove(string name_) {

	int tmp = -1;
	for (int i(0); i < filled_rows; ++i) {
		if ((*array[i]).name == name_){
			tmp = i;
		}
		if (tmp != -1) {
			delete array[tmp];
			array[tmp] = array[filled_rows];
			delete array[filled_rows];
			filled_rows--;
	}
	}
};

Polynomial viewed_tables::search(string name_) {
	bool is_exist = false;
	int tmp = -1;

	for (int i(0); i < filled_rows; ++i) {
		if ((*array[i]).name == name_) {
			is_exist = true;
			tmp = i;
	}
	}
	if (tmp != -1) {
		return *((*array[tmp]).ptr_p);
	}
	else {
		throw std::logic_error(" This row is not found ");

	}
}

ostream& operator << (ostream& os, const viewed_tables& t) {
	for (int i(0); i < t.size; ++i) {
		os << t.array[i] << endl;
		return os;
	}
}
