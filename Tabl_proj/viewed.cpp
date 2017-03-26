#pragma once
#include "viewed.h"
using namespace std;

void viewed_tables::insert(Row* r){
	array[count_rows] = r;
	count_rows++;
}

void viewed_tables::print_table() {
	for (int i(0); i < count_rows; ++i) {
		cout << array[i] << endl;
	}
}
viewed_tables::viewed_tables(){
	Row* array[SIZE] = {};
	count_rows = 0;
}
