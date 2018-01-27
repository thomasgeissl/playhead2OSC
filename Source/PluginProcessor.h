/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
*/
class Playhead2oscAudioProcessor  : public AudioProcessor, public Timer
{
public:
    //==============================================================================
    Playhead2oscAudioProcessor();
    ~Playhead2oscAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect () const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    
    static String invertPhaseToText (float value)
    {
        return value < 0.5 ? "Normal" : "Inverted";
    }
    
    static float textToInvertPhase (const String& text)
    {
        if (text == "Normal")    return 0.0f;
        if (text == "Inverted")  return 1.0f;
        return 0.0f;
    }
    
    void timerCallback();
    bool connect(String address, int port = 9001);
    
 
private:
    //==============================================================================
    AudioProcessorValueTreeState parameters;
    OSCSender _sender;
    AudioPlayHead::CurrentPositionInfo _currentTime;
    bool _noErrorTryingToGetTime;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Playhead2oscAudioProcessor)
};
