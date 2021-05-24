/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FIRFilterAudioProcessorEditor::FIRFilterAudioProcessorEditor (FIRFilterAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);


    filterCutoffDial.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    filterCutoffDial.setRange(audioProcessor.minFilterCutoff, audioProcessor.maxFilterCutoff);
    filterCutoffDial.setValue(audioProcessor.defaultFilterCutoff);
    filterCutoffDial.setTextValueSuffix("hz");
    filterCutoffDial.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);

    addAndMakeVisible(&filterCutoffDial);


    filterCutoffValue = new juce::AudioProcessorValueTreeState::SliderAttachment
    (audioProcessor.treeState, audioProcessor.filterCutoffId, filterCutoffDial);

}

FIRFilterAudioProcessorEditor::~FIRFilterAudioProcessorEditor()
{
}

//==============================================================================
void FIRFilterAudioProcessorEditor::paint (juce::Graphics& g)
{
  
}

void FIRFilterAudioProcessorEditor::resized()
{
    filterCutoffDial.setBounds(getLocalBounds().reduced(20));
}
