#include "expressions.h"
#include <TVout.h>

#define DEBUG false

// happy, sad, angry, tired, broken, surprised, skeptical
const int pins[7] = {3, 4, 5, 6, 8, 10, 11};
int pinStates[7];
int pressed;

// Eye positions
const int leftx = 3, lefty = 5;
const int rightx = 12, righty = 5;

TVout win;
int x, y;

char exprLeft, exprRight;

void setup() {
  // Enable logging for debug
  if (DEBUG) Serial.begin(115200);

  // Initialize pins
  for (int pin : pins) pinMode(pin, INPUT);

  // Initialize screen
  win.begin(NTSC);
  win.select_font(expr8x8);
}

void loop() {
  // Clear screen before drawing again 
  win.clear_screen();

  // Get pin states
  for (int i = 0; i < 7; i++) pinStates[i] = digitalRead(pins[i]);

  // Print pin states if debug enabled
  if (DEBUG) {
    for (int state : pinStates) Serial.print(String(state) + " ");
    Serial.println();
  }

  // Set expression based on button push
  pressed = get_pressed();
  switch (pressed) {
    case 0:
      set_expression(HAPPY, HAPPY);
      break;
    case 1:
      set_expression(SAD_L, SAD_R);
      break;
    case 2:
      set_expression(ANGRY_L, ANGRY_R);
      break;
    case 3:
      set_expression(TIRED, TIRED);
      break;
    case 4:
      set_expression(BROKEN, BROKEN);
      break;
    case 5:
      set_expression(SURPRISED, SURPRISED);
      break;
    case 6:
      set_expression(SKEPTICAL, SKEPTICAL);
      break;
    default:
      set_expression(NEUTRAL, NEUTRAL);
      break;
  }

  print_eyes(exprLeft, exprRight);

  win.delay(1);
}

void set_expression(char left, char right) {
  exprLeft = left;
  exprRight = right;
}

void print_eyes(char leftc, char rightc) {
  // Print expression to the screen
  print_char(leftc, leftx, lefty);
  print_char(rightc, rightx, righty);
}

void print_char(char c, int startx, int starty) {
  // Each expression made up of 4 tiles in square
  win.print_char(startx * 8, starty * 8, c);
  win.print_char((startx + 1) * 8, starty * 8, c + 1);
  win.print_char(startx * 8, (starty + 1) * 8, c + 2);
  win.print_char((startx + 1) * 8, (starty + 1) * 8, c + 3);
}

int get_pressed() {
  // Get first pressed pin
  for (int i = 0; i < 7; i++)
    if (pinStates[i]) return i;

  return -1;
}
