/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
Playhead2oscAudioProcessor::Playhead2oscAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
    parameters(*this, nullptr)

#endif
{
    parameters.createAndAddParameter ("bpm", "bpm", String(),
                                      NormalisableRange<float> (0.0f, 1.0f, 1.0f), 0.0f,
                                      invertPhaseToText,    // value to text function
                                      textToInvertPhase);   // text to value function
    parameters.createAndAddParameter ("timeSignature", "timeSignature", String(),
                                      NormalisableRange<float> (0.0f, 1.0f, 1.0f), 0.0f,
                                      invertPhaseToText,    // value to text function
                                      textToInvertPhase);   // text to value function
    parameters.createAndAddParameter ("timeInSeconds", "timeInSeconds", String(),
                                      NormalisableRange<float> (0.0f, 1.0f, 1.0f), 0.0f,
                                      invertPhaseToText,    // value to text function
                                      textToInvertPhase);   // text to value function
    parameters.createAndAddParameter ("isPlaying", "isPlaying", String(),
                                      NormalisableRange<float> (0.0f, 1.0f, 1.0f), 0.0f,
                                      invertPhaseToText,    // value to text function
                                      textToInvertPhase);   // text to value function
    parameters.createAndAddParameter ("isRecording", "isRecording", String(),
                                      NormalisableRange<float> (0.0f, 1.0f, 1.0f), 0.0f,
                                      invertPhaseToText,    // value to text function
                                      textToInvertPhase);   // text to value function
    parameters.createAndAddParameter ("isLooping", "isLooping", String(),
                                      NormalisableRange<float> (0.0f, 1.0f, 1.0f), 0.0f,
                                      invertPhaseToText,    // value to text function
                                      textToInvertPhase);   // text to value function
    
    parameters.state = ValueTree (Identifier ("playhead2OSCParameters"));
    
    
    _sender.connect ("127.0.0.1", 9001);
//    _sender.send("/info", "connected to default ip and port");
    
    
    startTimerHz(60);
}

Playhead2oscAudioProcessor::~Playhead2oscAudioProcessor()
{
}

//==============================================================================
const String Playhead2oscAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Playhead2oscAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Playhead2oscAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Playhead2oscAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Playhead2oscAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Playhead2oscAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Playhead2oscAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Playhead2oscAudioProcessor::setCurrentProgram (int index)
{
}

const String Playhead2oscAudioProcessor::getProgramName (int index)
{
    return {};
}

void Playhead2oscAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Playhead2oscAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void Playhead2oscAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Playhead2oscAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Playhead2oscAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    if (AudioPlayHead* ph = getPlayHead())
    {
        AudioPlayHead::CurrentPositionInfo newTime;
        _noErrorTryingToGetTime = ph->getCurrentPosition (_currentTime);

    }
}

//==============================================================================
bool Playhead2oscAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Playhead2oscAudioProcessor::createEditor()
{
    return new Playhead2oscAudioProcessorEditor (*this, parameters);
}

//==============================================================================
void Playhead2oscAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Playhead2oscAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Playhead2oscAudioProcessor();
}

bool Playhead2oscAudioProcessor::connect(String address, int port){
    _sender.send("/"+getName()+"/info/connect", (int)(port));
    return _sender.connect(address, port);
}

void Playhead2oscAudioProcessor::timerCallback(){
    if(_noErrorTryingToGetTime){
        
        if(*parameters.getRawParameterValue ("bpm") > 0.5f){
            auto bpm = _currentTime.bpm;
            _sender.send ("/"+getName()+"/bpm", (float) (bpm));
        }
        
        if(*parameters.getRawParameterValue ("timeSignature") > 0.5f){
            auto timeSigNumerator = _currentTime.timeSigNumerator;
            auto timeSigDemominator = _currentTime.timeSigDenominator;
            _sender.send("/"+getName()+"/signature", (int) timeSigNumerator, (int) timeSigDemominator);
        }
        
        if(*parameters.getRawParameterValue ("timeInSeconds") > 0.5f){
            auto timeInSeconds = _currentTime.timeInSeconds;
            _sender.send ("/"+getName()+"/timeInSeconds", (float) (timeInSeconds));
        }
        
        if(*parameters.getRawParameterValue ("isPlaying") > 0.5f){
            auto isPlaying = _currentTime.isPlaying;
            _sender.send ("/"+getName()+"/isPlaying", (bool) (isPlaying));
        }
        
        if(*parameters.getRawParameterValue ("isRecording") > 0.5f){
            auto isRecording = _currentTime.isRecording;
            _sender.send ("/"+getName()+"/isRecording", (bool) (isRecording));
        }
        
        if(*parameters.getRawParameterValue ("isLooping") > 0.5f){
            auto isLooping = _currentTime.isLooping;
            _sender.send ("/"+getName()+"/isLooping", (bool) (isLooping));
        }
    }
    
}

