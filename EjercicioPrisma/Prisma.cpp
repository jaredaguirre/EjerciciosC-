/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 39.336.695-VACA_AGUIRRE,JaredMartin-(05-1965) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**   DESARROOLLE LAS "FUNCIONES MIEMBRO" DE LA CLASE    **//**//**//**/

#include "Prisma.h"

//Constructor DEFAULT
Prisma::Prisma(string _color, int _ancho, int _alto, int _profundidad)
{
    color = _color;
    ancho = _ancho;
    alto = _alto;
    profundidad = _profundidad;
}
//definicion de operadores
Prisma & Prisma::operator=(const Prisma &obj)
{
    alto = obj.alto;
    ancho = obj.ancho;
    profundidad = obj.profundidad;
    color = obj.color;
    return *this;
}

Prisma operator*(const int &n, const Prisma &obj)
{
    Prisma pri(obj.color, obj.ancho * n, obj.alto * n, obj.profundidad * n);
    return pri;
}

Prisma Prisma::operator++(int)
{
    Prisma aux(*this);
    this->alto++;
    this->ancho++;
    this->profundidad++;
    return aux;
}

Prisma& Prisma::operator--()
{
    this->alto--;
    this->ancho--;
    this->profundidad--;
    return *this;
}

ostream& operator<<(ostream &salida, const Prisma &obj)
{
    salida << obj.ancho << "x" << obj.alto <<"x" << obj.profundidad << "-" << obj.color;
    return salida;
}
