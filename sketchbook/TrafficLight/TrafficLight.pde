#include "LightModel.h"
#include "LightController.h"

LightModel lightModel;

LightController* lc;
USLightController uslc;
RandomLightController rlc;


void setup()
{
  randomSeed(analogRead(0));

  lightModel.setup();
  LightController::setLightModel(&lightModel);
//  lc = &uslc;
  lc = &rlc;
}

void loop()
{
  lc->tick();
  delay(500);
}
