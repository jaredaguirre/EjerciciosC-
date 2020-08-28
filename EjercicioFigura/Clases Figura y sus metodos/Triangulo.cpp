/**//* 39.336.695-VACA_AGUIRRE,JaredMartin-(05-1965) *//**/

#include "Triangulo.h"

Triangulo::Triangulo(const float _h, const float _b):Figura(_h, _b){}

float Triangulo::area()
{
    return (h * b)/2;
}
