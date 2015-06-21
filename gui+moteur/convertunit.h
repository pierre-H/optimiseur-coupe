/*
 * \file convertunit.h
 * \brief class ConvertUnit chargée de convertir les unités
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 */

#ifndef CONVERTUNIT_H
#define CONVERTUNIT_H

#include <QString>
#include <QLocale>

/*
 * \class ConvertUnit convertunit.h
 *
 * Classe permettant la conversion d'un nombre en mm et inversement.
 * Elle contient les 4 méthodes statiques de conversion.
 * L'argument unité peut être soit le string de l'unité soit l'int suivant :
 * 0 -> m
 * 1 -> cm
 * 2 -> mm
 * 3 -> inches
 * 4 -> feet
 * 5 -> yard
 *
 * Une dernière méthode statique QString toStrSimplifie(double nb) permet
 * de renvoyer un QString qui corresond à l'écriture optimale de nb (ex : 30mm->3cm).
 */

class ConvertUnit
{
public:

    /*
     * \brief Constructeur de la classe ConvertUnit - Non nécessaire vu que toutes les méthodes sont statiques
     */
    ConvertUnit();

    /*
     * \brief Convertit un nombre en mm.
     * \param nb Nombre à convertir
     * \param unite L'unité de nb, doit être compris entre 1 et 6 (Voir la description de la classe pour plus de détails
     * \return Le nombre convertit en mm.
     */
    static double toMm(double nb, int unite);

    /*
     * \brief Convertit un nombre au départ en mm vers l'unité choisie..
     * \param nb Nombre en mm à convertir.
     * \param unite L'unité de conversion : doit être compris entre 1 et 6 (Voir la description de la classe pour plus de détails
     * \return Le nombre convertit en unite.
     */
    static double toUnit(double nb, int unite);

    /*
     * \ brief Convertit un nombre vers le mm.
     * \param nb Nombre à convertir.
     * \param unite La chaîne de caractère de l'unité de nb : m,cm,mm,inches,feet ou yard
     * \return Le nombre convertit en mm.
     */
    static double toMm(double nb, QString unite);

    /*
     * \ brief Convertit un nombre au départ en mm vers l'unité choisie..
     * \param nb Nombre en mm à convertir.
     * \param unite La chaîne de caractère de l'unité : m,cm,mm,inches,feet ou yard
     * \return Le nombre convertit en unite.
     */
    static double toUnit(double nb, QString unite);

    /*
     * \ brief Renvoie l'écriture optimisée d'un nombe à l'origine en mm (ex : ConvertUnit::toStrSimplifie(24) => "2,4 cm")
     * \param nb Nombre en mm dont il faut l'écriture otpimisée.
     * \return Le chaîne de caractère de nb optimisée.
     */
    static QString toStrSimplifie(double nb);
};

#endif // CONVERTUNIT_H
