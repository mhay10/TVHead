# TVHead

A project that controls a tv through composite video and displays different expressions.

### Electronic Components

 - 8 - 1k Ω Resistor
 - 5 - 220 Ω Resistor
 - 1 - Arduino Nano
 - 7 - Push Button
 - 1 - Female Composite Connector
 - 2 - Adafruit Perma-Proto 1/2 Sized Breadboard
 - 1 - Female Headers

### Required Tools

 - Soldering Iron
 - Solder
 - 3D Printer or 3D Printing Service
 - Arduino IDE

### Creating Custom Expressions

  1. Create a Black & White 16x16 image of the expression you want
  2. Run the `ImageToHex.py` script in the `images` folder
  3. Add the generated hex data to `expressions.cpp`
  4. Give the expression the correct value in `expressions.h`
