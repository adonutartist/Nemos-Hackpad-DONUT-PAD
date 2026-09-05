 #include <Adafruit_TinyUSB.h>
Adafruit_USBD_HID usb_hid;
enum {
  RID_KEYBOARD = 1,
  RID_CONSUMER = 2
};
uint8_t const hid_report_descriptor[] = {

  0x05, 0x01,                    // Usage Page (Generic Desktop)
  0x09, 0x06,                    // Usage (Keyboard)
  0xA1, 0x01,                    // Collection (Application)

  0x85, RID_KEYBOARD,            // Report ID 1

  0x05, 0x07,                    // Usage Page (Keyboard/Keypad)

  // Modifier keys
  0x19, 0xE0,
  0x29, 0xE7,
  0x15, 0x00,
  0x25, 0x01,
  0x75, 0x01,
  0x95, 0x08,
  0x81, 0x02,

  // Reserved byte
  0x75, 0x08,
  0x95, 0x01,
  0x81, 0x01,

  // 8 simultaneous keys
  0x15, 0x00,
  0x25, 0x65,
  0x19, 0x00,
  0x29, 0x65,
  0x75, 0x08,
  0x95, 0x08,
  0x81, 0x00,

  0xC0,                          // End keyboard

  0x05, 0x0C,                    // Usage Page (Consumer)
  0x09, 0x01,                    // Usage (Consumer Control)
  0xA1, 0x01,                    // Collection

  0x85, RID_CONSUMER,            // Report ID 2

  0x15, 0x00,                    // Logical Minimum
  0x26, 0xFF, 0x03,              // Logical Maximum 0x03FF

  0x19, 0x00,                    // Usage Minimum
  0x2A, 0xFF, 0x03,              // Usage Maximum 0x03FF

  0x75, 0x10,                    // Report Size = 16 bits
  0x95, 0x01,                    // Report Count = 1

  0x81, 0x00,                    // Input

  0xC0                           // End consumer
};
const uint8_t rowPins[4] = {
  D0, D1, D2, D3
};
const uint8_t colPins[3] = {
  D6, D7, D8
};

// KEY MAPPING
//
// SW1 = W + UP
// SW2 = S + DOWN
// SW3 = A + LEFT
// SW4 = D + RIGHT
//
// SW5 = J
// SW6 = K
// SW7 = U
// SW8 = I
//
// SW9  = SPACE
// SW10 = ESC
// SW11 = Q
// SW12 = E

// Encoder = Volume

bool keyState[12] = { false };
const uint8_t encoderA = D9;
const uint8_t encoderB = D10;
uint8_t encoderState = 0;
int8_t encoderAccumulator = 0;
const int8_t encoderTable[16] = {
   0, -1,  1,  0,
   1,  0,  0, -1,
  -1,  0,  0,  1,
   0,  1, -1,  0
};
void volumeUp() {
  if (!usb_hid.ready()) {
    return;
  }
  usb_hid.sendReport16(
    RID_CONSUMER,
    HID_USAGE_CONSUMER_VOLUME_INCREMENT
  );
  delay(3);
  usb_hid.sendReport16(
    RID_CONSUMER,
    0
  );
}
void volumeDown() {
  if (!usb_hid.ready()) {
    return;
  }
  usb_hid.sendReport16(
    RID_CONSUMER,
    HID_USAGE_CONSUMER_VOLUME_DECREMENT
  );
  delay(3);
  usb_hid.sendReport16(
    RID_CONSUMER,
    0
  );
}
void updateEncoder() {
  uint8_t A = digitalRead(encoderA);
  uint8_t B = digitalRead(encoderB);
  uint8_t newState = (A << 1) | B;
  if (newState == encoderState) {
    return;
  }
  uint8_t index = (encoderState << 2) | newState;
  encoderAccumulator += encoderTable[index];
  encoderState = newState;
  if (encoderAccumulator >= 4) {
    volumeDown();
    encoderAccumulator = 0;
  }
  else if (encoderAccumulator <= -4) {
    volumeUp();
    encoderAccumulator = 0;
  }
}
void addKey(
  uint8_t report[],
  int &count,
  uint8_t key
) {
  if (count < 8) {
    report[2 + count] = key;
    count++;
  }
}
void sendKeyboardReport() {
  uint8_t report[10] = { 0 };
  int count = 0;
  for (int i = 0; i < 12; i++) {
    if (!keyState[i]) {
      continue;
    }
    if (i == 0) {
      addKey(report, count, HID_KEY_W);
      addKey(report, count, HID_KEY_ARROW_UP);
    }
    else if (i == 1) {
      addKey(report, count, HID_KEY_S);
      addKey(report, count, HID_KEY_ARROW_DOWN);
    }
    else if (i == 2) {
      addKey(report, count, HID_KEY_A);
      addKey(report, count, HID_KEY_ARROW_LEFT);
    }
    else if (i == 3) {
      addKey(report, count, HID_KEY_D);
      addKey(report, count, HID_KEY_ARROW_RIGHT);
    }
    else if (i == 4) {
      addKey(report, count, HID_KEY_J);
    }
    else if (i == 5) {
      addKey(report, count, HID_KEY_K);
    }
    else if (i == 6) {
      addKey(report, count, HID_KEY_U);
    }
    else if (i == 7) {
      addKey(report, count, HID_KEY_I);
    }
    else if (i == 8) {
      addKey(report, count, HID_KEY_SPACE);
    }
    else if (i == 9) {
      addKey(report, count, HID_KEY_ESCAPE);
    }
    else if (i == 10) {
      addKey(report, count, HID_KEY_Q);
    }
    else if (i == 11) {
      addKey(report, count, HID_KEY_E);
    }
  }
  usb_hid.sendReport(
    RID_KEYBOARD,
    report,
    sizeof(report)
  );
}
void setup() {
  for (int r = 0; r < 4; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], LOW);
  }
  for (int c = 0; c < 3; c++) {

    pinMode(
      colPins[c],
      INPUT_PULLDOWN
    );
  }
  pinMode(
    encoderA,
    INPUT_PULLUP
  );
  pinMode(
    encoderB,
    INPUT_PULLUP
  );
  encoderState =
    (digitalRead(encoderA) << 1) |
     digitalRead(encoderB);
  usb_hid.setPollInterval(2);
  usb_hid.setReportDescriptor(
    hid_report_descriptor,
    sizeof(hid_report_descriptor)
  );
  usb_hid.begin();
  while (!TinyUSBDevice.mounted()) {
    delay(10);
  }
}
void loop() {
  if (!usb_hid.ready()) {
    return;
  }
  updateEncoder();
  for (int r = 0; r < 4; r++) {
    digitalWrite(
      rowPins[r],
      HIGH
    );
    delayMicroseconds(50);
    for (int c = 0; c < 3; c++) {
      int key = r * 3 + c;
      bool pressed =
        digitalRead(colPins[c]);

      keyState[key] = pressed;
    }
    digitalWrite(
      rowPins[r],
      LOW
    );
  }
  sendKeyboardReport();
  delay(2);
}