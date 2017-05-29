#include "gtest.h"`
#include "Polynomial.h"
#include "Monom.h"
#include "viewed.h"


TEST(TView, can_create_table) {
	viewed_tables T;
	ASSERT_EQ(T[1].is__empty, true);
	ASSERT_EQ(T[1].name, "emp");
	ASSERT_EQ(T[2].ptr_p, nullptr);
	ASSERT_EQ(T[4].is__empty, true);
	ASSERT_EQ(T[4].name, "emp");
	ASSERT_EQ(T[4].ptr_p, nullptr);
}

TEST(TView, can_insert_row) {
	Polynomial p1;

	p1.add_monom_in_tail(new Monom(2.3, 2));
	p1.add_monom_in_tail(new Monom(2.1, 3));
	p1.add_monom_in_tail(new Monom(-2.1, 13));
	Row R1("abc", &p1);
	viewed_tables T;
	T.insert(R1);

	ASSERT_EQ(T[0].name, R1.name);

	ASSERT_EQ(*(T[0].ptr_p), *(R1.ptr_p));
}

TEST(TView, can_remove_row) {
	Polynomial p1;

	p1.add_monom_in_tail(new Monom(2.3, 2));
	p1.add_monom_in_tail(new Monom(2.1, 3));
	p1.add_monom_in_tail(new Monom(-2.1, 13));
	Row R1("abc", &p1);
	Row R2("cdd", &p1);
	Row R3("bbb", &p1);
	viewed_tables T;
	T.insert(R1);
	T.insert(R2);
	T.insert(R3);
	T.remove("cdd");
	ASSERT_EQ(T[1].name, "bbb");

//	ASSERT_EQ(T[0].ptr_p == nullptr, true);
}