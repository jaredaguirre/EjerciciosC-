/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 22.333.444-PEREZ_DEL_RIO,JuanManuel-(07-2299) *//**/
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
    int alto;
    int ancho;
    int profundidad;
    string color;     /// <--preferentemente, de lo contrario:  char *color;

public:
    Prisma(string color = "Incoloro", int alto = 1, int ancho = 1, int profundidad = 1);
    Prisma(Prisma &);

    //Operadores
    friend ostream& operator << (ostream&, Prisma&);

    Prisma& operator=(Prisma& obj)
    {
        color = obj.color;
        alto = obj.alto;
        ancho = obj.ancho;
        profundidad = obj.profundidad;

        return this;
    }

    friend Prisma operator*(int n, Prisma& obj);
};



#endif // PRISMA_H_

