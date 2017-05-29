
#include "gtest.h"`
#include "Tabl_proj.h"
#include "Polynomial.h"
#include "Monom.h"




TEST(TRow, can_create_row) {
	Polynomial p1;
	Row R;
	

	ASSERT_EQ(R.is__empty, true);
	ASSERT_EQ(R.name, "emp");
	ASSERT_EQ(R.ptr_p, nullptr);
}


TEST(TRow, can_cmp_rows) {
	Polynomial p1;

	p1.add_monom_in_tail(new Monom(2.3, 2));
	p1.add_monom_in_tail(new Monom(2.1, 3));
	p1.add_monom_in_tail(new Monom(-2.1, 13));
	Row R1("abc", &p1);
	Row R2("aaa", &p1);
	ASSERT_LT(R2.name, R1.name);
}

TEST(TRow, can_assign) {
	Polynomial p1;

	p1.add_monom_in_tail(new Monom(2.3, 2));
	p1.add_monom_in_tail(new Monom(2.1, 3));
	p1.add_monom_in_tail(new Monom(-2.1, 13));
	Row R1("abc", &p1);
	Row R2 = R1;
	ASSERT_EQ(R1 == R2, true);
}