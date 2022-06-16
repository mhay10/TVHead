from functools import reduce
from operator import mul
from PIL import Image
import sys

binToHex = {
    "0000": "0",
    "0001": "1",
    "0010": "2",
    "0011": "3",
    "0100": "4",
    "0101": "5",
    "0110": "6",
    "0111": "7",
    "1000": "8",
    "1001": "9",
    "1010": "a",
    "1011": "b",
    "1100": "c",
    "1101": "d",
    "1110": "e",
    "1111": "f",
}


def toHex(binary):
    return "0x" + binToHex[binary[:4]] + binToHex[binary[4:]]


def convert(lst, shape):
    if len(shape) == 1:
        return lst

    n = reduce(mul, shape[1:])
    return [convert(lst[i * n : (i + 1) * n], shape[1:]) for i in range(len(lst) // n)]


if len(sys.argv) == 2:
    print("Usage: python ImageToHex.py <img path>")

path = sys.argv[1]
img = Image.open(path).convert("L")
width, height = img.size

pixels = []
for pixel in img.getdata():
    pixels.append(0 if pixel < 255 else 1)
pixels = convert(pixels, (width, height))

chop = 8
tiles = {}
for i in range(0, width, chop):
    for j in range(0, height, chop):
        tile = []
        for k in range(chop):
            row = ""
            for l in range(chop):
                row += str(pixels[i + k][j + l])

            tile.append(row)

        tiles[f"From ({i},{j}) to ({i+chop},{j+chop}): "] = tile

vals = []
for tile, data in tiles.items():
    print(tile, end="")

    tileVals = []
    for row in data:
        val = toHex(row)
        vals.append(val)
        tileVals.append(val)

    print(", ".join(tileVals))

print("\nRaw Hex Data: ", ", ".join(vals))
