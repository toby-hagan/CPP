#include <iostream>
#include "List.h"
#include "ListNode.h"
#include <ctime>

using namespace std;

template<typename T>
int search_r(List<T>& lst, T key)
{
	int val = -1; //default value of -1 for not found
	for (int i = 0; i < lst.size(); i++)
	{
		if (lst.get(i) == key)
		{
			val = i;
		}
	}
	return val;
}

int main1()
{
	// (1)
	List<int> llist;

	// (2)
	srand(time(0));

	for (int i = 0; i < 10; i++)
	{
		llist.insert_end(rand() % 10 + 1);
	}

	llist.print();

	// (3)
	int temp = llist.get(4);
	llist.remove(0); // this block swaps the value in p=4 with the value 1024,
	llist.remove(4); // and inserts the value that was in p=4 into p=0
	llist.insert(4, 1024);
	llist.insert(0, temp);

	// (4)
	for (int i = 0; i < 10; i++)
	{
		cout << llist.get(i) << " ";
	}
	cout << endl;

	// (5)
	llist.get(0);
	for (int i = 0; i < 10; i++)
	{
		cout << llist.get_next() << " ";
	}
	cout << endl;

	return 0;
}

int main()
{
	// define chList
	//int maxArraySize = 5;
	//char* chArray = new char[maxArraySize];
	List<char> chList;
	// read & store characters
	cout << "Type characters to store, ending with a #:" << endl;
	char ch;
	int size = 0;
	while (cin >> ch) {
		if (ch == '#')
			break;
		chList.insert_end(ch);
		size++;
	}
	// print the array
	for (int i = 0; i < size; i++)
		cout << chList.get(i) << " ";
	cout << endl;
	
	// (c) prints the list in reverse
	chList.print_r();

	// (d) runs function declared at the start to search for character 'm' and returns last intance
	cout << search_r(chList, 'm');

	return 0;
}
