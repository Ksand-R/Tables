#pragma once
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
