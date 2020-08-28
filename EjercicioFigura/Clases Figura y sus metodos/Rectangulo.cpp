/**//* 39.336.695-VACA_AGUIRRE,JaredMartin-(05-1965) *//**/

#include "Rectangulo.h"

Rectangulo::Rectangulo(const float _h, const float _b):Figura(_h, _b){}

float Rectangulo::area()
{
    return h * b;
}
