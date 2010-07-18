#include "LightModel.h"

LightModel lightModel;

void setup()
{
  lightModel.setup();
}

void loop()
{
  lightModel.setRed(true);
  delay(500);
  lightModel.setRed(false);
  lightModel.setGreen(true);
  delay(500);
  lightModel.setGreen(false);
  lightModel.setAmber(true);
  delay(500);
  lightModel.setAmber(false);
}
