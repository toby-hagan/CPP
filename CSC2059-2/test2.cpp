#include <iostream>
#include "TwoValues.h"

using namespace std;

template<typename T>
void fill(T* pi, T size, T val)
{
	while (size-- > 0)
	{
		pi[size] = val;
	}

}

template<typename T>
bool alloc(T*& pt, int size, T v0)	// I got an exception error here 'Access violation writing location', 
									// seems to be an error with my pcmay run correctly on your pc
{
	
	fill(pt, 10, v0);

	/*int n = size;
	while (n-- > 0)
		pt[n] = v0;
		*/
	// this was another method of filling the array that I had developed
	for (int i = 0; i < size; i++)
	{
		TwoValues<int> tv(v0, pt[i]);
		if (tv.equal() == false)
		{
			pt = NULL;
			return false;
		}
	}

	return true;
	
}

int main1()
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

int main2()
{
	TwoValues<double> meme(3.0, 3.1);
	if (meme.equal() == true)
	{
		cout << "Two values are equal" << endl;
	}
	else
	{
		cout << "Two values are not equal" << endl;
	}

	TwoValues<string>* stringValues = new TwoValues<string>("abcd", "abcd");
	if (stringValues->equal() == true)
	{
		cout << "Two string values are equal" << endl;
	}
	else
	{
		cout << "Two string values are not equal" << endl;
	}

	delete stringValues;

	return 0;

}

int main() //this was test that alloc ran as intended
{
	int* pi;
	int arr[10] = { 1, 2, 3, 4, 5 };
	pi = arr;

	if (alloc(pi, 10, 10))
	{
		cout << "The allocation was completed succesfully." << endl;
	}

	return 0;
}