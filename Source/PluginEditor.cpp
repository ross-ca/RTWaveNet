/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RTWaveNetAudioProcessorEditor::RTWaveNetAudioProcessorEditor (RTWaveNetAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);
    
    inputGain.setSliderStyle(juce::Slider::LinearBarVertical);
    inputGain.setRange(-24.0, 24.0, 0.1);
    inputGain.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    inputGain.setPopupDisplayEnabled(true, false, this);
    inputGain.setTextValueSuffix(" dB");
    inputGain.setValue(0.0);
    inputGain.addListener(this);
    addAndMakeVisible(&inputGain);
}

RTWaveNetAudioProcessorEditor::~RTWaveNetAudioProcessorEditor()
{
}

//==============================================================================
void RTWaveNetAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText("RTWaveNet", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void RTWaveNetAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    inputGain.setBounds(40, 30, 20, getHeight() - 60);
}

void RTWaveNetAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    audioProcessor.addedInGain = inputGain.getValue();
}
