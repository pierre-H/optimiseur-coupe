/*
 * \file widgetresultats.cpp
 * \brief Source de la classe WidgetResultats
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 */

#include "widgetresultats.h"

WidgetResultats::WidgetResultats(QFont & fontTitre, QWidget *parent) : QWidget(parent)
{
    // Label Titre
    QLabel * labelTitre = new QLabel(tr("Résultats"));
    labelTitre->setFont(fontTitre);

    // Label Résultats
    m_labelResultat = new QTextEdit(tr("Veuillez remplir le formulaire de saisie et cliquer sur \"Appliquer\"."));
    m_labelResultat->setReadOnly(true);
    m_labelResultat->setMinimumSize(530,310);
    m_labelResultat->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    m_labelResultat->setFrameShape(QFrame::NoFrame);

    // Bouton Aide et Quitter
    QPushButton * buttonQuitter = new QPushButton(tr("Quitter"));
    QPushButton * buttonAide = new QPushButton(tr("Aide"));
    QHBoxLayout * layoutButtons = new QHBoxLayout;
    layoutButtons->addWidget(buttonAide);
    layoutButtons->addWidget(buttonQuitter);
    QWidget * widgetButtons = new QWidget;
    widgetButtons->setLayout(layoutButtons);

    // Layout
    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addWidget(labelTitre,0, Qt::AlignTop);
    mainLayout->addWidget(m_labelResultat);
    mainLayout->addWidget(widgetButtons, 0, Qt::AlignBottom | Qt::AlignRight);

    setLayout(mainLayout);

    // Connexion
    QObject::connect(buttonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(buttonAide, SIGNAL(clicked()), this, SLOT(afficheAide()));

}

void WidgetResultats::afficheAide(){
    QDesktopServices::openUrl(QUrl::fromLocalFile(QDir::currentPath() + tr("/help/index.fr.html")));
}

void WidgetResultats::updateResultats(QString & text){
    m_labelResultat->setText(text);
}

