#include <iostream>
#include "List.h"
#include "ListNode.h"

using namespace std;

int* insertionSort(int* a, int N)
{
	for (int i = 1; i < N; i++)
	{
		int item = a[i];
		int j = i - 1;

		// from j to 0 move a[j] > item up to a[j+1]
		while (j >= 0 && a[j] > item)
		{
			a[j + 1] = a[j];
			j--;
		}
		// insert item into the first a[j+1] with a[j] < item 
		a[j + 1] = item;
	}
	return a;
}

int rLargest(int* pi, int N, int r)
{
	pi = insertionSort(pi, N);
	return pi[(N - 1) - (r - 1)];
}

int main1()
{
	int nums[5] = { 1, 4, 9, 6, 2 };
	cout << rLargest(nums, 5, 1) << endl;
	cout << rLargest(nums, 5, 5) << endl;

	cout << "The complexity of rLargest is O(N squared)." << endl;
	return 0;
}

int* quickSort1(int* a, int first, int last)
{// partition
	int i = first, j = last;
	int pivot = a[(first + last) / 2];
	while (i <= j) 
	{
		while (a[i] < pivot)i++;
		while (a[j] > pivot)j--;
		if (i <= j) 
		{ 
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}// recursion
	if (first < i - 1) 
		quickSort1(a, first, i - 1);
	if (i < last) 
		quickSort1(a, i, last);
	
	return a;
}

int rLargestQuick(int* pi, int N, int r)
{
	pi = quickSort1(pi, 0, N-1);
	return pi[(N - 1) - (r - 1)];
}

int main2()
{
	int nums[5] = { 1, 4, 9, 6, 2 };
	cout << rLargestQuick(nums, 5, 1) << endl;
	cout << rLargestQuick(nums, 5, 5) << endl;

	cout << "The complexity of rLargest is O(logN)." << endl;
	return 0;
}

template<typename T>
void quickSort(List<T>* l, int first, int last)
{
	int i = first, j = last;
	int pivot = (l->get(first) + l->get(last)) / 2;
	while (i <= j)
	{
		while (l->get(i) < pivot)i++;
		while (l->get(j) > pivot)j--;
		if (i <= j)
		{
			int tmp = l->get(i);
			l->set(i, l->get(j));
			l->set(j, tmp);
			i++;
			j--;
		}
	}// recursion
	if (first < i - 1)
		quickSort(l, first, i - 1);
	if (i < last)
		quickSort(l, i, last);

}

int main()
{
	srand(time(0));
	// list size
	int N = 50;
	// 1. create a linked list l of N any-range random integers
	List<int>* l = new List<int>;
	for (int i = 0; i <= N; i++) //int i = 1 so that there are the correct number of integers in list
	{
		l->insert_end(rand());
	}
	// 2. print l before sorting
	cout << "List: ";
	l->print();
	// 3. call quickSort to sort list l
	quickSort(l, 0, N);
	// 4. print l after sorting
	cout << "Sorted list: ";
	l->print();
	return 0;
}
