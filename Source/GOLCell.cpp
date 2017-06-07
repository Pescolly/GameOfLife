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
	if (neighbor0->alive) neighborCount++;
	if (neighbor1->alive) neighborCount++;
	if (neighbor2->alive) neighborCount++;
	if (neighbor3->alive) neighborCount++;
	if (neighbor4->alive) neighborCount++;
	if (neighbor5->alive) neighborCount++;
	if (neighbor6->alive) neighborCount++;
	if (neighbor7->alive) neighborCount++;

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
	return this->alive;
}

GOLCell::GOLCell(int xx, int yy, int ww, int hh) : Rectangle(xx, yy, ww, hh)
{

}
