/**//* 39.336.695-VACA_AGUIRRE,JaredMartin-(05-1965) *//**/

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO AC�   *//**//**/
#include <stdlib.h>
#include <string.h>
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, H�GALO AC�   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* AC� DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEM�S DE CUALQUIER OTRA FUNCI�N QUE SE REQUIERA           *//**//**/

/*ESTRUCTURA tIndex*/

//Se almacena en este tipo de dato el DNI y la cantidad de veces que aparece en lista.
typedef struct
{
    char dni[11];
    int cant;
}tIndex;

tNodo * buscarMasRepetido(tNodo *, int);

tNodo * buscarMasRepetido(tNodo *p, int cantNodos)
{
    /*
    C�MO FUNCIONA?
    --------------
    Esta funci�n busca a partir del puntero que se le pasa, el DNI m�s repetido
    respetando orden cronol�gico. Al comenzar, crea un vector del tipo "tIndex", cuya
    definici�n est� m�s arriba, y permite almacenar tanto el DNI de cada nodo as� como
    la cantidad de veces que �ste aparece en la lista. Para hacerlo din�mico, el vector
    tiene como tama�o m�ximo la cantidad de nodos, ya que la cantidad de DNIs nunca puede superar
    ese n�mero. Adem�s, puede funcionar con cualquier cantidad de alumnos.
    Luego de generar y cargar el �ndice din�mico, se recorre el mismo buscando
    el DNI con el valor de repeticiones m�s alto y que haya aparecido primero cronol�gicamente.

    Luego retornamos la direcci�n de cualquier Nodo que tenga un DNI que cumpla esa caracter�stica.

    DEFINICI�N DE PUNTEROS:
    -----------------------
    ACT = Apunta al elemento Actual, que se ir� comparando con cada elemento del vector �ndice
    nobj= Nodo objetivo: Es el puntero que, luego de encontrar el DNI objetivo, recorre la lista buscando cualquier
        nodo que posea ese mismo DNI.

    vec = Es el vector �ndice, donde se almacena cada DNI, y cu�ntas veces aparece en Lista.
    lim = Es el limite de inserci�n en el vector. Tambi�n funciona como indicador de la cantidad de DNIs diferentes
    found = Es una Bandera para saber si se encontr� el elemento recorriendo el vector �ndice.
    mayor = Almacena la cantidad mayor de veces que un DNI aparece en el vector �ndice.
    posiM = Posici�n Mayor. Es el entero que muestra la posici�n del mayor en el vector
    */
    tNodo *act = p,
          *nobj = p;

    tIndex *vec = (tIndex*)calloc(cantNodos, sizeof(tIndex));
    int i, lim = 0,
        found,
        mayor = 0,
        posiM = 0;

    //RECORREMOS LA LISTA a fin de llenar el �ndice
    while(act)
    {
        found = 0;                  //Colocamos la bandera en 0

        //RECORRIDO DEL INDICE
        for(i = 0; i < lim; i++)
        {
            //Si el DNI registrado en el vector es igual al dni del nodo Actual,
            if(!strcmp(vec[i].dni, ((tFinal*)act->info)->dni))
            {
                vec[i].cant++;      //Aumentamos la cantidad de apariciones
                found = 1;          //Colocamos la Bandera en 1
                break;              //Paramos de recorrer el vector
            }
        }
        //Si no encontramos el DNI en el vector,
        //es porque es la primera vez que se ingresa en el mismo, por lo tanto...
        if(!found)
        {
            strcpy(vec[lim].dni, ((tFinal*)act->info)->dni);    //Copiamos el DNI del nodo actal en "pos" del vector
            vec[lim].cant = 1;                                  //La cantidad empieza en 1
            lim++;                                              //aumentamos el l�mite de inserci�n en el vector
        }
        act = act->sig;             //ACT avanza al siguiente
    }
    //RECORREMOS EL VECTOR BUSCANDO EL MAYOR
    for(i = lim-1; i >= 0; i--)
    {
        //Si la cantidad es mayor o igual al mayor,
        if(vec[i].cant >= mayor)
        {
            mayor = vec[i].cant;    //el mayor pasa a ser esa cantidad
            posiM = i;              //guardamos la posici�n con el mayor.
        }
    }
    //Al salir del recorrido, ya tenemos la posici�n con el mayor DNI
    //Ahora buscamos un nodo que tenga ese mismo DNI
    while(strcmp(vec[posiM].dni, ((tFinal*)nobj->info)->dni) != 0)
        nobj = nobj->sig;
    free(vec);      //liberamos o "limpiamos" el vector

    return nobj;
}


int getCantidadNodosDesdeIni(tNodo*);

