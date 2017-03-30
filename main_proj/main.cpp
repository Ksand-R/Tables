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
	Row R2("acd", &P2);
	Row R3("accd", &P2);
	//Row R4("adcd", &P2);
	//Row R5("ascd", &P2);
	//Row R6("aacd", &P2);

	cout <<endl << endl;
	viewed_tables a;

		a.insert(R1);
		a.insert(R2);
		a.insert(R3);
		//a.insert(R4);
		//a.insert(R5);
		//a.insert(R6);

		//a.remove("acd");
		//a.remove("accd");

	a.print_table();
	//
	cout << endl;
	//cout << *(a.search("acd")) << endl;

	cout << "I'm alive yet" << endl;
	a.realloc_();

	return 0;
}
