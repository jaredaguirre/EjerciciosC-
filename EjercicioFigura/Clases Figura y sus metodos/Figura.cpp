/**//* 39.336.695-VACA_AGUIRRE,JaredMartin-(05-1965) *//**/

#include "Figura.h"
#include "FiguraInvalidaException.h"

Figura::Figura(const float _h, const float _b)
{
    if(_h <= 0 || _b <= 0)
        throw FiguraInvalidaException();

    this->h = _h;
    this->b = _b;
}

Figura::~Figura(){}
