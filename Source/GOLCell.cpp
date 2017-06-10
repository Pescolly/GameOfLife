//
// Created by armen karamian on 6/4/17.
//
/*/
Rules:
1.	Any live cell with fewer than two live neighbours dies, as if caused by under-population.
2.	Any live cell with two or three live neighbours lives on to the next generation.
3.	Any live cell with more than three live neighbours dies, as if by overcrowding.
4.	Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
/*/
#include "GOLCell.h"
#define ALIVE true
#define DEAD false


void GOLCell::countNeighbors()
{
	int neighborCount = 0;
	if (neighbor0) { if (neighbor0->alive) { neighborCount++; } }
	if (neighbor1) { if (neighbor1->alive) { neighborCount++; } }
	if (neighbor2) { if (neighbor2->alive) { neighborCount++; } }
	if (neighbor3) { if (neighbor3->alive) { neighborCount++; } }
	if (neighbor4) { if (neighbor4->alive) { neighborCount++; } }
	if (neighbor5) { if (neighbor5->alive) { neighborCount++; } }
	if (neighbor6) { if (neighbor6->alive) { neighborCount++; } }
	if (neighbor7) { if (neighbor7->alive) { neighborCount++; } }

	if (alive)
	{
		if (neighborCount < 2) { alive = DEAD; return; }
		if (neighborCount > 3) { alive = DEAD; return; }
		if (neighborCount == 2 || neighborCount == 3) { alive = ALIVE; return; }
	}
	else
	{
		if (neighborCount == 3) { alive = ALIVE; return; }
	}
}


bool GOLCell::isAlive()
{
	this->countNeighbors();
	return this->alive;
}

GOLCell::GOLCell(int xx, int yy, int ww, int hh) : Rectangle<int>(xx, yy, ww, hh) {}

void GOLCell::setNeighbors(GOLCell *cells[8])
{
	neighbor0 = cells[0];
	neighbor1 = cells[1];
	neighbor2 = cells[2];
	neighbor3 = cells[3];
	neighbor4 = cells[4];
	neighbor5 = cells[5];
	neighbor6 = cells[6];
	neighbor7 = cells[7];
}

void GOLCell::setAlive()
{
	alive = true;
}
