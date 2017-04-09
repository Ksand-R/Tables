#include "sorted_t.h"
#include <iostream>

sorted_t::sorted_t() {
	array = new Row[size];
	curr_pos = 0;
	for (int i(0); i < size; ++i) {
		array[i].is__empty = true;
		array[i].name = "emp";
		array[i].ptr_p = new Polynomial;
	}
}

sorted_t::~sorted_t() {
	delete[] array;
	curr_pos = 0;
}

void sorted_t::insert(const Row& r) {
	if (curr_pos == 0) {
		array[0] = r;
		array[0].is__empty = false;
		curr_pos++;
		//cout << array[0] << endl;
	}
	else {
		int tmp = search(r.name);
		curr_pos++;
		if (tmp < curr_pos) {
			
			for (int i(curr_pos); i > tmp; --i) {
				array[i] = array[i - 1];
			}
			array[tmp] = r;
			array[tmp].is__empty = false;
		}
		else {
			array[curr_pos] = r;
			array[curr_pos].is__empty = false;
		}
	}
	//for (int i(0); i < curr_pos; ++i) {
	//	cout << array[i] << endl;
	//}
	//cout << "alive" << endl;

}

int sorted_t::search(string name) {
		if (curr_pos == 0)
		{
			throw std::logic_error(" This name is not found "); // dont works
			cout << " search error "; // dont works
			return -1;
		}
		else {
			int left = -1;

			int right = curr_pos;

			int mid;
			while (left < right - 1)
			{
				mid = (left + right) / 2;
				if (array[mid].name < name)
					left = mid;
				else
					right = mid;
			}

			return right;
			//return *(array[right].ptr_p);
		}

}

void sorted_t::remove(string r) {

	int is_found = search(r);
	if (is_found != -1) {
		array[is_found].is__empty = true;
	}
	else {
		throw std::logic_error(" This name is not found "); // dont works
		cout << " search error "; // dont works
	}

}

void sorted_t::print_table() {
	for (int i(0); i < size; ++i) {
		cout << array[i] << endl;
	}
}

ostream& operator << (ostream& os, const sorted_t& t) {
	for (int i(0); i < t.size; ++i) {
		os << t.array[i] << endl;
		return os;
	}
}