#!/usr/bin/env python3

import sys, math, os
from PIL import Image

if len(sys.argv) < 2:
    print(f"Usage: {sys.argv[0]} <romfile> [offset]")
    exit(1)

with open(sys.argv[1], 'rb') as ris:
    rom = ris.read()

offset = 0 if len(sys.argv) < 3 else int(sys.argv[2]) % 3
rom = rom[offset:]

imageWidth = math.ceil(math.sqrt(len(rom)*8))
imageHeight = len(rom)*8 // imageWidth

pngName = os.path.splitext(sys.argv[1])[0] + f"_{offset}.png"

print (f"Generating image {pngName} of size {imageWidth}x{int(imageHeight)} from offset {offset}...")

bits = []
for byte in rom:
    for i in range(8):
        bits.append(0 if (byte >> (7 - i)) & 1 else 255)
bits += [0] * (imageWidth*imageHeight - len(bits))

img = Image.frombytes("L", (imageWidth, imageHeight), bytes(bits)).transpose(Image.TRANSPOSE)
img.save(pngName)

print("Done.")
