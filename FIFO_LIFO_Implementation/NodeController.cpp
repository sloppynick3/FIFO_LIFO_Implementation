#include "NodeController.h"
#include <iostream>


//---------------ADDING-------------------
void NodeController::pushLIFO(int value)
{

	Node * ptr = new Node(value);
	std::cout << "Created node " << std::endl;
	ptr->link = head;
	head = ptr;

	if (ptr->link == nullptr) {
		tail = ptr;
	}
	nodes++;
}

void NodeController::pushFIFO(int value) {
	Node * ptr = new Node(value);
	ptr->link = nullptr;
	nodes++;

	if (head == nullptr) { //That means its the first created node
		head = ptr;
		tail = ptr;
		return;
	}

	Node *i;
	for (i = head; i->link != nullptr; i = i->link);
	i->link = ptr;
	tail = ptr;
}

 void NodeController::addAfter(int value, int data) {
	 Node* cursor = head;
	 Node* previous = new Node();
	 Node* node = new Node(data);

	 if (value == 0) {
		 node->link = head;
		 head = node;
		 return;
	 }


	 for (int i = 0; i < value; i++) {
		 previous = cursor;
		 cursor = cursor->link;
	 }
	 previous->link = node;
	 node->link = cursor;

	 std::cout << "Added node at " << value << std::endl;

}

 void NodeController::addInPosition(int value, int data) {
	 Node* previous = new Node();
	 Node* cursor = head;
	 Node* node = new Node(data);

	 if (value == nodes) {
		 pushFIFO(data);

		 delete previous;
		 delete node;
		 return;
	 }
	 if (value == 0) {
		 Node* node = new Node(data);
		 node->link = head->link;
		 delete head;
		 head = node;
		 return;
	 }

	 if (value > nodes || value < 0) {
		 std::cout << "Position is too large or small." << std::endl;
		 return;
	 }

	 for (int i = 0; i < value; i++) {
		 previous = cursor;
		 cursor = cursor->link;
	 }

	 previous->link = node;
	 node->link = cursor->link;

	 delete cursor;

 }

 //---------------DELETING----------------
 void NodeController::pop()
 {
	 Node* current = head;
	 head = current->link;
	 delete current;

	 nodes--;
	 std::cout << "Removed head" << std::endl;

 }

 void NodeController::popTail() {
	 Node *previous = tail, *i;
	 for (i = head; i->link != nullptr; i = i->link) {
		 previous = i;
	 }

	 tail = previous;
	 tail->link = nullptr;
	 delete i;

	 nodes--;
	 std::cout << "Removed tail" << std::endl;
 }

void NodeController::remove(int node)
{
	if (node == nodes-1) {
		popTail();
		return;
	}
	if (node == 0) {
		pop();
		return;
	}


	if (node < 1 || node > nodes) {
		std::cout << "Invalid node value" << std::endl;
		return;
	}

	Node* current = head;
	Node* previous = new Node();

	for (int i = 0; i < node; i++) {
		previous = current;
		current = current->link;
	}
	previous->link = current->link;

	std::cout << "Deleted node" << std::endl;

	delete current;
	
	nodes--;
}


void NodeController::clear() {
	while (nodes > 0) {
		pop();
	}
}

//----------------PRINTING------------------------

void NodeController::printList() {

	if (head == nullptr) {
		std::cout << "List is empty" << std::endl;
		return;
	}

	Node* cursor = head;

	int i = 0;
	while (cursor != nullptr) {
		
		int data = cursor->data;
		std::cout << "Node nr. " << i << " data is: " << data << std::endl;
		i++;
		cursor = cursor->link;
	}

	std::cout << std::endl << std::endl << std::endl;
}

void NodeController::printListJSON() {
	Node* cursor = head;
	printf("{ \n  \"linkedList\" : { \n");
	printf("    \"nodes\" : \"%i\", \n", nodes + 1);
	printf("    \"values\" : [ ");

	//Prints out values of linked list in an array for JSON
	while (cursor->link != nullptr)
	{
		printf("\"%i\" ,", cursor->data);
		//std::cout  << "\""<< cursor->data << "\" ,";
		if (cursor->link == nullptr) {
			break;
		}
		cursor = cursor->link;
	}

	printf("\"%i\" ] \n  }\n}\n", cursor->data);

}

//---------------------------MISC--------------------------

void NodeController::printListXML() {
	Node* cursor = head;

	printf("<linkedList>\n  <nodes>%i</nodes>\n",nodes+1);
	while (cursor != nullptr) {
		printf("  <values>%i</values\n",cursor->data);
		cursor = cursor->link;
	}
	printf("</linkedList>\n");
}

void NodeController::sort() {
	Node *i, *j;
	i = head;

	for (i = head; i != nullptr; i = i->link) {
		for (j = i->link; j != nullptr; j = j->link) {
			if (i->data > j->data) {
				std::swap(i->data, j->data);
			}
		}
	}
}

Node* NodeController::findElement(int value) {
	Node* node = nullptr; //If wont be found returns null

	for (Node* i = head; i != nullptr; i = i->link) {
		if (i->data == value) {
			node = i;
			break;
		}
	}


	return node;
}

void NodeController::addSorted(int data) {
	int pos = 0;
	

	for (Node* i = head; i != nullptr; i = i->link) {
		if (data < i->data) {
			addAfter(pos,data);
			break;
		}
		pos++;
	}

	addAfter(pos, data);
}

void NodeController::push(int value)
{
}
