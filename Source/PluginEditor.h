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
class FIRFilterAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    FIRFilterAudioProcessorEditor (FIRFilterAudioProcessor&);
    ~FIRFilterAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FIRFilterAudioProcessor& audioProcessor;

    juce::Slider filterCutoffDial;

    juce::ScopedPointer <juce::AudioProcessorValueTreeState::SliderAttachment> filterCutoffValue;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FIRFilterAudioProcessorEditor)
};
