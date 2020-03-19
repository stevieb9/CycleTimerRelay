#include "Arduino.h"
#include "CycleTimer.h"

/* Default Constructor */

CycleTimer::CycleTimer (uint8_t pin, unsigned long onTime, unsigned long offTime) {
    _pin = pin;
    _onTime = onTime;
    _offTime = offTime;
}

/* Reverse ON/OFF State Constructor */

CycleTimer::CycleTimer (uint8_t pin, unsigned long onTime, unsigned long offTime, uint8_t reverseState) {
    _pin = pin;
    _onTime = onTime;
    _offTime = offTime;

    _reverseState = true; 
    _on = LOW;
    _off = HIGH;
}

uint8_t CycleTimer::reverse () { 
    return _reverseState;
}

void CycleTimer::process () {

    if (_pMillis == 0) {
        _pMillis = millis();
    }

    unsigned long currentMillis = millis();

    // Turn the outlet on

    if (_state == _off && currentMillis - _pMillis >= _offTime) {
        _state = _on;
        _pMillis = currentMillis;
        digitalWrite(_pin, _on);
    }

    // Turn the outlet off

    else if (_state == _on && currentMillis - _pMillis >= _onTime) {
        _state = _off;
        _pMillis = currentMillis;
        digitalWrite(_pin, _off);
    }
}