#include "convertunit.h"

ConvertUnit::ConvertUnit()
{

}

// Convertit nb en mm. L'unité de nb est unite.
// retourne 0 si unite n'est pas compris entre 1 et 6.
float ConvertUnit::toMm(float nb, int unite){
    float a;
    switch (unite)
    {
    case 1:
        a = nb * 1000;
        break;
    case 2:
        a = nb * 10;
        break;
    case 3:
        a = nb;
        break;
    case 4:
        a = nb*25.4;
        break;
    case 5:
        a = nb * 304.8;
        break;
    case 6:
        a = nb * 914.4;
        break;
    default:
        a=0;
    }
    return a;
}

// Convertit nb en unite. L'unité de nb est le mm.
// retourne 0 si unite n'est pas compris entre 1 et 6.
float ConvertUnit::toUnit(float nb, int unite){
    float a;
    switch(unite)
    {
    case 1:
        a = nb/1000;
        break;
    case 2:
        a = nb * 0.1;
        break;
    case 3:
        a = nb;
        break;
    case 4:
        a = nb * 0.039;
        break;
    case 5:
        a = (nb * 3.28)/1000;
        break;
    case 6:
        a = (nb*1.09)/1000;
        break;
    default:
        a=0;
    }
    return a;
}
