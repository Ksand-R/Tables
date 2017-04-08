#include "Tabl_proj.h"

Row::Row(string n, Polynomial* p) {
	name = n;
	ptr_p = p;
}
Row& Row::operator =(const Row& n) {
	if (this == &n) { return *this; }
	else {
		name = n.name;
		ptr_p = n.ptr_p;
		return *this;
	}
}

ostream& operator << (ostream& os, const Row& row)
{
	os << row.name << "		"<< *(row.ptr_p);
	return os;
}

//
//Table::Table(){
//	Row* array[SIZE] = {};
//	for (int i(0); i < SIZE; ++i) {
//		(*array[i]).name = "None";
//	}
//	count_rows = 0;
//}
