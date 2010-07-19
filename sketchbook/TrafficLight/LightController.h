#ifndef LIGHTCONTROLLER_H
#define LIGHTCONTROLLER_H

#include "TrafficLight_fwd.h"

class LightController
{
  public:
    LightController();
    
    static void setLightModel(LightModel* lm);
    
    virtual void tick() = 0;
    virtual void reset();

  protected:
    static LightModel* sLightModel;
    int mTickCount;
};

class USLightController : public LightController
{
  public:
    USLightController();
    virtual void tick();
};

class RandomLightController : public LightController
{
  public:
    RandomLightController();
    virtual void tick();

};

class EuropeanLightController : public LightController
{
  public:
    EuropeanLightController();
    virtual void tick();
};

#endif /* LIGHTCONTROLLER_H */

/* Local Variables: */
/* mode: c++ */
/* End: */
