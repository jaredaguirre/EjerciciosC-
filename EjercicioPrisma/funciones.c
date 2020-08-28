/**//* 39.336.695-VACA_AGUIRRE,JaredMartin-(05-1965) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/

#include <string.h>
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarMovim_MIO(const void *d, FILE *fp)
{
    //Cuando esta funcion recibe un puntero a NULL, entonces
    //el retorno es la Cabecera o Título de la información
    const tMovi *m = (tMovi*)d;

    if(m)
        fprintf(fp, "%-12s %9.2f\n", m->ctaCte, m->saldo);
    else fprintf(fp, "Nro Cuenta Banc   Importe\n");
}



int compararMovim_MIO(const void *d1, const void *d2)
{
    /*
    Aclaracion: Debido a que el total de digitos (sin los guiones) de
    la cuenta siempre sera de al menos 11 (si es que no contamos los
    dos primeros ceros) entonces nos es imposible convertir la cadena
    a entero, ya que ni siquiera entraria en una variable de tipo long

    Por lo tanto, para los fines de este ejercicio, la comparacion se
    realiza entre cadenas a y b con un puntero que recorre cada una,
    retornando:

    - 0 si A == B
    - MAYOR QUE CERO si A > B
    - MENOR QUE CERO si A < B

    */
    tMovi *m1 = (tMovi*)d1;
    tMovi *m2 = (tMovi*)d2;

    char *s1 = m1->ctaCte, *s2 = m2->ctaCte;
    int r = 0;
    while(*s1 && r == 0)
    {
        r = *s1 - *s2;
        s1++;
        s2++;
    }
    return r;

}


int esCtaCte002_MIO(const void *d)
{
    tMovi *m = (tMovi*)d;
    //str es un puntero que apunta al ultimo guion
    char *str = strrchr(m->ctaCte, '-');
    //Si luego del guion, se encuentra "002", entonces retorna 1, sino, 0
    return (str = strstr(str, "002") != NULL);
}


int acumularMoviSaldo_MIO(void **dest, unsigned *tamDest,
                      const void *ori, unsigned tamOri)
{
    tMovi *d = (tMovi*)*dest;
    tMovi *o = (tMovi*)ori;

    d->saldo += o->saldo;

    return 1;
}

void mostrarTotal_MIO(const void *d, FILE *fp)
{
    tMovi *m = (tMovi*)d;
    fprintf(fp, "%15s %9.2f\n\n", "Total cliente:" , m->saldo);
}


/**//* para el TDA LISTA                                                  *//**/
int mostrarLista_MIO(const tLista *p,
                     void (*mostrarMovim_MIO)(const void *, FILE *), FILE *fp)
{
    int cant = 0;
    mostrarMovim_MIO(NULL, fp); //Imprimimos Cabecera de Lista
    while(*p)
    {
        mostrarMovim_MIO((*p)->info, fp);
        p = &(*p)->sig; //p pasa a apuntar al siguiente
        cant++;
    }
    return cant;
}

void ordenarLista_MIO(tLista *p, int (*compararMovim_MIO)(const void *, const void *))
{
    /*DEFINICION DE PUNTEROS

    MENOR = Señala el elemento con el menor valor
    PRI = "Principio del recorrido" -Señana el elemento desde donde se inicia el recorrido en busca de menores
    R = Es el puntero que recorre en busca de menores hacia la derecha

    */
    tNodo *menor, *pri = *p, *r = *p;

    //Si no hay lista, no hay orden a realizar
    if(*p == NULL)
        return;

    //Mientras exista un elemento siguiente a PRI
    while(pri->sig)
    {
        //PRI Inicia como el MENOR
        menor = pri;
        //R recorre en busca del Menor entre todos de la derecha
        r = pri->sig;
        while(r)
        {
            if(compararMovim_MIO((r)->info, menor->info) < 0 )
                menor = r;
            r = r->sig;
        }
        //Al terminar de recorrer toda la derecha, pueden pasar dos cosas:
        //SI "MENOR" NO SE ENCONTRO
        if(menor == pri)
        {
            pri = pri->sig;     //PRI avanza al siguiente
            p = &(*p)->sig;     //P tambien avanza uno
        }

        //SI "MENOR" SI FUE HAYADO
        else
        {
            //Invocamos un aux que comienza en PRI
            tNodo *aux = pri;

            //Posicionamos AUX hasta uno antes del MENOR para desvincularlo y reubicarlo antes de PRI
            while(aux->sig != menor) //mientras el siguiente de aux no sea igual a "MENOR"
                aux = aux->sig;      //avanza aux

            aux->sig = menor->sig;   //desvinculamos el menor
            menor->sig = pri;        //lo ponemos antes de pri

            /*Si P es igual a PRI, se trata de la primera insercion, y P
            pasa a apuntarlo*/
            if((*p) == pri)
                *p = menor;
            else
            {
              (*p)->sig = menor;
               p = &(*p)->sig;
            }
        }
    }


}


