/**//* 39.336.695-VACA_AGUIRRE,JaredMartin-(05-1965) *//**/

#ifndef TRIANGULO_H_
#define TRIANGULO_H_

#include "Figura.h"

class Triangulo : public Figura
{
public:
    Triangulo(const float altura, const float base);
    float area();
};





#endif // TRIANGULO_H_
