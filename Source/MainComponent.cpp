/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (800, 800);
	this->startTimer(1000);

	//setup cells
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			GOLCell cell(i*10,j*10,10,10);
			cells[i][j] = cell;
		}
	}

	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			//create temp array to pass into neighbor assignment
			//cells go clockwise around current
			GOLCell *tempCellArr[8];
			if (i-1 >= 0 && j-1 >= 0) tempCellArr[0] = &cells[i-1][j-1];
			if (i-1 >= 0) tempCellArr[1] = &cells[i-1][j];
			if (i-1 >= 0 && j+1 < 79) tempCellArr[2] = &cells[i-1][j+1];

			if (j+1 < 79) tempCellArr[3] = &cells[i][j+1];
			if (i+1 < 79 && j+1 < 79) tempCellArr[4] = &cells[i+1][j+1];
			if (i+1 < 79) tempCellArr[5] = &cells[i+1][j];

			if (i+1 < 79 && j-1 >= 0) tempCellArr[6] = &cells[i+1][j-1];
			if (j-1 >= 0) tempCellArr[7] = &cells[i][j-1];


			cells[i][j].setNeighbors(tempCellArr);
		}
	}

	cells[0][0].setAlive();
	cells[0][1].setAlive();
	cells[0][2].setAlive();

}

MainContentComponent::~MainContentComponent() {}

void MainContentComponent::timerCallback()
{
	repaint();
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
void MainContentComponent::paint (Graphics& g)
{
	std::cout << "painting" << std::endl;
    g.fillAll (Colour (0xff001F36));
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (cells[i][j].isAlive()) g.setColour(Colours::greenyellow);
			else g.setColour(Colours::black);
			Rectangle<int> cellColorShading = (Rectangle<int>)cells[i][j];
			g.fillRect(cellColorShading);
		}
	}
}
#pragma clang diagnostic pop



void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
