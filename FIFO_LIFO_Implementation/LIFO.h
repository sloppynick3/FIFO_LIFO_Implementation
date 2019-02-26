#pragma once
#include "NodeController.h"
#include <iostream>
class LIFO :
	public NodeController
{
public:
	LIFO();
	LIFO(int value);
	~LIFO();
	void push(int value);
};

