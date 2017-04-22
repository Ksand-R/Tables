#include <iostream>
#include "Monom.h"
#include "Tabl_proj.h"
#include "viewed.h"
#include "sorted_t.h"
#include "Polynomial.h"
#include "hash_t.h"
#include "btree.h"
using namespace std;

int main() {


	
	


	//	cout << endl << endl;
	//	for (int i(0); i < 1000000; ++i) {
	//		viewed_tables a;
	//		a.insert(R1);
	//		a.insert(R2);
	//		a.insert(R3);
	//		a.insert(R4);
	//		a.insert(R5);
	//		a.insert(R6);
	//		a.insert(R7);
	//		//a.print_table();

	//		a.remove("acd");
	//		a.remove("accd");
	//		a.remove("adcd");
	//		a.remove("ascd");
	//		a.remove("aacd");

			//a.print_table();
			//cout << a.search("aafd") << endl;

			//cout << "I'm alive yet" << endl;
			//a.remove("aafd");
			//a.print_table();
			//cout << "I'm alive yet" << endl;
		//}

		//for (int i(0); i < 100000; ++i) {
		//	sorted_t A;
		//	A.insert(R1);
		//	A.insert(R2);
		//	A.insert(R3);
		//	A.insert(R4);
		//	A.insert(R5);
		//	A.insert(R6);
		//	A.insert(R7);
		//	//cout << "__________________" << endl;
		//	//A.print_table();
		//	//cout << "__________________" << endl;
		//	A.remove("acd");
		//	A.remove("ascd");
		//	A.remove("aafd");
		//	//A.print_table();
		//	//cout << "I'm alive" << A.get_curr_pos() << endl;
		//	A.repacking();
		//	//A.print_table();
		//	//cout << "I'm alive" << A.get_curr_pos() << endl;
		//}

	Polynomial P2;
	//P2.Input_poly();
	P2.add_monom_in_tail(new Monom(2.3, 101010));
	P2.add_monom_in_tail(new Monom(4.3, 201010));
	Row R1("abc", &P2);
	Row R2("acd", &P2);
	Row R3("accd", &P2);
	Row R4("adcd", &P2);
	Row R5("ascd", &P2);
	Row R6("aacd", &P2);
	Row R7("aafd", &P2);

	Node_tree nt(&R1);
	
	cout << nt << endl;


	//for (int i(0); i < 10; ++i) {
	/*	hash_t H;
		H.insert(R1);
		H.insert(R2);
		H.insert(R3);
		H.insert(R4);
		H.insert(R5);
		H.insert(R6);
		H.insert(R7);
		H.print_table();
		H.remove(R2.name);
		H.print_table();
*/
	//}


	return 0;
}
