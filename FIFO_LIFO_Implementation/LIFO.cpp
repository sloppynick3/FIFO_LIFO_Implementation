#include "LIFO.h"



LIFO::LIFO()
{
	head = nullptr;
}

LIFO::LIFO(int value)
{
	pushFIFO(value);
}


LIFO::~LIFO()
{
	clear();
}

void LIFO::push(int value)
{
	pushLIFO(value);
}
