# ROMs

The ROMs can be found here:
[NEC PinWriter P6 plus ROMs on the Internet Archive](https://archive.org/download/NecPinWriterP6PlusRoms)

The copyright resides with NEC.

## Processing

There are two 64kB ROMs, split into even (18?) and odd (18?).

Since I did not have a ROM merging tool at hand, I quickly wrote one myself (`merge.cpp`).

The `rom2img.py` python script exports the ROM into a PNG image file, in order to try to "see" where the fonts may be located.
(Without luck so far.)
