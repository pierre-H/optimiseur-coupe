/*
 * \file saisie.cpp
 * \brief Source de la classe Saisie
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 */

#include "saisie.h"

Saisie::Saisie(int numero, QWidget *parent) : QWidget(parent)
{
    // Layout
    QHBoxLayout * layoutH = new QHBoxLayout;

    // Ajout du numéro
    QLabel * labelNumero = new QLabel(QString::number(numero)+".");

    // Ajout de la longueur
    m_longueur = new QDoubleSpinBox;
    m_longueur->setMinimum(0.01);
    m_longueur->setValue(10);
    m_longueur->setMaximum(999.99);

    // Ajout de l'unité
    m_unite = new QComboBox;
    m_unite->addItem("m");
    m_unite->addItem("cm");
    m_unite->addItem("mm");
    m_unite->addItem("inches");
    m_unite->addItem("feet");
    m_unite->addItem("yard");
    m_unite->setInsertPolicy(QComboBox::NoInsert);
    m_unite->setCurrentIndex(1);

    // Ajout de la quantite
    m_quantite = new QSpinBox;
    m_quantite->setMinimum(1);
    m_quantite->setMaximum(99999);
    m_quantite->setMaximumWidth(70);

    // ajout des widgets
    layoutH->addWidget(labelNumero);
    layoutH->addWidget(m_longueur,0,Qt::AlignLeft);
    layoutH->addWidget(m_unite,0,Qt::AlignCenter);
    layoutH->addWidget(m_quantite,0, Qt::AlignRight);
    layoutH->addSpacing(20);
    layoutH->setMargin(0);

    //set layout
    setLayout(layoutH);
}

// Renvoie la longueur en mm
double Saisie::longueur() const{
    return ConvertUnit::toMm(m_longueur->value(), m_unite->currentIndex());
}

/* Renvoie l'unité. Par convention :
 * 0 -> m
 * 1 -> cm
 * 2 -> mm
 * 3 -> inches
 * 4 -> feet
 * 5 -> yard
 */
int Saisie::unite() const{
    return m_unite->currentIndex();
}

// Renvoie la quantite
int Saisie::quantite() const{
    return m_quantite->value();
}

Saisie::~Saisie()
{

}

