//
// Created by armen karamian on 6/4/17.
//
//	This is the cell that will appear on the user interface.
//	contains a NAME_OF_CLASS object that is represented on the UI as a square/circle/thing
//
#include "../JuceLibraryCode/JuceHeader.h"

#ifndef GAMEOFLIFE_GOLCELL_H
#define GAMEOFLIFE_GOLCELL_H


class GOLCell : public Rectangle<int>
{
private:
	GOLCell *neighbor0; //starting clockwise from top left
	GOLCell *neighbor1;
	GOLCell *neighbor2;
	GOLCell *neighbor3;
	GOLCell *neighbor4;
	GOLCell *neighbor5;
	GOLCell *neighbor6;
	GOLCell *neighbor7;

	bool alive = false;

	void countNeighbors();


public:
	GOLCell(int xx, int yy, int ww, int hh);
//	~GOLCell();
	void setNeighbors(GOLCell *cells[8]);
	void setAlive();
	bool isAlive();
};



#endif //GAMEOFLIFE_GOLCEL