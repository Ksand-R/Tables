#pragma once	
#include "viewed.h"
#include <stdexcept>
using namespace std;

viewed_tables::viewed_tables() {
	
	array = new Row[size];
	filled_rows = 0;	
}

viewed_tables::~viewed_tables() {
	delete[] array;

	filled_rows = 0;
}

void viewed_tables::insert(const Row& r){
	
	if (filled_rows == 0) {
		array[0] = r;
		array[0].is__empty = false;
		filled_rows++;
	}
	else {
		bool same_name = false;
		for (int i(0); i < filled_rows; ++i) {
			if (r.name == array[i].name) {
				same_name = true;
				throw std::logic_error(" This name is already exists "); // dont works
				cout << " Input error "; // dont works
			}
		}
		if (same_name == false){
			if (filled_rows < size)
			{
				array[filled_rows] = r;
				array[filled_rows].is__empty = false;
				filled_rows++;

			}
			else {
			Row* tmp = new Row[size + 10];
			for (int i = 0; i < size + 10; i++) {
				tmp[i].ptr_p = new Polynomial;
				tmp[i].name = "emp";
				tmp[i].is__empty = true;
			}
			for (int i = 0; i < size; i++)
			{
			tmp[i] = array[i];
			}
			delete[] array;
			size+= 10;

			array = tmp;

			array[filled_rows] = r;
			array[filled_rows].is__empty = false;
			filled_rows++;
			}

		}
		else {
			exit(1);
		}
	}
} 

void viewed_tables::print_table(){
	for (int i(0); i < size; ++i) {
		cout << array[i] << endl;
	}
}

void viewed_tables::remove(string name_) {
	if (filled_rows == 0) {
		throw std::logic_error(" The table is empty "); // dont works
		cout << " remove error ";
	} // dont works}
	else {
		int tmp = -1;
		for (int i(0); i < filled_rows; ++i) {
			if ((array[i]).name == name_) {
				tmp = i;
			}
			
		}
		if (tmp != -1) {
			filled_rows--;// memory leak
						  //delete array[tmp].ptr_p;
						  //(array[tmp].ptr_p)->~Polynomial();
						  //array[tmp].ptr_p = new Polynomial;

			array[tmp] = array[filled_rows];
			array[filled_rows].is__empty = true;
		
		}
		
		if(tmp == -1) {
			throw std::logic_error(" This name is not found "); // dont works
			cout << " search error "; // dont works
		}
	}
};

Row* viewed_tables::search(string name_) {
	bool is_exist = false;
	int tmp = -1;

	for (int i(0); i < filled_rows; ++i) {
		if ((array[i]).name == name_) {
			is_exist = true;
			tmp = i;
			break;
	}
	}
	if (tmp != -1) {
		return &array[tmp];
		//return *((array[tmp]).ptr_p);
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
