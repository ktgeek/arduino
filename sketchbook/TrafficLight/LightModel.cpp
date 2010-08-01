#include "WProgram.h"
#include "LightModel.h"

const byte LightModel::ALL_OFF = 0x0;
const byte LightModel::RED_ON = 0x1;
const byte LightModel::AMBER_ON = 0x2;
const byte LightModel::GREEN_ON = 0x4;

LightModel::LightModel()
  : state(0)
{
}

// typical AMBER light is 5 seconds
void LightModel::setup()
{
    // Set digital pins 3, 4, and 5 to be output.
    DDRD = B00011100;
    // Set all values low
    PORTD = ALL_OFF;
}

// The state is only expecting a value between 0 and 7.  We'll
// bitshift it over twice to match our input.
void LightModel::setState(byte newState)
{
    state = newState << 2;
    
    PORTD = state;
}        
