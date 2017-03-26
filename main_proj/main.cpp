#include <iostream>
#include "Monom.h"
#include "Polynomial.h"
#include "Tabl_proj.h"
#include "viewed.h"
using namespace std;

int main() {


	Polynomial P1;
	Polynomial P2;
	P1.Input_poly();
	P2 = P1;
	Row R1("abc", &P1);
	Row R2("bcd", &P2);
	//viewed_tables a();???????????????????????
	//a.insert(&R1);
	//a.insert(&R2);
	//a.print_table();
	

	cout << "I'm alive yet" << endl;

	return 0;
}
