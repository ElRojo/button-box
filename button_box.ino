// #define HALF_STEP // uncomment if using half-step encoders
#define ENABLE_PULLUPS // comment this line if using rotary encoders with built-in pull-ups

#include <Keypad.h>
#include <Joystick.h>

constexpr int NUMROTARIES = 4;
constexpr int NUMROWS = 4; // set rows here
constexpr int NUMCOLS = 4; // set columns here
constexpr int NUMBUTTONS = 16; // set button count here depending on matrix

// button matrix setup. update if numrows/numcols changes
const byte buttons[NUMROWS][NUMCOLS] = {
  {0, 1, 2, 3},
  {4, 5, 6, 7},
  {8, 9, 10, 11},
  {12, 13, 14, 15}
};

// arduino pins for rows and columns
byte rowPins[NUMROWS] = {21,20,19,18};
byte colPins[NUMCOLS] = {15,14,16,10};

struct RotaryEncoder {
  byte pin1;
  byte pin2;
  int ccwchar;
  int cwchar;
  volatile unsigned char state;
};

RotaryEncoder rotaries[NUMROTARIES] {
  {3, 2, 15, 17, 0},
  {5, 4, 18, 19, 0},
  {7, 6, 20, 21, 0},
  {9, 8, 22, 23, 0}
};


Keypad buttbx = Keypad( makeKeymap(buttons), rowPins, colPins, NUMROWS, NUMCOLS);
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,
  JOYSTICK_TYPE_JOYSTICK, 32, 0,
  false, false, false, false, false, false,
  false, false, false, false, false);

constexpr uint8_t DIR_CCW = 0x10;
constexpr uint8_t DIR_CW = 0x20;
constexpr uint8_t R_START = 0x0;

#ifdef HALF_STEP
constexpr uint8_t R_CCW_BEGIN = 0x1;
constexpr uint8_t R_CW_BEGIN = 0x2;
constexpr uint8_t R_START_M = 0x3;
constexpr uint8_t R_CW_BEGIN_M = 0x4;
constexpr uint8_t R_CCW_BEGIN_M = 0x5;
const unsigned char ttable[6][4] = {
  // R_START (00)
  {R_START_M,            R_CW_BEGIN,     R_CCW_BEGIN,  R_START},
  // R_CCW_BEGIN
  {R_START_M | DIR_CCW, R_START,        R_CCW_BEGIN,  R_START},
  // R_CW_BEGIN
  {R_START_M | DIR_CW,  R_CW_BEGIN,     R_START,      R_START},
  // R_START_M (11)
  {R_START_M,            R_CCW_BEGIN_M,  R_CW_BEGIN_M, R_START},
  // R_CW_BEGIN_M
  {R_START_M,            R_START_M,      R_CW_BEGIN_M, R_START | DIR_CW},
  // R_CCW_BEGIN_M
  {R_START_M,            R_CCW_BEGIN_M,  R_START_M,    R_START | DIR_CCW},
};
#else

constexpr uint8_t R_CW_BEGIN = 0x2;
constexpr uint8_t R_CW_FINAL = 0x1;
constexpr uint8_t R_CW_NEXT = 0x3;
constexpr uint8_t R_CCW_BEGIN = 0x4;
constexpr uint8_t R_CCW_FINAL = 0x5;
constexpr uint8_t R_CCW_NEXT = 0x6;
const unsigned char ttable[7][4] = {
  // R_START
  {R_START,    R_CW_BEGIN,  R_CCW_BEGIN, R_START},
  // R_CW_FINAL
  {R_CW_NEXT,  R_START,     R_CW_FINAL,  R_START | DIR_CW},
  // R_CW_BEGIN
  {R_CW_NEXT,  R_CW_BEGIN,  R_START,     R_START},
  // R_CW_NEXT
  {R_CW_NEXT,  R_CW_BEGIN,  R_CW_FINAL,  R_START},
  // R_CCW_BEGIN
  {R_CCW_NEXT, R_START,     R_CCW_BEGIN, R_START},
  // R_CCW_FINAL
  {R_CCW_NEXT, R_CCW_FINAL, R_START,     R_START | DIR_CCW},
  // R_CCW_NEXT
  {R_CCW_NEXT, R_CCW_FINAL, R_CCW_BEGIN, R_START},
};
#endif


void initEncoders() {
  for (int i = 0; i < NUMROTARIES; i++) {
    pinMode(rotaries[i].pin1, INPUT);
    pinMode(rotaries[i].pin2, INPUT);
    #ifdef ENABLE_PULLUPS
      digitalWrite(rotaries[i].pin1, HIGH);
      digitalWrite(rotaries[i].pin2, HIGH);
    #endif
  }
}

void checkAllButtons() {
    if (!buttbx.getKeys()) return;
        for (int i = 0; i < LIST_MAX; ++i) {
            if (!buttbx.key[i].stateChanged) continue;
                bool isPressed = (buttbx.key[i].kstate == PRESSED || buttbx.key[i].kstate == HOLD);
                Joystick.setButton(buttbx.key[i].kchar, isPressed);
    }
}

void checkAllEncoders(void) {
  for (int i = 0; i < NUMROTARIES; i++) {
    unsigned char result = processEncoder(i);
    if (result == DIR_CCW) {
      Joystick.setButton(rotaries[i].ccwchar, 1);
      delay(50);
      Joystick.setButton(rotaries[i].ccwchar, 0);
    };
    if (result == DIR_CW) {
      Joystick.setButton(rotaries[i].cwchar, 1);
      delay(50);
      Joystick.setButton(rotaries[i].cwchar, 0);
    };
  }
}

unsigned char processEncoder(int i) {
  unsigned char pinstate = (digitalRead(rotaries[i].pin2) << 1) | digitalRead(rotaries[i].pin1);
  rotaries[i].state = ttable[rotaries[i].state & 0xf][pinstate];
  return (rotaries[i].state & 0x30);
}

void setup() {
  Joystick.begin();
  initEncoders();
}

void loop() {
  checkAllEncoders();
  checkAllButtons();
}
