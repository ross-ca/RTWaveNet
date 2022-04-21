/*
  ==============================================================================

    Knob.h
    Created: 21 Apr 2022 3:57:41pm
    Author:  Ross Castledine

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Knob : public juce::Slider
{
public:
    Knob(juce::Image stripToShow)
        : filmStrip(stripToShow)
    {
        //Assumes square frames
        filmStripWidth  = filmStrip.getWidth();
        numFrames = filmStrip.getHeight() / filmStripWidth;
    }
    void paint(juce::Graphics &g) override
    {
        std::size_t imageNumber = static_cast<std::size_t>(0.5 + (getValue() - getMinimum()) / (getMaximum() - getMinimum()) * (numFrames - 1));
        g.drawImage(filmStrip, 0, 0, filmStripWidth, filmStripWidth, 0, imageNumber * filmStripWidth, filmStripWidth, filmStripWidth);
    }
    std::size_t getFilmStripWidth() { return filmStripWidth; }
private:
    std::size_t numFrames, filmStripWidth;
    juce::Image filmStrip;
};
