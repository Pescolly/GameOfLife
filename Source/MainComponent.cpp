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
	this->startTimer(3000);

	//setup cells
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			cells[i][j] = new GOLCell(i*10,j*10,10,10);
		}
	}

	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			//create temp array to pass into neighbor assignment
			//cells go clockwise around current
			GOLCell *tempCellArr[8];
			if (i-1 >= 0 && j-1 >= 0) { tempCellArr[0] = cells[i-1][j-1]; }
			else { tempCellArr[0] = NULL; }

			if (i-1 >= 0) tempCellArr[1] = cells[i-1][j];
			else { tempCellArr[1] = NULL; }
			if (i-1 >= 0 && j+1 < 79) tempCellArr[2] = cells[i-1][j+1];
			else { tempCellArr[2] = NULL; }

			if (j+1 < 79) tempCellArr[3] = cells[i][j+1];
			else { tempCellArr[3] = NULL; }
			if (i+1 < 79 && j+1 < 79) tempCellArr[4] = cells[i+1][j+1];
			else { tempCellArr[4] = NULL; }
			if (i+1 < 79) tempCellArr[5] = cells[i+1][j];
			else { tempCellArr[5] = NULL; }

			if (i+1 < 79 && j-1 >= 0) tempCellArr[6] = cells[i+1][j-1];
			else { tempCellArr[6] = NULL; }
			if (j-1 >= 0) tempCellArr[7] = cells[i][j-1];
			else { tempCellArr[7] = NULL; }


			cells[i][j]->setNeighbors(tempCellArr);
		}
	}	
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
	g.fillAll (Colour (0xff001F36));
	
	if (firstRun)
	{
		std::cout <<"seeding life" << std::endl;
		g.setColour(Colours::greenyellow);
		cells[3][0]->setAlive(); g.fillRect((Rectangle<int>)*cells[3][0]);
		cells[3][1]->setAlive(); g.fillRect((Rectangle<int>)*cells[3][1]);
		cells[3][2]->setAlive(); g.fillRect((Rectangle<int>)*cells[3][2]);
		cells[4][0]->setAlive(); g.fillRect((Rectangle<int>)*cells[4][0]);
		cells[5][0]->setAlive(); g.fillRect((Rectangle<int>)*cells[5][0]);
		cells[6][0]->setAlive(); g.fillRect((Rectangle<int>)*cells[6][0]);
		firstRun = false;
	}
	else
	{
		std::cout << "running game" << std::endl;
		// run game
		for (int i = 0; i < 80; i++)
		{
			for (int j = 0; j < 80; j++)
			{
				if (cells[i][j]->isAlive())
				{ std::cout << i << j << " is alive" << std::endl; g.setColour(Colours::greenyellow); }
				else g.setColour(Colours::black);
				g.fillRect((Rectangle<int>)*cells[i][j]);
			}
		}
	}
	
	if (mouseRespond)
	{
		g.setColour(Colours::greenyellow);
		g.fillRect((Rectangle<int>)*cells[(int)pointToDraw.x/10][(int)pointToDraw.y/10]);
		mouseRespond = false;
	}
	
}

void MainContentComponent::mouseDown(const MouseEvent &event)
{
	std::cout << "Draw position: " << event.position.x << " " << event.position.y << std::endl;
	mouseRespond = true;
	pointToDraw.setXY(event.position.x, event.position.y);
	repaint();
}


#pragma clang diagnostic pop

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
