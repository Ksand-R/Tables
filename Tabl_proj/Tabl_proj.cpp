#include "Tabl_proj.h"

Row::Row(string n, Polynomial* p) {
	name = n;
	ptr_p = new Polynomial(*p); 
	is__empty = false;
}
Row& Row::operator =(const Row& n) {
	if (this == &n) { return *this; }
	else {
		name = n.name;
		ptr_p = new Polynomial(*n.ptr_p);
		is__empty = n.is__empty;
		return *this;
	}
}
Row::Row(const Row& r)
{
	name = r.name;
	if (r.ptr_p != NULL)
		ptr_p = new Polynomial(*r.ptr_p);
	else ptr_p = NULL;
	is__empty = r.is__empty;
}
bool Row::operator==(const Row& a){
	if (this == &a) {
		return true;
}
	if(this->name == a.name)
	{
		return true;
	}
	return false;
}

Row::~Row()
{
	if (ptr_p) {
		name = "emp";
		delete ptr_p;
	}
}
ostream& operator << (ostream& os, const Row& row)
{
	os << row.name << "		"<< *(row.ptr_p);
	return os;
}
