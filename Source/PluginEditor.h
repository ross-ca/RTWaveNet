/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

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

    juce::Slider inputGain;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RTWaveNetAudioProcessorEditor)
};
