/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef __PLUGINEDITOR_H_EC4F709B__
#define __PLUGINEDITOR_H_EC4F709B__

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class ExtraNotesAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    ExtraNotesAudioProcessorEditor (ExtraNotesAudioProcessor* ownerFilter);
    ~ExtraNotesAudioProcessorEditor();

    //==============================================================================
    // This is just a standard Juce paint method...
    void paint (Graphics& g);
};


#endif  // __PLUGINEDITOR_H_EC4F709B__
