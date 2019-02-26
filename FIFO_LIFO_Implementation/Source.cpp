#include<iostream>
#include "LIFO.h"
#include "FIFO.h"
using namespace std;




int main() {
	//INFO ABOUT LINKED LISTS http://www.manojagarwal.co.in/singly-linked-list-creation-lifo-fifo-sorted/
	LIFO n;
	n.push(1);
	n.push(2);
	n.push(3);
	n.push(4);



	n.printList();

	//n.addAfter(4, 51);


	n.printList();

	n.remove(0);
	n.printList();
	n.remove(1);

	n.printList();


	n.sort();

	n.printList();

	n.addSorted(55);

	n.printList();

	//cout << n.findElement(15) << endl;
	//n.addInPosition(0, 62);

	//n.printListJSON();

	//n.printListXML();

	cout << "----------------------FIFO---------------------------------" << endl;
	cout << "\n\n\n\n\n\n";

	FIFO m;

	m.push(5);
	m.push(4);
	m.push(3);
	m.push(2);
	m.push(1);




	m.printList();

	m.addAfter(4, 51);


	m.printList();

	m.pop();
	m.pop();	

	m.printList();

	m.addInPosition(1, 62);

	m.printListJSON();

	m.printListXML();

	cin.ignore();
	return 0;
}