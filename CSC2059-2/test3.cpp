#include "StackNode.h"
#include "Stack.h"
#include <iostream>

int main1()
{
	Stack<char> *psa = new Stack<char>;
	
	for (int i = 97; i <= 122; i++)
	{
		psa->push(i);
	}
	psa->print();

	int pos = psa->search('m');
	if (pos == -1)
	{
		cout << "The character 'm' is not in the stack. " << endl;
	}
	else
	{
		cout << "The character 'm' is in the stack. " << endl;
	}

	pos = psa->search('=');
	if (pos == -1)
	{
		cout << "The character '=' is not in the stack. " << endl;
	}
	else
	{
		cout << "The character '=' is in the stack. " << endl;
	}

	Stack<char>* psb = new Stack<char>;
	psb = psa;
	psa->print();

	psa->~Stack();
	psb->~Stack();

	return 0;
}


int main()
{
	// stack sent1 is used to store words from input
	Stack<string> sent1;
	string word = "";
	cout << "Enter a sentence, ending with a separate period ." << endl;
	cin >> word;
	while (word != ".") {
		sent1.push(word); // fills sent1 with the words in reverse order due to stack structure
		cin >> word;
	}

	// I believe I need code such as Stack<string> *sent2 = new Stack<string>,
	// however, I ran out of time before I could implement this.
	Stack<string> sent2;
	sent2 = sent1;

	while (sent1.size() > 0)
		sent2.push(sent1.pop()); // swaps the order of the words by changing stack
	cout << endl;

	// sent2 is used for output
	while (sent2.size() > 1)
		cout << sent2.pop() << " ";
	cout << endl;
	
	sent2.count("is");

	return 0;
}

/*
I again got a access violation reading location error, however my code runs as intended and outputs the correct result. 
*/