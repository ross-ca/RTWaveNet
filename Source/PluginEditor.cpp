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
    setSize (878, 400);
    
    inGain->setSliderStyle(juce::Slider::RotaryVerticalDrag);
    inGain->setRange(-24.0, 24.0, 0.1);
    inGain->setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    inGain->setPopupDisplayEnabled(true, false, this);
    inGain->setTextValueSuffix(" dB");
    inGain->setValue(0.0);
    inGain->addListener(this);
    addAndMakeVisible(inGain);
    
    outGain->setSliderStyle(juce::Slider::RotaryVerticalDrag);
    outGain->setRange(-24.0, 24.0, 0.1);
    outGain->setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    outGain->setPopupDisplayEnabled(true, false, this);
    outGain->setTextValueSuffix(" dB");
    outGain->setValue(0.0);
    outGain->addListener(this);
    addAndMakeVisible(outGain);
}

RTWaveNetAudioProcessorEditor::~RTWaveNetAudioProcessorEditor()
{
}

//==============================================================================
void RTWaveNetAudioProcessorEditor::paint (juce::Graphics& g)
{
    juce::Image background = juce::ImageCache::getFromFile(juce::File("/Users/ross/Documents/University/Project/Real-Time Implementation/RTWaveNet/Resources/Images/WaveNetAmp.png"));
    g.drawImageAt(background, 0, 0);
}

void RTWaveNetAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    inGain->setBounds(366, 251, inGain->getFilmStripWidth(), inGain->getFilmStripWidth());
    outGain->setBounds(464, 251, outGain->getFilmStripWidth(), outGain->getFilmStripWidth());
}

void RTWaveNetAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    audioProcessor.addedInGain = inGain->getValue();
    audioProcessor.addedOutGain = outGain->getValue();
}
