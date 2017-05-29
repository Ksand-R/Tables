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





	Polynomial P2;
	P2.add_monom_in_tail(new Monom(2.3, 101010));
	P2.add_monom_in_tail(new Monom(4.3, 201010));
	Row R1("abc", &P2);
	Row R2("acd", &P2);
	Row R3("accd", &P2);
	Row R4("adcd", &P2);
	//Row R5("ascd", &P2);
	//Row R6("aacd", &P2);
	//Row R7("aafd", &P2);


	//Row R1("abc", NULL);
	//Row R2("acd", NULL);
	//Row R3("accd", NULL);
	//Row R4("adcd", NULL);
	//Row R5("ascd", NULL);
	//Row R6("aacd", NULL);
	//Row R7("aafd", NULL);
		

		//btree btr;
		//btr.insert_(btr.root, R1);
		//btr.insert_(btr.root, R2);
		//btr.insert_(btr.root, R3);
		//btr.insert_(btr.root, R4);
		////cout << "	";
		////btr.insert2("abc", poly);
		//
		//btr.print_table(btr.root, 0);
		//cout << endl;


	//hash_t H;
	//H.insert(R1);
	//H.insert(R2);
	//H.insert(R3);
	//H.insert(R4);
	//H.insert(R5);
	//H.insert(R6);
	//H.insert(R7);
	//H.print_table();
	//H.remove(R2.name);
	//H.print_table();

	//	cout << endl << endl;
		//	viewed_tables a;
		//	a.insert(R1);
		//	a.insert(R2);
		//	a.insert(R3);
		//	a.insert(R4);
		//	a.insert(R5);
		//	a.insert(R6);
		//	a.insert(R7);
		//	//a.print_table();

		//	a.remove("acd");
		//	a.remove("accd");
		//	a.remove("adcd");
		//	a.remove("ascd");
		//	a.remove("aacd");

		//	//a.print_table();
		//	//cout << a.search("aafd") << endl;

		//	//cout << "I'm alive yet" << endl;
		//	a.remove("aafd");
		//	//a.print_table();
		//	//cout << "I'm alive yet" << endl;



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

	//Node_tree nt(&R1);
	//cout << nt << endl;

		return 0;
}
