#!/usr/bin/env python3

import sys, math, os
from PIL import Image

if len(sys.argv) < 2:
    print(f"Usage: {sys.argv[0]} <romfile> [bytes per column]")
    exit(1)

with open(sys.argv[1], 'rb') as ris:
    rom = ris.read()

bytesPerColumn = 3 if len(sys.argv) < 3 else int(sys.argv[2])
bitsPerColumn = bytesPerColumn * 8

imageWidth = 1024 # ~sqrt(128k)
imageHeight = len(rom)*8 // imageWidth + bytesPerColumn*8 # Add some extra height to avoid problems.

for offset in range(bytesPerColumn):
    pngName = os.path.splitext(sys.argv[1])[0] + f"_{offset}.png"
    
    print (f"Generating image {pngName} of size {imageWidth}x{int(imageHeight)} from offset {offset}...")
    
    bits = [127]*imageWidth*imageHeight # Grey by default, to see what is being overwritten.
    column = 0
    rowOffset = 0
    for byte in rom:
        for i in range(8):
            bits[column + (rowOffset+i) * imageWidth] = 255 if (byte & (1 << (7 - i))) > 0 else 0
        rowOffset += 8
        if rowOffset % bitsPerColumn == 0 : # We assume 3 bytes per character column.
            rowOffset -= bitsPerColumn
            column += 1
        if column >= imageWidth:
            column = 0
            rowOffset += bitsPerColumn
    
    img = Image.frombytes("L", (imageWidth, imageHeight), bytes(bits))
    img.save(pngName)

    rom = rom[1:] # Shift offset by one byte for next image.

print("Done.")
