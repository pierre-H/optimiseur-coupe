/*
 * \file convertunit.cpp
 * \brief source de la classe ConvertUnit chargée de convertir les unités
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 */

#include "convertunit.h"

ConvertUnit::ConvertUnit()
{

}

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

QString ConvertUnit::toStrSimplifie(double nb){
    QString text("");
    if(QLocale::system().measurementSystem() == QLocale::MetricSystem){
        if((nb-1000) >= 0)
            text += QString::number(ConvertUnit::toUnit(nb,0)) + " m";
        else if((nb-10) >= 0)
            text += QString::number(ConvertUnit::toUnit(nb, 1)) + " cm";
        else
            text += QString::number(nb) + " mm";
    }
    else{
        if((nb-914.4) >= 0)
            text += QString::number(ConvertUnit::toUnit(nb,5)) + " yard";
        else if ((nb-304.8) >= 0)
            text += QString::number(ConvertUnit::toUnit(nb,4)) + " feet";
        else
            text += QString::number(ConvertUnit::toUnit(nb,3)) + " inches";
    }
    return text;
}

