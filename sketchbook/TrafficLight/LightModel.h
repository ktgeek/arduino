#ifndef LIGHTMODEL_H
#define LIGHTMODEL_H

typedef unsigned char byte;

class LightModel
{
  public:
    LightModel();
    void setup();

    void setRed(bool on);
    void setAmber(bool on);
    void setGreen(bool on);

    
    bool isRedOn();
    bool isAmberOn();
    bool isGreenOn();

    void setState(byte newState);
        
    static const bool ON;
    static const bool OFF;

  private:
    static const int RED_LIGHT;
    static const int AMBER_LIGHT;
    static const int GREEN_LIGHT;

    static const byte RED_ON;
    static const byte AMBER_ON;
    static const byte GREEN_ON;

    byte state;
};

#endif /* LIGHTMODEL_H */

/* Local Variables: */
/* mode: c++ */
/* End: */



