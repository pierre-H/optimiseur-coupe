/*
 * \file saisie.h
 * \brief Header de la classe Saisie
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 */

#ifndef SAISIE_H
#define SAISIE_H

#include <QWidget>
#include <QWidget>
#include <QLayout>
#include <QSpinBox>
#include <QComboBox>
#include <QLabel>
#include "convertunit.h"

/* \class Saisie saisie.h
 * \brief Classe de Saisie
 * Une saisie est un widget qui contient :
 * - un champ DoubleSpinBox concernant la longueur
 * - un champ Combobox concernant l'unité
 * - un champ SpinBox concernant la quantité
 */

class Saisie : public QWidget
{
    Q_OBJECT
public:
    // \brief Constructeur de la classe Saisie
    // \param numero Contient le numéro de la saisie
    explicit Saisie(int numero, QWidget *parent = 0);

    // \brief Déconstructeur de la classe Saisie
    ~Saisie();

    // \brief Méthode d'accès à la longueur
    // \return la longueur en mm
    double longueur() const;

    // \brief Méthode d'accès à l'unité
    /* \return Renvoie l'unité.
     * Par convention :
     * 0 -> m
     * 1 -> cm
     * 2 -> mm
     * 3 -> inches
     * 4 -> feet
     * 5 -> yard
     */
    int unite() const;

    // \brief Méthode d'accès à la quantité
    // \return Renvoie la quantité
    int quantite() const;

private:
    QDoubleSpinBox * m_longueur;
    QComboBox * m_unite;
    QSpinBox * m_quantite;
signals:

public slots:
};

#endif // SAISIE_H
