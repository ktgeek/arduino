#include "WProgram.h"
#include "LightModel.h"

const int LightModel::RED_LIGHT = 10;
const int LightModel::AMBER_LIGHT = 11;
const int LightModel::GREEN_LIGHT = 12;

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
    pinMode(RED_LIGHT, OUTPUT);
    pinMode(AMBER_LIGHT, OUTPUT);
    pinMode(GREEN_LIGHT, OUTPUT);

    // Ensure that all lights are off at the start
    digitalWrite(RED_LIGHT, LOW);
    digitalWrite(AMBER_LIGHT, LOW);
    digitalWrite(GREEN_LIGHT, LOW);
}

void LightModel::setRed(bool on)
{
    if(on)
    {
        digitalWrite(RED_LIGHT, HIGH);
        state |= RED_ON;
    }
    else
    {
        digitalWrite(RED_LIGHT, LOW);
        state &= ~RED_ON;
    }
}

void LightModel::setAmber(bool on)
{
    if(on)
    {
        digitalWrite(AMBER_LIGHT, HIGH);
        state |= AMBER_ON;
    }
    else
    {
        digitalWrite(AMBER_LIGHT, LOW);
        state &= ~AMBER_ON;
    }
}

void LightModel::setGreen(bool on)
{
    if(on)
    {
        digitalWrite(GREEN_LIGHT, HIGH);
        state |= GREEN_ON;
    }
    else
    {
        digitalWrite(GREEN_LIGHT, LOW);
        state &= ~GREEN_ON;
    }
}


bool LightModel::isRedOn()
{
    return state & RED_ON;
}

bool LightModel::isAmberOn()
{
    return state & AMBER_ON;
}

bool LightModel::isGreenOn()
{
    return state & GREEN_ON;
}

void LightModel::setState(byte newState)
{
    state = newState;
    
    digitalWrite(RED_LIGHT, state & RED_ON ? HIGH: LOW);
    digitalWrite(AMBER_LIGHT, state & AMBER_ON ? HIGH : LOW);
    digitalWrite(GREEN_LIGHT, state & GREEN_ON ? HIGH : LOW);
}        
