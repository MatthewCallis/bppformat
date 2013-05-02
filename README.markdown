# BPPFormat

This is a photoshop plug-in to read / write to various BPP (1BPP, 2BPP, 3BPP, 4BPP, 8BPP) formats used by various video game systems (GB, NES, SNES).

## Building

This expects the project folder to live next to the [photoshopsdk](http://www.adobe.com/devnet/photoshop/sdk.html) folder and the SDK to be adjected as described in [this thread](http://forums.adobe.com/thread/1115040?tstart=0) also recreated below. The project must be built in 64 bit only, and use 10.7 as the base SDK, 10.8 will not work. Windows, probably the same folder setup?

```
~/photoshopsdk
~/bppformat
```

### Fixing the SDK
Comment out those header includes:

```
SDK common/includes/PIUFile.h
  #include <Folders.h>

SDK common/includes/PIUtilities.h
  #include <LowMem.h>
  #include <ToolUtils.h>
  #include <FixMath.h>

SDK common/includes/DialogUtilities.h
  #include <Diaglos.h>
  #include <Types.h>
  #include <Gestalt.h>
  #include <TextUtils.h>
  #include <OSUtils.h>
  #include <Menus.h>

SDK common/includes/PiUi.h
  #include "Lists.h"
```
