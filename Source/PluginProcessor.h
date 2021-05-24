/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class FIRFilterAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    FIRFilterAudioProcessor();
    ~FIRFilterAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    void updateFilter();

    float minFilterCutoff = 20.0f;
    float maxFilterCutoff = 20000.0f;
    float defaultFilterCutoff = 500.0f;

    float minFilterResonance = 0.1f;
    float maxFilterResonance = 10.f;
    float defaultFilterResonance = 2.f;

    float minFilterTypeMenu = 0;
    float maxFilterTypeMenu = 10;
    float defaultFilterTypeMenu = 0;

    float minFilterGainFactor = 1;
    float maxFilterGainFactor = 100;
    float defaultFilterGainFactor = 1;


    std::string filterCutoffId = "filterCutoff";
    std::string filterCutoffName = "Cutoff";

    std::string filterResonanceId = "filteResonance";
    std::string filterResonanceName = "Resonance";

    std::string filterTypeMenuId = "filteTypeMenu";
    std::string filterTypeMenuName = "Type";

    std::string filterGainFactorId = "filterGainFactor";
    std::string filterGainFactorName = "Gain Factor";

    juce::AudioProcessorValueTreeState treeState;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FIRFilterAudioProcessor)
};
