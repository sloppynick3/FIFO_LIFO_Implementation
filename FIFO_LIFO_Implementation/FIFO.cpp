#include "FIFO.h"



FIFO::FIFO()
{
	head = nullptr;
}


FIFO::~FIFO()
{
	clear();
}

FIFO::FIFO(int value)
{
	pushFIFO(value);
}

void FIFO::push(int value) {
	pushFIFO(value);
}
