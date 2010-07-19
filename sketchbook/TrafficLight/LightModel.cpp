#include "WProgram.h"
#include "LightModel.h"

const int LightModel::RED_LIGHT = 10;
const int LightModel::AMBER_LIGHT = 11;
const int LightModel::GREEN_LIGHT = 12;

const byte LightModel::RED_ON = 0x1;
const byte LightModel::AMBER_ON = 0x2;
const byte LightModel::GREEN_ON = 0x4;

const bool LightModel::ON = true;
const bool LightModel::OFF = false;

LightModel::LightModel()
  : state(0)
{
}

// typical AMBER light is 5 seconds
void LightModel::setup()
{
    pinMode(RED_LIGHT, OUTPUT);
    pinMode(AMBER_LIGHT, OUTPUT);
    pinMode(GREEN_LIGHT, OUTPUT);

    // Ensure that all lights are off at the start
    digitalWrite(RED_LIGHT, LOW);
    digitalWrite(AMBER_LIGHT, LOW);
    digitalWrite(GREEN_LIGHT, LOW);
}

void LightModel::setState(byte newState)
{
    state = newState;
    
    digitalWrite(RED_LIGHT, state & RED_ON ? HIGH: LOW);
    digitalWrite(AMBER_LIGHT, state & AMBER_ON ? HIGH : LOW);
    digitalWrite(GREEN_LIGHT, state & GREEN_ON ? HIGH : LOW);
}        