int getCantidadNodosDesdeIni(tNodo * ini)
{
    /*Funcion que cuenta la cantidad de Nodos a partir del puntero INI*/

    int cantNodos = 1;
    tNodo * b = ini;
    while(b->sig)
    {
        b = b->sig;
        cantNodos++;
    }
    free(b);
    return cantNodos;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la informaci�n                                                *//**/

void mostrarFinal_MIO(const void *d, FILE *fp)
{
    //Convertimos a tipo tFinal el dato que recibimos
    const tFinal *temp = (const tFinal*)d;

    //Si el valor recibido no es NULL, entonces imprimimos el registro completo
    //si no, simplemente ponemos el "header" o "cabecera"
    if(temp)
        fprintf(fp,"%-10s %-31s %04d %2d\n", temp->dni, temp->apYNom, temp->codMat, temp->calif);
    else
        fprintf(fp, " D. N. I.  Apellido(s), Nombre(s)         CodM Cal\n");
}


int  compararFinal_MIO(const void *d1, const void *d2)
{
    const tFinal * f1 = (const tFinal*)d1;
    const tFinal * f2 = (const tFinal*)d2;

    return strcmp(f1->dni, f2->dni);
}


int  acumularCalif_MIO(void **dest, unsigned *tamDest,
                       const void *orig, unsigned tamOrig)
{
    tFinal *fDestino = (tFinal*)*dest;
    const tFinal *fOrigen = (const tFinal*)orig;

    fDestino->calif += fOrigen->calif;

    return 1;
}


void mostrarProm_MIO(const void *d2, int cantCalif, FILE *fp)
{
    const tFinal *f = (const void*)d2;

    fprintf(fp, "   --- Rindio  %2d final(es) con un promedio de: %2d\n\n", cantCalif, f->calif / cantCalif);
}


/**//* para el TDA LISTA                                                  *//**/

int  mostrarDeIzqADer_MIO(const tLista *p,
                          void(*mostrarFinal_MIO)(const void *, FILE *), FILE *fp)
{
    tNodo *act = *p;
    int cant = 0;

    if(act)
    {
        mostrarFinal_MIO(NULL, fp);
        while(act->ant)
            act = act->ant;
        while(act)
        {
            mostrarFinal_MIO(act->info, fp);
            act = act->sig;
            cant++;
        }
    }
    return cant;
}


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    /*
    C�MO FUNCIONA?
    --------------
    La funci�n OrdenarLista funciona invocando un puntero INI al comienzo; a partir del cual
    se comienza a buscar el dni m�s repetido respetando orden cronol�gico. Para encontrarlo,
    se aplica la funci�n "buscarMasRepetido()" cuyo funcionamiento se explica m�s arriba.
    Una vez que se encuentra, se "reposicionan" esos elementos que posean ese mismo DNI,
    detr�s de INI para luego ejecutarse el mismo procedimiento a partir de INI.
    Al ordenar todo, llegar� un punto donde todos los elementos de la lista estar�n
    detr�s de INI, y entonces el proceso se da por terminado.

    DEFINICI�N DE PUNTEROS Y VARIABLES:
    -----------------------------------
    INI = Inicio de Busqueda. A partir de este puntero y hasta el final de la lista,
          se comenzar� a buscar al ultimo Nodo con el dni m�s repetido.
    R   = Puntero Recorrido. Es el puntero que se desprende de INI y comienza a recorrer
          la lista en busca de nodos con el DNI objetivo. Si R llega a tener valor NULL,
          es porque hay que buscar un nuevo DNI para seguir ordenando.

    nodoEncontrado = Es el puntero que apunta al Nodo que se utilizar� como "objetivo", el
                     cual contiene el DNI que tenemos como objetivo de b�squeda. En este
                     caso "nodoEncontrado" apunta siempre al �ltimo de la lista que cumpla
                     con esa condici�n, sin embargo el proceso funciona igualmente si apuntara
                     a cualquier otro Nodo con el DNI objetivo.

    cantNodos = En esta variable se guarda la cantidad de nodos de la lista A PARTIR DE INI. Disminuye su
                valor cada vez que se acomodan nodos detr�s de INI. Sirve como par�metro para la funci�n
                "buscarMasRepetido()" que se explica m�s arriba.
    */
    tNodo *ini = *p,
          *r = NULL,
          *nodoObjetivo;

    int cantNodos;

    //Si la lista est� vac�a, no hay ordenamiento
    if(!ini)
        return;

    //Posicionamos INI al comienzo
    while(ini->ant)
        ini = ini->ant;

    //Calculamos la cantidad de nodos a partir de INI
    cantNodos = getCantidadNodosDesdeIni(ini);

    //Mientras INI tenga un nodo siguiente
    while(ini->sig)
    {
        //Si R es NULL, comienza la
        //BUSQUEDA DE DNI OBJETIVO
        if(!r)
        {
            nodoObjetivo = buscarMasRepetido(ini, cantNodos);    //Establecemos el nodo con el DNI objetivo
            r = ini;                                             //R se invoca apuntando al mismo nodo que INI
        }
        //Si R apunta a un Nodo con el DNI Objetivo
        if(comparar(r->info, nodoObjetivo->info) == 0)
        {
            //e INI y R apuntan al mismo Nodo,
            if(ini == r)
            {
                r = r->sig;     //Ambos Avanzan al siguiente, y
                ini = ini->sig; //de esta forma nos ahorramos el proceso de cableado...
                cantNodos--;    //Disminuye la cantidad de nodos
            }
            /*si no, movemos el nodo R hacia antes del nodo INI y despu�s del �ltimo ingresado.
              A este movimiento le llamamos "cableado"*/
            else
            {
                //PROCESO DE CABLEADO:
                tNodo *aux = r->ant;                /*La variable aux nos sirve para no perder
                                                      la posicion donde R debe regresar*/

                if((r->ant->sig = r->sig) != NULL)  //Si el anterior a R, no cablea a NULL,
                    r->sig->ant = r->ant;           //entonces el posterior a R, cablea al anterior a R

                if(ini->ant)                        //Si INI tiene un elemento antes,
                    ini->ant->sig = r;              //el anterior a INI cablea a R

                r->ant = ini->ant;                  //R se posiciona despues del anterior de INI
                ini->ant = r;                       //Y antes de INI
                r->sig = ini;
                r = aux->sig;

                cantNodos--;                        //disminuye la cantidad de Nodos
            }
        }
        //si no, R avanza al siguiente
        else r = r->sig;
    }
}


