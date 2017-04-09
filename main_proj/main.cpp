#include <iostream>
#include "Monom.h"
//#include "Polynomial.h"
#include "Tabl_proj.h"
#include "viewed.h"
#include "sorted_t.h"
#include "../Polynomials/Polynomial.h"
using namespace std;

int main() {

	Polynomial P2;
	P2.Input_poly();
	
		Row R1("abc", &P2);
		Row R2("acd", &P2);
		Row R3("accd", &P2);
		Row R4("adcd", &P2);
		Row R5("ascd", &P2);
		Row R6("aacd", &P2);
		Row R7("aafd", &P2);



		//cout << endl << endl;
		//viewed_tables a;
		//a.insert(R1);
		//a.insert(R2);
		//a.insert(R3);
		//a.insert(R4);
		//a.insert(R5);
		//a.insert(R6);
		//a.insert(R7);
		//a.remove("acd");
		//a.remove("accd");
		//a.remove("adcd");
		//a.remove("ascd");
		//a.remove("aacd");

		////a.print_table();
		////cout << a.search("aafd") << endl;

		////cout << "I'm alive yet" << endl;
		//a.remove("aafd");
		///*cout << endl;
		//a.print_table();*/
		//cout << "I'm alive yet" << endl;

		sorted_t A;
		A.insert(R1);
		A.insert(R2);
		A.insert(R3);
		A.insert(R4);
		A.insert(R5);
		A.insert(R6);
		A.insert(R7);

		A.print_table();

	return 0;
}
