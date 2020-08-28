/**//* 39.336.695-VACA_AGUIRRE,JaredMartin-(05-1965) *//**/

#include "Cuadrado.h"

Cuadrado::Cuadrado(const float lado):Figura(lado, lado){}

float Cuadrado::area()
{
    return h * b;
}
