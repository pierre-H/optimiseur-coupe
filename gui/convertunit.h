#ifndef CONVERTUNIT_H
#define CONVERTUNIT_H

/* Classe permettant la conversion d'un nombre en mm et inversement.
 * Elle contient uniquement les 2 méthodes statiques de conversion.
 * Par convention, l'argument unite désigne :
 * 1 -> m
 * 2 -> cm
 * 3 -> mm
 * 4 -> inches
 * 5 -> feet
 * 6 -> yard
 */

class ConvertUnit
{
public:
    ConvertUnit();
    static float toMm(float nb, int unite);
    static float toUnit(float nb, int unite);
};

#endif // CONVERTUNIT_H
