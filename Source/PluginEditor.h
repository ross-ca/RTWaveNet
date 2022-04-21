/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <iostream>
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Knob.h"

//==============================================================================
/**
*/
class RTWaveNetAudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Slider::Listener
{
public:
    RTWaveNetAudioProcessorEditor (RTWaveNetAudioProcessor&);
    ~RTWaveNetAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged(juce::Slider* slider) override;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    RTWaveNetAudioProcessor& audioProcessor;

    juce::Image knobImage = juce::ImageCache::getFromFile(juce::File("/Users/ross/Documents/University/Project/Real-Time Implementation/RTWaveNet/Resources/Images/org_amp.png"));
    Knob* inGain = new Knob(knobImage);
    Knob* outGain = new Knob(knobImage);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RTWaveNetAudioProcessorEditor)
};
