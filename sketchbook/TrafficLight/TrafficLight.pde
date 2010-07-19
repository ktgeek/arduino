#include "LightModel.h"
#include "LightController.h"

LightModel lightModel;

LightController* lc;
USLightController uslc;
RandomLightController rlc;

const int TICK_INTERVAL = 100;

void setup()
{
  randomSeed(analogRead(0));

  lightModel.setup();
  LightController::setLightModel(&lightModel);
  lc = &uslc;
}

int loop_count = 0;

void loop()
{
  // Until I work a button in, we'll switch modes ever 5 minutes
  switch(loop_count)
  {
    case 3000:
      lc = &rlc;
      lc->reset();
      break;

    case 6000:
      lc = &uslc;
      lc->reset();
      loop_count = 0;
      break;
  }
  
  lc->tick();
  delay(TICK_INTERVAL);
  loop_count++;
}
