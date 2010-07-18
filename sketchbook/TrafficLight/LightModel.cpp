#include "WProgram.h"
#include "LightModel.h"

const int LightModel::RED_LIGHT = 10;
const int LightModel::AMBER_LIGHT = 11;
const int LightModel::GREEN_LIGHT = 12;

LightModel::LightModel()
{
}

// typical AMBER light is 5 seconds
void LightModel::setup()
{
    pinMode(RED_LIGHT, OUTPUT);
    pinMode(AMBER_LIGHT, OUTPUT);
    pinMode(RED_LIGHT, OUTPUT);

    // Ensure that all lights are off at the start
    digitalWrite(RED_LIGHT, LOW);
    digitalWrite(AMBER_LIGHT, LOW);
    digitalWrite(RED_LIGHT, LOW);
}

