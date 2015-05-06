#include "convertunit.h"

ConvertUnit::ConvertUnit()
{

}

// Convertit nb en mm. L'unité de nb est unite.
// retourne 0 si unite n'est pas compris entre 1 et 6.
double ConvertUnit::toMm(double nb, int unite){
    double a;
    switch (unite)
    {
    case 0:
        a = nb * 1000;
        break;
    case 1:
        a = nb * 10;
        break;
    case 2:
        a = nb;
        break;
    case 3:
        a = nb*25.4;
        break;
    case 4:
        a = nb * 304.8;
        break;
    case 5:
        a = nb * 914.4;
        break;
    default:
        a=0;
    }
    return a;
}

// Convertit nb en unite. L'unité de nb est le mm.
// retourne 0 si unite n'est pas compris entre 1 et 6.
double ConvertUnit::toUnit(double nb, int unite){
    double a;
    switch(unite)
    {
    case 0:
        a = nb/1000;
        break;
    case 1:
        a = nb * 0.1;
        break;
    case 2:
        a = nb;
        break;
    case 3:
        a = nb * 0.039;
        break;
    case 4:
        a = (nb * 3.28)/1000;
        break;
    case 5:
        a = (nb*1.09)/1000;
        break;
    default:
        a=0;
    }
    return a;
}

// Convertit nb en mm. L'unité de nb est unite.
// retourne 0 si unite n'est pas une unité supportée
double ConvertUnit::toMm(double nb, QString unite){
    double a;
    if(unite=="m")
        a = nb * 1000;
    else if (unite=="cm")
        a = nb * 10;
    else if(unite=="mm")
        a = nb;
    else if(unite=="inches")
        a = nb*25.4;
    else if(unite=="feet")
        a = nb * 304.8;
    else if(unite=="yard")
        a = nb * 914.4;
    else
        a=0;
    return a;
}

// Convertit nb en unite. L'unité de nb est le mm.
// retourne 0 si unite n'est pas une unité supportée
double ConvertUnit::toUnit(double nb, QString unite){
    double a;
    if(unite=="m")
        a = nb/1000;
    else if (unite=="cm")
        a = nb * 0.1;
    else if(unite=="mm")
        a = nb;
    else if(unite=="inches")
        a = nb * 0.039;
    else if(unite=="feet")
        a = (nb * 3.28)/1000;
    else if(unite=="yard")
        a = (nb*1.09)/1000;
    else
        a=0;
    return a;
}

