/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#define RASTER_SIZE 160

#include "../JuceLibraryCode/JuceHeader.h"
#include "GOLCell.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent : public Component, private Timer
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&) override;
    void resized () override;
	void mouseDown (const MouseEvent &event) override;
	void mouseDrag (const MouseEvent &event) override;

private:
	void timerCallback() override;
	GOLCell *cells[RASTER_SIZE][RASTER_SIZE];
	bool firstRun = true;
	bool mouseRespond = false;
	Point<float> pointToDraw;

	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
