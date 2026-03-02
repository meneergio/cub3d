#!/usr/bin/env python3
import sys
from PIL import Image

def png_to_xpm(input_file, output_file, size=64):
    img = Image.open(input_file).resize((size, size)).convert("RGB")
    pixels = list(img.getdata())
    width, height = img.size

    # build color table
    color_map = {}
    chars = []
    char_pool = (
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%^&*()-_=+[]{}|;:,.<>?"
    )
    idx = 0
    for pixel in pixels:
        key = pixel
        if key not in color_map:
            if idx >= len(char_pool):
                # fallback: use 2-char codes
                c = char_pool[idx // len(char_pool) - 1] + char_pool[idx % len(char_pool)]
            else:
                c = char_pool[idx]
            color_map[key] = c
            idx += 1

    cpp = 2 if len(color_map) > len(char_pool) else 1

    # rebuild with correct cpp
    color_map = {}
    idx = 0
    for pixel in pixels:
        key = pixel
        if key not in color_map:
            if cpp == 1:
                c = char_pool[idx % len(char_pool)]
            else:
                c = char_pool[(idx // len(char_pool)) % len(char_pool)] + char_pool[idx % len(char_pool)]
            color_map[key] = c
            idx += 1

    with open(output_file, 'w') as f:
        f.write("/* XPM */\n")
        f.write("static char *texture[] = {\n")
        f.write(f'"{width} {height} {len(color_map)} {cpp}",\n')

        for rgb, c in color_map.items():
            hex_color = "#{:02x}{:02x}{:02x}".format(*rgb)
            f.write(f'"{c} c {hex_color}",\n')

        for y in range(height):
            row = ""
            for x in range(width):
                pixel = pixels[y * width + x]
                row += color_map[pixel]
            if y < height - 1:
                f.write(f'"{row}",\n')
            else:
                f.write(f'"{row}"\n')

        f.write("};\n")

    print(f"Done: {output_file} ({len(color_map)} colors, cpp={cpp})")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("usage: python3 png_to_xpm.py input.png output.xpm [size]")
        print("example: python3 png_to_xpm.py north.png north.xpm 64")
        sys.exit(1)
    size = int(sys.argv[3]) if len(sys.argv) > 3 else 64
    png_to_xpm(sys.argv[1], sys.argv[2], size)
