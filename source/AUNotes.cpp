/*
 *	File:		AUNotes.cpp
 *	
 *	Version:	1.0
 * 
 *	Created:	17.12.05
 *	
 *	Copyright:  Copyright � 2005 Teragon Audio, All Rights Reserved
 *
 */

#ifndef __AUNotes_H
#include "AUNotes.h"
#endif

namespace teragon {
  namespace AUNotes {
    COMPONENT_ENTRY(AUNotes)
    
    AUNotes::AUNotes(AudioUnit component)	: AUEffectBase(component) {
      CreateElements();
      Globals()->UseIndexedParameters(0);
      
      this->noteReader = NULL;
      this->noteWriter = NULL;
    }
    
    AUNotes::~AUNotes() {
    }
    
    void AUNotes::GetUIComponentDescs(ComponentDescription* inDescArray) {
      inDescArray[0].componentType = kAudioUnitCarbonViewComponentType;
      inDescArray[0].componentSubType = AUNotes_COMP_SUBTYPE;
      inDescArray[0].componentManufacturer = AUNotes_COMP_MANF;
      inDescArray[0].componentFlags = 0;
      inDescArray[0].componentFlagsMask = 0;
    };
    
    ComponentResult AUNotes::GetProperty(AudioUnitPropertyID inId,
                                         AudioUnitScope inScope,
                                         AudioUnitElement inElement,
                                         void* outData) {
      ComponentResult result;
      
      switch(inId) {
        case kNoteReaderPropertyId:
          outData = dynamic_cast<NoteReader*>(this);
          result = noErr;
          break;
        default:
          result = AUEffectBase::GetProperty(inId, inScope, inElement, outData);
          break;
      }
      
      return result;
    }
    
    ComponentResult AUNotes::GetPropertyInfo(AudioUnitPropertyID inId,
                                             AudioUnitScope inScope,
                                             AudioUnitElement inElement,
                                             UInt32& outDataSize,
                                             Boolean& outWritable) {
      ComponentResult result;
      
      switch(inId) {
        case kNoteReaderPropertyId:
          outDataSize = sizeof(NoteReader*);
          result = noErr;
          break;
        case kNoteWriterPropertyId:
          outDataSize = sizeof(NoteWriter*);
          result = noErr;
          break;
        default:
          result = AUEffectBase::GetPropertyInfo(inId, inScope, inElement, outDataSize, outWritable);
          break;
      }
      return result;
    }
    
    ComponentResult AUNotes::SetProperty(AudioUnitPropertyID inId,
                                         AudioUnitScope inScope,
                                         AudioUnitElement inElement,
                                         const void *inData,
                                         UInt32 inDataSize) {
      ComponentResult result;
      
      switch(inId) {
        case kNoteReaderPropertyId:
          this->noteReader = reinterpret_cast<const NoteReader*>(inData);
          result = noErr;
          break;
        case kNoteWriterPropertyId:
        {
          // The note writer pointer cannot be const, since that interface method
          // is not const, so first we need to get a pointer to the interface and
          // then discard the const-ness of the pointer.
          const NoteWriter *noteWriterPtr = reinterpret_cast<const NoteWriter*>(inData);
          this->noteWriter = const_cast<NoteWriter*>(noteWriterPtr);
          result = noErr;
        }
          break;
        default:
          result = AUEffectBase::SetProperty(inId, inScope, inElement, inData, inDataSize);
          break;
      }
      
      return result;
    }
    
    ComponentResult AUNotes::SaveState(CFPropertyListRef *outData) {
      ComponentResult err = AUBase::SaveState(outData);
      
      if(this->noteReader != NULL) {
        CFStringRef noteText = this->noteReader->getNote();
        outData = (const void**)&noteText;
      }
      
      return err;
    }
    
    ComponentResult AUNotes::RestoreState(CFPropertyListRef inData) {
      ComponentResult err = AUBase::RestoreState(inData);
      
      if(this->noteWriter != NULL) {
        const CFStringRef noteText = (CFStringRef)inData;
        this->noteWriter->setNote(noteText);
      }
      
      return err;
    }
    
    // NoteReader interface
    const CFStringRef AUNotes::getNote() const {
      return NULL;
    }
    
    // NoteWriter interface
    void AUNotes::setNote(const CFStringRef note) {
    }
  }
}
