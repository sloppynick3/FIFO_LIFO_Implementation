#pragma once
#include "Node.h"
class NodeController
{
public:
	Node * head = nullptr;
	Node * tail = nullptr;
	int nodes = 0;

	void addAfter(int value, int data);
	void addInPosition(int value, int data);
	void pushFIFO(int value);
	void pushLIFO(int value);
	void remove	(int node);
	virtual void push(int value);
	void pop();

	void popTail();

	void clear();

	void printList();

	void printListJSON();

	void printListXML();

	void sort();

	Node * findElement(int value);

	void addSorted(int value);
	
};

