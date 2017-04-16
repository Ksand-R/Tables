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

}

hash_t::~hash_t() {
	for (int i = 0; i < SIZE; ++i)
	{
		delete array[i];
		//cout << i << endl;
	}
	delete[] array;
	//cout << "Im alive";

}

unsigned int hash_t::MurmurHash2(char * key, unsigned int len)
{
	//Copyright Austin Appleby
	const unsigned int m = 0x5bd1e995;
	const unsigned int seed = 0;
	const int r = 24;

	unsigned int h = seed ^ len;

	const unsigned char * data = (const unsigned char *)key;
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