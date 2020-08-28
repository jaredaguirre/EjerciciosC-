/**//* 39.336.695-VACA_AGUIRRE,JaredMartin-(05-1965) *//**/

#ifndef FIGURAINVALIDAEXCEPTION_H_
#define FIGURAINVALIDAEXCEPTION_H_

#include <iostream>
#include <exception>
using namespace std;

class FiguraInvalidaException : public exception{
public:
    FiguraInvalidaException() : exception(){}
    const char *what() throw()
    {
        return "Figura Inválida";
    }
};



#endif // FIGURAINVALIDAEXCEPTION_H_
