#ifndef IARRAY_H
#define IARRAY_H

#include <iostream>
#include "iarray.h"

class iarray
{
	private :
		int* data; // (pointer to) an integer data array
		int size; // size of the data array

	public:
		// (1) constructor, to set the size of the array to length and allocate
		// memory for the array to the given size
		iarray(int length);
		// (2) destructor, to free the memory allocated for the data array
		~iarray();

		// (3) function, to print the array elements
		void print();
		// (4) function, to fill the array elements with random numbers
		// between v0 and v1 (inclusive)
		void fill(int v0, int v1);
};

#endif