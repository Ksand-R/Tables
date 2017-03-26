#pragma once
#include "Tabl_proj.h"

class viewed_tables : public Table {
private:
	Row* array[SIZE] = {};

public:
	viewed_tables();
	void print_table();
	void insert(Row* r);
	void remove(string name);
	int search(string name);
	void repacking();

	Row& operator [](const int i) { return *(array[i]); }

	friend ostream& operator << (ostream& os, const viewed_tables& t) {
		for (int i(0); i < t.count_rows; ++i) {
			os << t.array[i] << endl; //?????????????????
				//t.array[i]->ptr_p->Print_poly() << endl;
			return os;
		}
	}
	
};




