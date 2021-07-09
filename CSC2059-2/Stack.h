#ifndef STACK_H
#define STACK_H

#include "StackNode.h"
#include <iostream>

using namespace std;

template<typename T>
class Stack
{
public:
	Stack();		// parameter-less constructor
	Stack(const Stack<T>& sr);	// copy constructor
	~Stack();		// destructor

	T push(T i);	// push item i onto stack
	T pop();		// pop off top item 
	int size();		// return number of items in stack

	T operator+(T i);	// overload + for push
	T operator-();      // overload - for pop

	// operator==, to compare between two stack objects e.g. a == b
	// Two stacks are identical if and only if they have the same size and 
	// same sequence of data items
	bool operator==(const Stack& b) const;
	
	void print();		// print
	int search(T key);	// search

	int count(T item);
	bool insert(int n, T item);

private:
	StackNode<T>* pTos;
	int stackSize;
};

template<typename T>
Stack<T>::Stack()
{
	pTos = NULL;
	stackSize = 0;
}

template<typename T>
Stack<T>::Stack(const Stack<T>& sr)
{
	// push sr content into a temp stack in LIFO
	Stack<T>* s_temp = new Stack;
	StackNode<T>* psrTos = sr.pTos;
	while (psrTos != NULL) {
		s_temp->push(psrTos->item);
		psrTos = psrTos->pNextNode;
	}

	// push temp stack content into THIS stack in LIFO
	while (s_temp->pTos)
		push(s_temp->pop());
	delete s_temp;
}

template<typename T>
Stack<T>::~Stack()
{
	while (pTos) {
		StackNode<T>* pNewTos = pTos->pNextNode;
		delete pTos;
		pTos = pNewTos;
	}
}

template<typename T>
T Stack<T>::push(T i)
{
	StackNode<T>* pNewTos = new StackNode<T>(i, pTos);
	pTos = pNewTos;
	stackSize++;
	return i;
}

template<typename T>
T Stack<T>::pop()
{
	if (pTos) {
		T item = pTos->item;
		StackNode<T>* pNewTos = pTos->pNextNode;
		delete pTos;
		pTos = pNewTos;
		stackSize--;
		return item;
	}
	cout << "Stack underflow. Exit." << endl;
	exit(1);
}

template<typename T>
int Stack<T>::size()
{
	return stackSize;
}

template<typename T>
T Stack<T>::operator+(T i)
{
	return push(i);
}

template<typename T>
T Stack<T>::operator-()
{
	return pop();
}

// operator ==
template<typename T>
bool Stack<T>::operator==(const Stack& b) const
{
	if (stackSize != b.stackSize)
		return false;

	StackNode<T>* pNewTos = pTos;
	StackNode<T>* pNewTos_b = b.pTos;

	while (pNewTos) {
		if (pNewTos->item != pNewTos_b->item)
			return false;
		pNewTos = pNewTos->pNextNode;
		pNewTos_b = pNewTos_b->pNextNode;
	}

	return true;
}

// print
template<typename T>
void Stack<T>::print()
{
	StackNode<T>* pNewTos = pTos;
	while (pNewTos) {
		cout << pNewTos->item << endl;
		pNewTos = pNewTos->pNextNode;
	}
	cout << endl;
}

// search
template<typename T>
int Stack<T>::search(T key)
{
	StackNode<T>* pNewTos = pTos;
	for(int pos = stackSize - 1; pos >= 0; pos--) {
		if (pNewTos->item == key)
			return pos;
		pNewTos = pNewTos->pNextNode;
	}
	return -1;
}

//count
template<typename T>
int Stack<T>::count(T item)
{
	int count = 0;
	StackNode<T>* pNewTos = pTos;
	for (int pos = stackSize - 1; pos >= 0; pos--) {
		if (pNewTos->item == item)
			count++;
		pNewTos = pNewTos->pNextNode;
	}
	return count;
}

template<typename T>
bool Stack<T>::insert(int n, T item) {
	Stack<string> tempStack;
	int i = stackSize - 1;
	while (i >= n) {
		tempStack.push(pop());
		if (i == n) {
			push(item);
		}
		i--;
	}
	for (int i = 0; i <= n + 1; i++) {
		push(tempStack.pop());
	}
	return true;
}

#endif
