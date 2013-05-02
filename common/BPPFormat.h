//  File:
//    BPPFormat.h
//
//  Description:
//    This file contains the header prototypes and macros for the File Format module BPPFormat,
//    which writes a flat file with merged document pixels.
//
//  Use:
//    Format modules are called from the Save, Save as, and Save a copy dialogs.
//
//-------------------------------------------------------------------------------

#ifndef __BPPFormat_H__  // Has this not been defined yet?
#define __BPPFormat_H__  // Only include this once by predefining it

#include "PIDefines.h"
#include "PIFormat.h"         // Format Photoshop header file.
#include "PIUtilities.h"        // SDK Utility library.
#include "FileUtilities.h"        // File Utility library.
#include "BPPFormatTerminology.h"  // Terminology for plug-in.
#include <string>
#include <vector>

using namespace std;

//-------------------------------------------------------------------------------
//  Structure -- FileHeader
//-------------------------------------------------------------------------------
typedef struct HeaderVer2 {
  char identifier [8];

  int16 endian;
  int16 testendian;

  int16 mode;
  int16 depth;
  int32 rows;
  int32 cols;
  int16 planes;

  int32 transparencyPlane;

  int32 resourceLength;

} FileHeader;

typedef struct HeaderVer1 {
  int16 mode;
  int16 depth;
  int16 rows;
  int16 cols;
  int16 planes;

  int32 resourceLength;
} Header16BitRowsCols;


//-------------------------------------------------------------------------------
//  Data -- Structures
//-------------------------------------------------------------------------------
typedef struct Data {
  bool needsSwap;
  Boolean openAsSmartObject;
} Data;

typedef struct ResourceInfo {
  uint32 totalSize;
  uint32 type;
  uint16 id;
  string name;
  uint32 size;
  bool keep;
} ResourceInfo;

extern SPPluginRef gPluginRef;
extern FormatRecord * gFormatRecord;
extern Data * gData;
extern int16 * gResult;

//-------------------------------------------------------------------------------
//  Prototypes
//-------------------------------------------------------------------------------
void DoAbout (AboutRecordPtr about); // Pop about box.

bool DoUI (vector<ResourceInfo *> & rInfos);

// During read phase:
Boolean ReadScriptParamsOnRead (void);  // Read any scripting params.
OSErr WriteScriptParamsOnRead (void);   // Write any scripting params.

// During write phase:
Boolean ReadScriptParamsOnWrite (void); // Read any scripting params.
OSErr WriteScriptParamsOnWrite (void);  // Write any scripting params.

#endif // __BPPFormat_H__
