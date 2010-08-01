#ifndef LIGHTMODEL_H
#define LIGHTMODEL_H

typedef unsigned char byte;

class LightModel
{
  public:
    LightModel();
    void setup();

    void setState(byte newState);

    static const byte ALL_OFF;
    static const byte RED_ON;
    static const byte AMBER_ON;
    static const byte GREEN_ON;

  private:
    byte state;
};

#endif /* LIGHTMODEL_H */

/* Local Variables: */
/* mode: c++ */
/* End: */



