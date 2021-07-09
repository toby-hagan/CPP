#include <iostream>
using namespace std;


void fill(int* pi, int size, int val)
{
	while (size-- > 0) 
	{
		pi[size] = val; // -- changed to size
	}

}


int main1()
{
	double c = 299792458;
	double* pc = &c;

	*pc = *pc * *pc;

	cout << "The value of c (light speed) squared is: " << *pc << endl;

	return 0;
}

int main2()
{
	int* pi;
	int arr[5] = { 1, 2, 3, 4, 5 };
	pi = arr;

	int i = -1; //these two while loops are used to ensure the code has run as intended
	while (i++ < 4)
	{
		cout << pi[i] << " ";
	}

	fill(pi, 5, 6);
	cout << endl;

	i = -1;
	while (i++ < 4)
	{
		cout << pi[i] << " ";
	}


	return 0;
}

