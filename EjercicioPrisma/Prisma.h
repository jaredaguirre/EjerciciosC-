/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 39.336.695-VACA_AGUIRRE,JaredMartin-(05-1965) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**         COMPLETE LA DECLARACIÓN DE LA CLASE          **//**//**//**/

#ifndef PRISMA_H_
#define PRISMA_H_

#include <iostream>
#include <string>

using namespace std;

class Prisma
{
private:
    int ancho;
    int alto;
    int profundidad;
    string color;

public:
    Prisma(string = "Incoloro", int = 1, int = 1, int = 1);

    //OPERADORES
    Prisma &operator=(const Prisma &);
    Prisma &operator--();
    Prisma operator++(int);
    friend Prisma operator*(const int &, const Prisma &);
    friend ostream & operator<<(ostream &salida, const Prisma &);
};

#endif // PRISMA_H_

