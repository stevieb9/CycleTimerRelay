#ifndef CYCLETIMER_H
#define CYCLETIMER_H

#define DEBUG_TIMING true

#include "Arduino.h"

using namespace std;

class CycleTimer {

    private:
        uint8_t _reverseState   = false;
        uint8_t _on             = HIGH;
        uint8_t _off            = LOW;
        uint8_t _state          = _on;
        char* _name             = "";
        uint8_t       _pin      = -1;
        unsigned long _onTime   = 0;
        unsigned long _offTime  = 0;

        unsigned long _pMillis  = 0;

    public:
        /* Relay pin; On time; Off time */
        CycleTimer(uint8_t, unsigned long, unsigned long);
 
        /* Relay pin; On time; Off time; Reverse */
        CycleTimer(uint8_t, unsigned long, unsigned long, uint8_t);

        void    process ();
//        uint8_t state () { return _reverseState ? _state : !_state; }
        uint8_t state () { return _state; }

        char*   name () { return _name; }
        char*   name (char* name) { _name = name; }

        uint8_t reverse ();
        uint8_t reverse (uint8_t);
};

#endif

