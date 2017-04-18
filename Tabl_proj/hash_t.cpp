#include <hash_t.h>
#include <string>
#include <list>
using namespace std;

hash_t::hash_t() {

	array = new list<Row>*[SIZE];

	for (int i = 0; i < SIZE; ++i)
	{
		array[i] = new list <Row>;
	}
	filled_rows = 0;

}

hash_t::~hash_t() {
	for (int i = 0; i < SIZE; ++i)
	{
		delete array[i];
		//cout << i << endl;
	}
	delete[] array;
	//cout << "Im alive";
	filled_rows = 0;
}

unsigned int hash_t::MurmurHash2(const char * key, unsigned int len)
{
	//Copyright Austin Appleby
	const unsigned int m = 0x5bd1e995;
	const unsigned int seed = 0;
	const int r = 24;

	unsigned int h = seed ^ len;

	const unsigned char * data = (unsigned char *)key;
	unsigned int k;

	while (len >= 4)
	{
		k = data[0];
		k |= data[1] << 8;
		k |= data[2] << 16;
		k |= data[3] << 24;

		k *= m;
		k ^= k >> r;
		k *= m;
		h *= m;

		h ^= k;

		data += 4;
		len -= 4;
	}

	switch (len)
	{
	case 3:
		h ^= data[2] << 16;
	case 2:
		h ^= data[1] << 8;
	case 1:
		h ^= data[0];
		h *= m;
	};

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h % SIZE;
}


void hash_t::insert(const Row& r) {
	int hash = MurmurHash2(r.name.c_str(), (unsigned int)(r.name).length());
	array[hash]->push_back(r);
	//add_el_in_tail(r);
	filled_rows++;
}

void hash_t::remove(string r) {
	unsigned int hash = MurmurHash2((r.c_str()), r.length());
	//Polynomial* tmp = find_row(r);
	list<Row>::const_iterator it;
	for (it = array[hash]->begin(); it != array[hash]->end(); it++) {
		if (it->name == r) { array[hash]->remove(*it);
		break;
		}// erase?
	}
	filled_rows--;
}


void hash_t::print_table() {
	for (int i(0); i < SIZE; ++i) {
		cout << i << "th chain: ";
		

		list<Row>::const_iterator it;
		for (it = array[i]->begin(); it != array[i]->end(); it++) {
			cout << it->name << " " << *(it->ptr_p) << "; ";
		}
		cout << endl;
		//if (array[i].name == "emp") { cout << "emp" << endl; }
		//else {
		//	cout << array[i].is__empty << "	" <<
		//		array[i] << endl;
		//}
	}
}

Polynomial* hash_t::find_row(string r) {
	//_List::find_ptr();
	//int hash = MurmurHash2(r.c_str(), r.length());
	//list<Row>::const_iterator it = array[hash]->begin();
	//
	//for (; it != array[hash]->end(); ++it)
	//{
	//	if (r == it->name)
	//	{
	//		return it->ptr_p;
	//	}
	//}
	return NULL;
}