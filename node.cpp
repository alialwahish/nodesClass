#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};

void printList(node *);
void insertOrder(node *&, int);
bool removeNode(node *&, int);

int main()
{
	node *header = NULL;		// start with empty list

	/*
	// push number in front of list
	for (int i = 0; i < 10; i++)
	{
		// create new node
		node *newNode = new node;

		// put data in it
		newNode->data = i * i;

		// point newNode at whatever header was pointing at
		newNode->next = header;

		// point header at the newNode
		header = newNode;
	}
	*/

	//insertOrder(header, 25);
	insertOrder(header, 7);
	insertOrder(header, 33);
	insertOrder(header, 49);
	//insertOrder(header, 37);
	//insertOrder(header, 12);

	printList(header);

	removeNode(header, 33);
	removeNode(header, 7);
	removeNode(header, 49);
	//cout << removeNode(header, 19);

	printList(header);

	return 0;
}

bool removeNode(node *& header, int value)
{
	node *p, *prev;

	// scan list and find node to be deleted
	for (prev = NULL, p = header; p != NULL && value != p->data; prev = p, p = p->next)
		;

	if (p == NULL)
		return false;	// not found

	// if we are here we found a node to remove
	if (prev == NULL)	// removing first node
		header = p->next;
	else
		prev->next = p->next;

	// free up node
	delete p;

	return true;
}

void insertOrder(node *& header, int value)
{
	node *p, *prev, *newNode;

	// scan list and find where node should be inserted
	for (prev = NULL, p = header; p != NULL && value > p->data; prev = p, p = p->next)
		;

	// build new Node
	newNode = new node;

	// put data in it
	newNode->data = value;

	// check if prev should be header (meaning this is inserted first in list)
	if (prev == NULL)
		header = newNode;
	else
		prev->next = newNode;

	// point newNode at p
	newNode->next = p;

}

void printList(node *header)
{
	node *p;

	for (p = header; p != NULL; p = p->next)
		cout << p->data << ", ";

	cout << endl;
}