int eliminarMostrarYMostrarSubTot_MIO(tLista *p, FILE *fpPant,
                                      int compararMovim(const void *, const void *),
                                      int esCtaCte002_MIO(const void *d),
                                      int acumularMoviSaldo_MIO(void **, unsigned *,
                                                   const void *, unsigned),
                                      void mostrarMovim_MIO(const void *, FILE *),
                                      void mostrarTotal_MIO(const void *, FILE *))
{
    /*DEFINICION DE LAS VARIABLES Y PUNTEROS:
    cant = Cantidad de elementos Eliminados
    r = Puntero que recorre a partir de P, los nodos con el mismo cliente
    antep = Puntero que permanece siempre antes de P, para saber desde donde hay que desvincular*/
    int cant = 0;
    tNodo *r, *antep = NULL;

    while(*p)
    {
        //PRIMERA PARTE: MOSTRAR LOS ELEMENTOS
        //Si P->info acaba en "002"
        if(esCtaCte002_MIO((*p)->info))
        {
            mostrarMovim_MIO(NULL, fpPant);         //Mostramos la cabecera
            mostrarMovim_MIO((*p)->info, fpPant);   //Mostramos el Movimiento
            cant++;                             //Aumentamos el Contador
            r = *p;                             //Iniciamos R en P

            //Mientras el sig de R no sea NULL Y La comparacion
            //entre R y P sea 0 (o sea sean Iguales)
            while(r->sig != NULL && compararMovim(r->sig->info, (*p)->info) == 0)
            {
                r = r->sig;                     //R avanza
                mostrarMovim_MIO(r->info, fpPant);  //Mostramos el Movimiento
                cant++;                         //Aumenta el contador
                acumularMoviSaldo_MIO(&(*p)->info, (*p)->tamInfo, r->info, r->tamInfo); //Acumulamos el saldo en P

                /*(Recordar que el saldo de p->info puede ser modificado porque
                   ya lo mostramos, y posteriormente será eliminado)*/
            }
            mostrarTotal_MIO((*p)->info, fpPant);   //Mostramos el Total de la cuenta

            //SEGUNDA PARTE: DESVINCULACION Y ELIMINACION DE LOS ELEMENTOS MOSTRADOS
            //Si ANTEP no es NULL
            if(antep)
            {
                antep->sig = r->sig;    //Desvinculamos todos los nodos mostrados

                //Mientras P no esté uno adelante de R
                while(*p != r->sig)
                {
                    tNodo *aux = *p;    //Instanciamos un tNodo Aux
                    p = &(*p)->sig;     //P avanza
                    free(aux->info);    //Nos deshacemos del nodo
                    free(aux);

                    /*Cuando P llega al final, el ciclo termina como excepción*/
                    if(*p == NULL)
                        break;
                }
            }
            //Si ANTEP es NULL
            //(Esta condicion solamente puede darse cuando P es el primero de la lista)
            else
            {
                *p = r->sig;    //P avanza
                free(r->info);  //Liberamos la informacion
            }
        }
        //Si P No acaba en "002"
        else
        {
            antep = *p;         //Instanciamos antep donde está P
            p = &(*p)->sig;     //P avanza uno
        }
    }
    return cant;

}


int  vaciarListaYMostrar_MIO(tLista *p,
                             void (*mostrar)(const void *, FILE *), FILE *fp)
{
    int cant = 0;
    while(*p)
    {
        tNodo *aux = *p;

        mostrarMovim(aux->info, fp); //Mostramos movimiento
        cant++;

        *p = aux->sig;      //P avanza al siguiente
        free(aux->info);    //liberamos los nodos
        free(aux);
    }
    return cant;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