int  vaciarMostrarDetalleYProm_MIO(tLista *p, FILE *fp,
                                   int (*compararFinal)(const void *, const void *),
                                   int (*acumularCalif)(void **, unsigned *,
                                                   const void *, unsigned),
                                   void (*mostrarFinal)(const void *, FILE *),
                                   void (*mostrarProm)(const void *, int, FILE *))
{
    /*
    DEFINICI�N DE PUNTEROS Y VARIABLES:

    cantElim = Cantidad de nodos eliminados
    cantCalif = Cantidad de Calificaciones

    ACT = Es el puntero que se posiciona al comienzo de cada segmento. Una vez que
          ACT se posiciona, a partir del mismo se desprende el puntero AUX.
    AUX = Puntero que se desprende de ACT con el fin de recorrer los siguientes
          nodos para verificar si tienen el mismo DNI.

    AUX2= Funciona como puntero de existencia temporal para eliminar los nodos
    */
    int cantElim = 0,
        cantCalif;

    tNodo *act = *p;

    //Si ACT no es NULL, se da comienzo
    if(act)
    {
        //Llevamos ACT hasta el comienzo de la lista
        while(act->ant)
            act = act->ant;

        //Mientras ACT no sea NULL
        while(act)
        {
            cantCalif = 0;                  //Comenzamos a contar calificaciones
            tNodo *aux = act->sig;          //AUX se invoca como el siguiente de ACT
            mostrarFinal(NULL, fp);         //Mostramos la cabecera del segmento a eliminar
            mostrarFinal(act->info, fp);    //Mostramos el primer Registro
            cantCalif++;                    //Aumenta el contador de calificaciones

            //PROCESO DE ACUMULACI�N:
            //Mientras AUX tenga el mismo dni que ACT
            while(aux && compararFinal(act->info, aux->info) == 0)
            {
                mostrarFinal(aux->info, fp);                                            //Mostramos AUX
                cantCalif++;                                                            //Aumenta el contador de calificaciones
                acumularCalif(&act->info, &(act->tamInfo), aux->info, aux->tamInfo);    //Acumulamos la nota en ACT
                aux = aux->sig;                                                         //Avanza AUX
            }
            mostrarProm(act->info, cantCalif, fp);  //Mostramos el Promedio
            if(aux)
                aux->ant = NULL;                    //Desvinculamos todo antes de AUX

            //PROCESO DE ELIMINACI�N:
            //Mientras ACT sea diferente de AUX
            while(act != aux)
            {
                tNodo *aux2 = act;  //Invocamos un AUX2 en la posicion de ACT
                act = act->sig;     //ACT Avanza
                free(aux2->info);   //liberamos la info y el nodo
                free(aux2);
                cantElim++;         //Aumenta cantidad de eliminados
            }
        }
        *p = NULL;      //a P se le asigna valor NULL, ya que la lista est� vac�a
    }
    return cantElim;
}


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

