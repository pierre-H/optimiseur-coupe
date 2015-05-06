#ifndef CONVERTUNIT_H
#define CONVERTUNIT_H

#include <QString>

/* Classe permettant la conversion d'un nombre en mm et inversement.
 * Elle contient uniquement les 2 méthodes statiques de conversion.
 * Par convention, l'argument unite désigne :
 * 0 -> m
 * 1 -> cm
 * 2 -> mm
 * 3 -> inches
 * 4 -> feet
 * 5 -> yard
 */

class ConvertUnit
{
public:
    ConvertUnit();
    static double toMm(double nb, int unite);
    static double toUnit(double nb, int unite);
    static double toMm(double nb, QString unite);
    static double toUnit(double nb, QString unite);

};

#endif // CONVERTUNIT_H
