#pragma once
#include <string.h>
#include "Polynomial.h"
struct Row {

	string name;
	Polynomial* ptr_p;

	Row() { name = "emp", ptr_p = NULL; }
	Row(string n, Polynomial* p);
	Row& operator =(const Row& n);


	//NodeT& operator[](int i) {
	//}
	/*void find_node(string name_) {

	}*/
};

//class TT {
//private:
//	Row array[10]; // dinam;
//	virtual !
//		forms;
//	hash with open adress;
//	[] in base
//};
//


class Table {
public:
	virtual void insert(string name, Polynomial* p) = 0;
	virtual void remove(string name) = 0;
	virtual int search(string name) = 0;
	virtual void repacking() = 0;
	void print_table() {
		//write in three files, row to row
		//or in three consoles
	}
};
