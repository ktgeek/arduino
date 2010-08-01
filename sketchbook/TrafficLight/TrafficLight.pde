#include "MsTimer2.h"
#include "LightModel.h"
#include "LightController.h"

// This file now requires the use of MsTimer2 from
// http://www.arduino.cc/playground/Main/MsTimer2

LightModel lightModel;

LightController* lc;
USLightController uslc;
RandomLightController rlc;

const int TICK_INTERVAL = 100;

// Switch to the other light controller, but not the one we're on.
void switchController()
{
  if (lc == &uslc)
  {
    lc = &rlc;
  }
  else
  {
    lc = &uslc;
  }

  lc->reset();
}

void setup()
{
  // Set up the random number generator
  randomSeed(analogRead(0));

  // Set up our light model, assign it to the controllers
  // and set our default controller and reset it.
  lightModel.setup();
  LightController::setLightModel(&lightModel);
  lc = &uslc;
  lc->reset();

  // Use Timer2 to call back to switchController to switch modes every
  // 30 seconds until we can wire in a button on an interrupt.
  MsTimer2::set(300000, switchController); // 5 minute period
  MsTimer2::start();
}

void loop()
{
  lc->tick();
}
