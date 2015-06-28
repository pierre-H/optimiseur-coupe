/*
 * \file ongletinfo.cpp
 * \brief Source de la classe OngletInfo
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 */

#include "ongletinfo.h"

OngletInfo::OngletInfo(QWidget *parent) : QWidget(parent)
{
    // Texte infos
    QVBoxLayout * mainLayout = new QVBoxLayout;
    QLabel * infos = new QLabel;
    infos->setTextFormat(Qt::RichText);
    infos->setText(tr("<h3>Optimiseur de Coupe</h3><p>Réalisé dans le cadre de l'IED Paris 8 - Licence d'Informatique L2</p><p>Auteurs :</p><ul><li>Rebecca CHARBIT</li><li>Xavier JANIN</li><li>Pierre-Emmanuel PIRNAY</li></ul>"));

    // Boutton à propos de Qt
    QPushButton * infosQt = new QPushButton(tr("Informations Qt"));

    // Boutton quitter
    QPushButton * quitter = new QPushButton(tr("Quitter"));

    // Widget Bouttons
    QWidget * bouttons = new QWidget;
    QHBoxLayout * bouttonsLayout = new QHBoxLayout;
    bouttonsLayout->addWidget(infosQt);
    bouttonsLayout->addWidget(quitter);
    bouttons->setLayout(bouttonsLayout);

    // Layout
    mainLayout->addWidget(infos,0,Qt::AlignTop);
    mainLayout->addWidget(bouttons, 0, Qt::AlignBottom | Qt::AlignRight);
    setLayout(mainLayout);

    QObject::connect(infosQt, SIGNAL(clicked()), qApp, SLOT(aboutQt()));
    QObject::connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
}

