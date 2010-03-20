/*
 *  NoteWriter.h
 *  AUNotes
 *
 *  Created by Nik Reiman on 2010-03-20.
 *  Copyright 2010 Teragon Audio. All rights reserved.
 *
 */

#ifndef __NoteWriter_h__
#define __NoteWriter_h__

namespace teragon {
  namespace AUNotes {
    class NoteWriter {
    public:
      NoteWriter() {};
      virtual ~NoteWriter() {};
      
      virtual void setNote(const char* note) = 0;
    };
  }
}

#endif