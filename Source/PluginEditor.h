/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;

//==============================================================================
/**
*/
class Playhead2oscAudioProcessorEditor  : public AudioProcessorEditor, public TextEditor::Listener
{
public:
    Playhead2oscAudioProcessorEditor (Playhead2oscAudioProcessor& p, AudioProcessorValueTreeState& valueTreeState);
    ~Playhead2oscAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void textEditorReturnKeyPressed (TextEditor& textEditor) override;

private:
    Playhead2oscAudioProcessor& _processor;
    AudioProcessorValueTreeState& _valueTreeState;
    
    ToggleButton _bpmToggleButton, _timeSignatureToggleButton, _timeInSecondsToggleButton, _isPlayingToggleButton, _isRecordingToggleButton, _isLoopingToggleButton;
    ScopedPointer<ButtonAttachment> _bpmToggleButtonAttachment, _timeSignatureToggleButtonAttachment, _timeInSecondsToggleButtonAttachment, _isPlayingToggleButtonAttachment, _isRecordingToggleButtonAttachment, _isLoopingToggleButtonAttachment;
    
    TextEditor _remoteHostTextEditor, _remotePortTextEditor;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Playhead2oscAudioProcessorEditor)
};
