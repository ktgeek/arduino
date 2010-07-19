#ifndef LIGHTMODEL_H
#define LIGHTMODEL_H

typedef unsigned char byte;

class LightModel
{
  public:
    LightModel();
    void setup();

    void setState(byte newState);
        
    static const bool ON;
    static const bool OFF;

    static const byte RED_ON;
    static const byte AMBER_ON;
    static const byte GREEN_ON;

  private:
    static const int RED_LIGHT;
    static const int AMBER_LIGHT;
    static const int GREEN_LIGHT;

    byte state;
};

#endif /* LIGHTMODEL_H */

/* Local Variables: */
/* mode: c++ */
/* End: */



