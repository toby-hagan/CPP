#include "iarray.h"
#include <iostream>
#include <ctime>

using namespace std;

// (1) constructor
iarray::iarray(int length)
	: size(length)
{
	data = NULL;
	data = new int[size];
}

// (2) destructor
iarray::~iarray()
{
	delete[] data;
}

// (3) print function
void iarray::print()
{
	int* pi = data;
	int i = size;

	while (i-- > 0) {
		cout << *pi++ << " ";
		cout << endl;
	}
}

// (4) fill function
void iarray::fill(int v0, int v1)
{
	srand(time(0));

	int i = 0;
	while (i < size)
	{
		data[i] = rand() % (v1 - v0) + v0;
		i++;
	}
}

int main()
{
	iarray* myArr = new iarray(5);
	myArr->fill(1, 10);
	myArr->print();
	
	return 0;
}