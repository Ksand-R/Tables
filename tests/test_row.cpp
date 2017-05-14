#include "gtest.h"
#include "Tabl_proj.h"
#include "Polynomial.h"
#include "Monom.h"

Polynomial p1;
	add_monom_in_tail(new Monom(2.3, 2));
	p1.add_monom_in_tail(new Monom(2.1, 3));
	p1.add_monom_in_tail(new Monom(-2.1, 13));	

Row R;
Row R1("abc", p1)
TEST(TRow, can_create_row) {
	
	ASSERT_EQ(R.is__empty, true);
	ASSERT_EQ(R.name, "emp");
	ASSERT_EQ(R.ptr_p, nullptr);
}


TEST(TRow, can_cmp_rows) {
	

}