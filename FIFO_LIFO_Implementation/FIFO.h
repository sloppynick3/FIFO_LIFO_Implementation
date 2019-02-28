#pragma once
#include "LinkedList.h"
#include <iostream>
class FIFO :
	public NodeController
{
public:
	FIFO();
	~FIFO();
	FIFO(int value);

	void push(int value);

};

