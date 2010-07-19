#include "WProgram.h"
#include "LightController.h"
#include "LightModel.h"

LightModel* LightController::sLightModel = 0;

LightController::LightController()
    : mTickCount(0)
{
}

void LightController::setLightModel(LightModel* lm)
{
    sLightModel = lm;
}

void LightController::reset()
{
    sLightModel->setState(0);
    mTickCount = 0;
}

USLightController::USLightController() : LightController()
{
}

void USLightController::tick()
{
    switch(mTickCount)
    {
        // Initial state is red
        case 0:
            sLightModel->setState(LightModel::RED_ON);
            break;

        // 25 seconds later go green
        case 250:
            sLightModel->setState(LightModel::GREEN_ON);
            break;

         // 25 seconds later go yellow for 8 seconds
        case 500:
            sLightModel->setState(LightModel::AMBER_ON);
            break;

        case 580:
            mTickCount = -1;
            break;
    }
    mTickCount++;
}

RandomLightController::RandomLightController() : LightController()
{
}

void RandomLightController::tick()
{
    if (mTickCount > 4)
    {
        mTickCount = 0;
    }
    if (!mTickCount)
    {
        byte newState = random(7);
        sLightModel->setState(newState);
    }
    mTickCount++;
}

EuropeanLightController::EuropeanLightController() : LightController()
{
}

void EuropeanLightController::tick()
{
    mTickCount++;
}
