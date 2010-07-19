#include "WProgram.h"
#include "LightController.h"
#include "LightModel.h"

LightModel* LightController::sLightModel = 0;

LightController::LightController() { }

void LightController::setLightModel(LightModel* lm)
{
    sLightModel = lm;
}

USLightController::USLightController() : LightController() { }

void USLightController::tick()
{   
}

RandomLightController::RandomLightController()
{
}

void RandomLightController::tick()
{
    byte newState = random(7);
    sLightModel->setState(newState);
}
