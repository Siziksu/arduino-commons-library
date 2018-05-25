#include "Commons.h"

Button::Button(byte pin, byte debounce) {
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
  _debounce = debounce;
}

byte Button::pin() {
  return _pin;
}

byte Button::pressed() {
  _current = !digitalRead(_pin);
  if (_previous != _current) {
     _previous = _current;
    if (_current == HIGH) {
      delay(_debounce);
      return 1; // pressed
    } else {
      return 2; // released
    }
  } else {
    return 0; // same state
  }
}

Led::Led(byte pin, boolean on) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, on);
}

byte Led::pin() {
  return _pin;
}

void Led::on() {
  digitalWrite(_pin, HIGH);
}

void Led::off() {
  digitalWrite(_pin, LOW);
}

Buzzer::Buzzer(byte pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

byte Buzzer::pin() {
  return _pin;
}

void Buzzer::buzz() {
  digitalWrite(_pin, HIGH);
}

void Buzzer::stopBuzz() {
  digitalWrite(_pin, LOW);
}

void Buzzer::playTone(uint16_t frequency, uint32_t duration = 0) {
  tone(_pin, frequency, duration);
}

void Buzzer::stopTone() {
  noTone(_pin);
}
