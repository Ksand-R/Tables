
#include "gtest.h"`
#include "Tabl_proj.h"
#include "Polynomial.h"
#include "Monom.h"
#include "sorted_t.h"


TEST(TSorted, can_sort_rows) {
	Polynomial p1;

	p1.add_monom_in_tail(new Monom(2.3, 2));
	p1.add_monom_in_tail(new Monom(2.1, 3));
	p1.add_monom_in_tail(new Monom(-2.1, 13));
	Row R1("abc", &p1);
	Row R2("acd", &p1);
	Row R3("accd", &p1);
	Row R4("adcd", &p1);
	Row R5("ascd", &p1);
	Row R6("aacd", &p1);
	sorted_t T;
	T.insert(R4);
	T.insert(R2);
	T.insert(R6);
	T.insert(R1);
	T.insert(R5);
	T.insert(R3);
	
	ASSERT_EQ(T[0].name, R6.name);
	ASSERT_EQ(T[1].name, R1.name);
	ASSERT_EQ(T[4].name, R4.name);
	ASSERT_EQ(T[5].name, R5.name);

}
