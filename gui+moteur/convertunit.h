#ifndef CONVERTUNIT_H
#define CONVERTUNIT_H

#include <QString>
#include <QLocale>

/* Classe permettant la conversion d'un nombre en mm et inversement.
 * Elle contient uniquement les 4 méthodes statiques de conversion.
 * L'argument unité peut être soit le string de l'unité soit l'int suivant :
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
    static QString toStrSimplifie(double nb);
};

#endif // CONVERTUNIT_H