/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 22.333.444-PEREZ_DEL_RIO,JuanManuel-(07-2299) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**   DESARROOLLE LAS "FUNCIONES MIEMBRO" DE LA CLASE    **//**//**//**/

#include "Prisma.h"

Prisma::Prisma(Prisma& obj)
{
    alto = obj.alto;
    ancho = obj.ancho;
    profundidad = obj.profundidad;
    color = obj.color;
}

Prisma::Prisma(string _color, int _alto, int _ancho, int _profundidad)
{
    alto = _alto;
    ancho = _ancho;
    profundidad = _profundidad;
    color = _color;
}

//Operador Output
ostream& operator << (ostream& output, Prisma& obj)
{
    output << obj.alto <<"x"<< obj.ancho <<"x"<< obj.profundidad <<"-"<< obj.color;
    return output;
}


Prisma operator*(int n,const Prisma& obj)
{
    Prisma p1(obj.color, obj.alto*n, obj.ancho*n, obj.profundidad*n);
    return p1;
}

