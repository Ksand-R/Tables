#include "gtest.h"`
#include "Tabl_proj.h"
#include "Polynomial.h"
#include "Monom.h"
#include "btree.h"


TEST(TTree, can_add_R) {
	Polynomial p1;

	p1.add_monom_in_tail(new Monom(2.3, 2));
	p1.add_monom_in_tail(new Monom(2.1, 3));
	p1.add_monom_in_tail(new Monom(-2.1, 13));
	Row R1("bcd", &p1);
	Row R2("bad", &p1);
	Row R3("bbd", &p1);

	btree T;

	T.insert_(T.root,R1);
	T.insert_(T.root, R2);
	T.insert_(T.root, R3);

	ASSERT_EQ(T.root->right->row_->name, "bcd");
}


TEST(TTree, can_add_L) {
	Polynomial p1;

	p1.add_monom_in_tail(new Monom(2.3, 2));
	p1.add_monom_in_tail(new Monom(2.1, 3));
	p1.add_monom_in_tail(new Monom(-2.1, 13));
	Row R1("abc", &p1);
	Row R2("acd", &p1);
	Row R3("accd", &p1);

	btree T;

	T.insert_(T.root, R1);
	T.insert_(T.root, R2);
	T.insert_(T.root, R3);
	ASSERT_EQ(T.root->right->row_->name, "acd");
}



TEST(TTree, can_big_lft_rotale) {
	string s1 = "bbb";
	string s2 = "abb";
	string s3 = "bbf";
	string s4 = "bbc";
	string s5 = "fff";
	string s6 = "ccc";
	Polynomial p1;
	p1.add_monom_in_tail(new Monom(2.3, 2));

	Row R1(s1, &p1);
	Row R2(s2, &p1);
	Row R3(s3, &p1);
	Row R4(s4, &p1);
	Row R5(s5, &p1);
	Row R6(s6, &p1);
	btree B;
	B.insert_(B.root, R1);
	B.insert_(B.root, R2);
	B.insert_(B.root, R3);
	B.insert_(B.root, R4);
	B.insert_(B.root, R5);
	B.insert_(B.root, R6);

	cout << *(B.root) << endl;
	
	ASSERT_EQ(B.root->row_->name, "bbf");
	ASSERT_EQ(B.root->left->row_->name, "bbb");
	ASSERT_EQ(B.root->left->right->row_->name, "bbc");
}


TEST(TTree, can_print) {
	Polynomial p1;
	
		p1.add_monom_in_tail(new Monom(2.3, 2));

		Row R1("ccc", &p1);
		Row R2("bcc", &p1);
		Row R3("baa", &p1);
		Row R4("efr", &p1);
		Row R5("cdd", &p1);
		
		btree B;
		B.insert_(B.root, R1);
		B.insert_(B.root, R2);
		B.insert_(B.root, R3);
		B.insert_(B.root, R4);
		B.insert_(B.root, R5);
	
		B.print_table();
		
}
TEST(TTree, can_del_1) {
	Polynomial p1;

	p1.add_monom_in_tail(new Monom(2.3, 2));
	string s1 = "bbb";
	string s2 = "abb";
	string s3 = "bbf";
	string s4 = "bbc";
	string s5 = "fff";
	string s6 = "ccc";
	Row R1(s1, &p1);
	Row R2(s2, &p1);
	Row R3(s3, &p1);	
	Row R4(s4, &p1);
	Row R5(s5, &p1);
	Row R6(s6, &p1);
	btree B;
	B.insert_(B.root, R1);
	B.insert_(B.root, R2);
	B.insert_(B.root, R3);
	B.insert_(B.root, R4);
	B.insert_(B.root, R5);
	B.insert_(B.root, R6);

	B.remove(B.root, "bbb");
	B.print_table();
	ASSERT_EQ(B.root->left->row_->name, "bbc");
	ASSERT_EQ(B.root->right->row_->name, "fff");

}

TEST(TTree, can_del_2) {
	Polynomial p1;

	p1.add_monom_in_tail(new Monom(2.3, 2));
	string s1 = "bbb";
	string s2 = "abb";	
	string s3 = "bbf";
	string s4 = "bbc";
	string s5 = "fff";
	Row R1(s1, &p1);
	Row R2(s2, &p1);
	Row R3(s3, &p1);
	Row R4(s4, &p1);
	Row R5(s5, &p1);
	btree B;
	B.insert_(B.root, R1);
	B.insert_(B.root, R2);
	B.insert_(B.root, R3);
	B.insert_(B.root, R4);
	B.insert_(B.root, R5);

	
	B.remove(B.root, "bbb");
	B.print_table();
	
	/*ASSERT_EQ(B.root->right->row_->name, "fff");
	ASSERT_EQ(B.root->right->left->row_->name, "bbc");*/

}		