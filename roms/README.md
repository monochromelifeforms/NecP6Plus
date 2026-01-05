# ROMs

There are two 64kB ROMs, split into odd (183) and even (182), for a total of 128k.

The ROMs themselves are not in this repo. I figure if you're here, you have the printer yourself and can dump the ROMs yourself.

## Processing

Since there are two ROMs, and I did not have a ROM merging tool at hand, I quickly wrote one myself (`merge.cpp`).

The `rom2img.py` python script exports the ROM into a PNG image file, interpreting each bit as either black or white, depending on its value, grouped in bytes of three (for the 24 pins).
I was hoping that I copuld "see" where the fonts may be located, but without luck so far.

The next step is to disassemble the ROM. The printer runs a V50 processor, which is an embedded x86-compatible processor. Assuming the ROM is located at 0xE000 (so that it ends at 0xFFFF), we can start with the reset vector at 0xFFF0. There is indeed a `jmp` instruction there. I have not proceeded beyond that point.
