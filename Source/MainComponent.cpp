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
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff001F36));

	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (j%2 == 0 && i%2 == 0) { g.setColour (Colours::sandybrown); }
			if (j%2 == 0 && i%2 == 0) { g.setColour (Colours::sandybrown); }
			else { g.setColour (Colours::green); }

			GOLCell cell(i*10,j*10,10,10);
			Rectangle<int> cellColorShading = (Rectangle<int>)cell;
			g.fillRect(cellColorShading);

		}

	}
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
