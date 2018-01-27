/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
Playhead2oscAudioProcessorEditor::Playhead2oscAudioProcessorEditor (Playhead2oscAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), _processor (p), _valueTreeState(vts)
{

    
    setOpaque (true);
    addAndMakeVisible (_remoteHostTextEditor);
    addAndMakeVisible (_remotePortTextEditor);
    
    _remoteHostTextEditor.addListener(this);
    _remoteHostTextEditor.setInputRestrictions(15, "0123456789.");
    _remoteHostTextEditor.setReturnKeyStartsNewLine(false);
    _remoteHostTextEditor.setText("127.0.0.1");
    _remoteHostTextEditor.unfocusAllComponents();

    
    _remotePortTextEditor.addListener(this);
    _remotePortTextEditor.setInputRestrictions(5, "0123456789");
    _remotePortTextEditor.setReturnKeyStartsNewLine(false);
    _remotePortTextEditor.setText("9001");
    _remotePortTextEditor.unfocusAllComponents();

    
    _bpmToggleButton.setButtonText ("BPM");
    addAndMakeVisible (_bpmToggleButton);
    _bpmToggleButtonAttachment = new ButtonAttachment (_valueTreeState, "bpm", _bpmToggleButton);
    
    _timeSignatureToggleButton.setButtonText ("Time Signature");
    addAndMakeVisible (_timeSignatureToggleButton);
    _timeSignatureToggleButtonAttachment = new ButtonAttachment (_valueTreeState, "timeSignature", _timeSignatureToggleButton);
    
    _timeInSecondsToggleButton.setButtonText ("Time In Seconds");
    addAndMakeVisible (_timeInSecondsToggleButton);
    _timeInSecondsToggleButtonAttachment = new ButtonAttachment (_valueTreeState, "timeInSeconds", _timeInSecondsToggleButton);
    
    _isPlayingToggleButton.setButtonText ("Is Playing");
    addAndMakeVisible (_isPlayingToggleButton);
    _isPlayingToggleButtonAttachment = new ButtonAttachment (_valueTreeState, "isPlaying", _isPlayingToggleButton);

    _isRecordingToggleButton.setButtonText ("Is Recording");
    addAndMakeVisible (_isRecordingToggleButton);
    _isRecordingToggleButtonAttachment = new ButtonAttachment (_valueTreeState, "isRecording", _isRecordingToggleButton);
    
    _isLoopingToggleButton.setButtonText ("Is Looping");
    addAndMakeVisible (_isLoopingToggleButton);
    _isLoopingToggleButtonAttachment = new ButtonAttachment (_valueTreeState, "isLooping", _isLoopingToggleButton);
    
    
    setSize (400, 300);
}

Playhead2oscAudioProcessorEditor::~Playhead2oscAudioProcessorEditor()
{
}

//==============================================================================
void Playhead2oscAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

}

void Playhead2oscAudioProcessorEditor::resized()
{
    Rectangle<int> r = getLocalBounds();
    _remoteHostTextEditor.setBounds(r.removeFromTop (25));
    _remotePortTextEditor.setBounds(r.removeFromTop (25));

    _bpmToggleButton.setBounds (r.removeFromTop (25));
    _timeSignatureToggleButton.setBounds (r.removeFromTop (25));
    _timeInSecondsToggleButton.setBounds (r.removeFromTop (25));
    _isPlayingToggleButton.setBounds (r.removeFromTop (25));
    _isRecordingToggleButton.setBounds (r.removeFromTop (25));
    _isLoopingToggleButton.setBounds (r.removeFromTop (25));
}

void Playhead2oscAudioProcessorEditor::textEditorReturnKeyPressed (TextEditor & textEditor){
    textEditor.unfocusAllComponents();
    _processor.connect(_remoteHostTextEditor.getText(), _remotePortTextEditor.getText().getIntValue());
}

