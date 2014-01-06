/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_ADC62037F71138AA__
#define __JUCE_HEADER_ADC62037F71138AA__

//[Headers]     -- You can add your own extra header files here --
/*
 * Copyright (c) 2013 - Teragon Audio LLC
 *
 * Permission is granted to use this software under the terms of either:
 * a) the GPL v2 (or any later version)
 * b) the Affero GPL v3
 *
 * Details of these licenses can be found at: www.gnu.org/licenses
 *
 * This software is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * ------------------------------------------------------------------------------
 *
 * This software uses the JUCE library.
 *
 * To release a closed-source product which uses JUCE, commercial licenses are
 * available: visit www.juce.com for more information.
 */
#include "JuceHeader.h"
#include "TeragonGuiComponents.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ConfirmClearDialog  : public Component,
                            public teragon::ParameterObserver
{
public:
    //==============================================================================
    ConfirmClearDialog (teragon::ConcurrentParameterSet &p, teragon::ResourceCache *r);
    ~ConfirmClearDialog();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    // PluginParameterObserver methods
    bool isRealtimePriority() const { return false; }
    void onParameterUpdated(const teragon::Parameter *parameter);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* confirmcleardialog_png;
    static const int confirmcleardialog_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    teragon::ConcurrentParameterSet &parameters;
    teragon::ResourceCache *resources;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<teragon::ToggleButton> cancelButton;
    ScopedPointer<teragon::ToggleButton> confirmButton;
    Image cachedImage_confirmcleardialog_png;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ConfirmClearDialog)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_ADC62037F71138AA__
