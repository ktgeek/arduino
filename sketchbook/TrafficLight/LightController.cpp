#include "WProgram.h"
#include "LightController.h"
#include "LightModel.h"

LightModel* LightController::sLightModel = 0;

LightController::LightController()
{
}

void LightController::setLightModel(LightModel* lm)
{
    sLightModel = lm;
}

void LightController::reset()
{
    sLightModel->setState(0);
    mBaseTimeMillis = millis();
}

USLightController::USLightController() : LightController(), mState(0)
{
}

void USLightController::reset()
{
    LightController::reset();
    sLightModel->setState(LightModel::RED_ON);
    mState = 0;
}

const unsigned long USLightController::times[] = {25000, 50000, 58000};
const byte USLightController::states[] =
{
    LightModel::GREEN_ON,
    LightModel::AMBER_ON,
    LightModel::RED_ON
};

void USLightController::tick()
{
    unsigned long time = millis();
    unsigned long diff = time - mBaseTimeMillis;

    if (diff >= times[mState])
    {
        sLightModel->setState(states[mState++]);
        if(mState > 2)
        {
            mBaseTimeMillis = time;
            mState = 0;
        }
    }
}

RandomLightController::RandomLightController() : LightController()
{
}

void RandomLightController::tick()
{
    unsigned long time = millis();
    unsigned long diff = time - mBaseTimeMillis;

    if (diff >= 400)
    {
        byte newState = random(7);
        sLightModel->setState(newState);
        mBaseTimeMillis = time;
    }
}

EuropeanLightController::EuropeanLightController() : LightController()
{
}

void EuropeanLightController::tick()
{
}
