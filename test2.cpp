#include "List.h"
#include "ListNode.h"
#include <iostream>
#include <time.h>  

using namespace std;

double minValue(double* pd, int& p, int N)
{
	double minV = pd[0];
	for (int i = 1; i < N; i++)
		if (minV > pd[i]) {
			minV = pd[i];
			p = i;
		}
	cout << "The complexity of this algorithm is O(N)." << endl;
	return minV;
}

double func(int N)
{
	double total = 0.;
	for (int i = 0; i < N; i++)
		total += i;

	cout << "The complexity of this algorithm is O(N)." << endl;
	return total;
}

void func2(int N)
{
	for (int i = 0; i < N; i++)
		cout << func(i) << endl;

	cout << "The complexity of this algorithm is O(N*N)." << endl;
}

bool bInsert(int*& pi, int& size, int pos, int val)
{
	if (pos < 0 || pos > size) {
		cout << "pos is out of range" << endl;
		return false;
	}
	// new array size after insertion
	size++;
	// new array
	int* piNew = new int[size];
	if (piNew == NULL)
		return false;
	// copt pi to piNew & insert val
	for (int i = 0; i < pos; i++)
		piNew[i] = pi[i];
	piNew[pos] = val;
	for (int i = pos + 1; i < size; i++)
		piNew[i] = pi[i - 1];
	// delete old array
	delete[] pi;
	// point pi to the new array
	pi = piNew;

	cout << "The complexity of this algorithm is O(N)." << endl;
	return true;
}

List<int>* distinctList_1(int N)
{
	srand(time(0)); //this ensures that the numbers provided are random
	List<int>* list1 = new List<int>;
	for (int i = 1; i <= N; i++)
	{
		int randInt = rand();
		bool flag = false;
		for (int x = 0; x < list1->size(); x++)
		{
			if (randInt == list1->get(x))
			{
				flag = true;
			}
		}
		if (flag == false)
		{
			list1->insert_end(randInt);
		}
	}
	cout << "The complexity of the algorithm is O(N(^2)" << endl;
	return list1;

}

List<int>* distinctList_2(int N)
{
	srand(time(0));
	List<int>* list2 = new List<int>;
	for (int i = 1; i <= N; i++) //int i = 1 so that there are the correct number of integers in list
	{
		int randInt = rand();
		bool flag = false;
		list2->setp_first();
		for (int x = 0; x < list2->size(); x++)
		{
			if (randInt == list2->get_next())
			{
				flag = true;
			}
		}
		if (flag == false)
		{
			list2->insert_end(randInt);
		}
	}
	cout << "The complexity of the algorithm is O(N(^2)" << endl;
	return list2;

}

int main()
{
	List<int>* list = distinctList_2(5);
	list->print();
	return 0;
}