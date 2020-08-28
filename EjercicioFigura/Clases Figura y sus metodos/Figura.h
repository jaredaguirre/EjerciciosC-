/**//* 39.336.695-VACA_AGUIRRE,JaredMartin-(05-1965) *//**/

#ifndef FIGURA_H_
#define FIGURA_H_

#include "FiguraInvalidaException.h"

using namespace std;
class Figura{

protected:
    float h;    //altura
    float b;    //base

public:
    Figura(const float _h, const float _b);
    virtual float area() = 0;
    virtual ~Figura();
};



#endif // FIGURA_H_
