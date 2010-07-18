
#ifndef LIGHTMODEL_H
#define LIGHTMODEL_H

typedef unsigned char byte;
#define RED_ON 0x1;
#define AMBER_ON 0x2;
#define GREEN_ON 0x4;

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
        
    static const bool ON;
    static const bool OFF;

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



