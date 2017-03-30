#pragma once
#include "viewed.h"
#include <stdexcept>
using namespace std;

viewed_tables::viewed_tables() {
	array = new Row[SIZE];
	count_rows = 0;
	filled_rows = 0;

	for (int i(0); i < SIZE; ++i) {
		array[i].is__empty = true;
	}
}

void viewed_tables::insert(const Row& r){
	bool same_name = false;
	for (int i(0); i < count_rows; ++i) {
		if (r.name == array[i].name) {
			same_name = true;
			throw std::logic_error(" This name is already exists ");
		}
	}
	if (same_name == false) {
		count_rows++;
		for (int i(0); i < count_rows; ++i) {
			if (array[i].is__empty == true) {
				array[i] = r;
				filled_rows++;
				array[i].is__empty = false;
				break;
		}
		}	
	}
} //print into console!
void viewed_tables::print_table() {
	for (int i(0); i < count_rows; ++i) {
		cout << array[i] << endl;
	}
}

void viewed_tables::remove(string name_) {

	int curr = -1;
	for (int i(0); i < count_rows; ++i) {
		if (array[i].name == name_){
			curr = i;
		}
		if (curr != -1) {
			//delete array[curr];
			array[curr].is__empty = true;
	}
	}
};

void viewed_tables::repacking() {
	{
		int tmp1 = -1;
		int tmp2 = -1;
		Row buff;

		for (int i(0); i < count_rows; ++i) {
			if (!array[i].is__empty)
			{
				continue;
			}
			else
			{
				tmp1 = i;
				for (int i(count_rows); i >= tmp1; --i) {
					if (array[i].is__empty) { tmp2 = i; break; }
				}

				buff = array[tmp1];
				array[tmp1] = array[tmp2];
				array[tmp2] = buff;
			}
		}
	}
}

Polynomial* viewed_tables::search(string name_) {
	bool is_exist = false;
	int tmp = -1;

	for (int i(0); i < count_rows; ++i) {
		if (array[i].name == name_) {
			is_exist = true;
			tmp = i;
	}
	}
	if (tmp != -1) {
		return array[tmp].ptr_p;
	}
	else {
		throw std::logic_error(" This row is not found ");

	}
}

void viewed_tables::realloc_() {
	realloc(array, sizeof(SIZE+10+((int)0.3*filled_rows)));
}

ostream& operator << (ostream& os, const viewed_tables& t) {
	for (int i(0); i < t.count_rows; ++i) {
		os << t.array[i] << endl;
		return os;
	}
}
