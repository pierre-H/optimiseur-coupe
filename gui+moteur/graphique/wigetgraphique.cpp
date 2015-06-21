/*
 * \file wigetgraphique.cpp
 * \brief Source de la classe WidgetGraphique
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 */

#include "wigetgraphique.h"

WidgetGraphique::WidgetGraphique(QFont & fontTitre, QWidget *parent) : QWidget(parent)
{
    // Titre
    QLabel * labelTitre = new QLabel(tr("Graphique des résultats"));
    labelTitre->setFont(fontTitre);

    // Label : pas de résultats
    m_labelNoResults = new QLabel(tr("Veuillez remplir le formulaire de saisie et cliquer sur \"Appliquer\"."));
    // Graphique
    QWidget * widgetBarres = new QWidget;
    m_layoutBarres = new QVBoxLayout;
    m_layoutBarres->addWidget(m_labelNoResults, 0, Qt::AlignTop | Qt::AlignLeft);
    m_layoutBarres->setMargin(5);
    m_layoutBarres->setAlignment(Qt::AlignTop);
    widgetBarres->setLayout(m_layoutBarres);

    // QScrollArea
    QScrollArea * scrollArea = new QScrollArea;
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setWidgetResizable(true);
    scrollArea->setMinimumHeight(330);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setAlignment(Qt::AlignTop);
    scrollArea->setWidget(widgetBarres);
    scrollArea->setBackgroundRole(QPalette::Base);

    // Bouton quitter
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
    mainLayout->addWidget(scrollArea);
    mainLayout->addStretch();
    mainLayout->addWidget(widgetButtons, 0, Qt::AlignBottom | Qt::AlignRight);

    setLayout(mainLayout);

    // Connexion
    QObject::connect(buttonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(buttonAide, SIGNAL(clicked()), this, SLOT(afficheAide()));
}

void WidgetGraphique::afficheAide(){
    QDesktopServices::openUrl(QUrl::fromLocalFile(QDir::currentPath() + tr("/help/index.fr.html")));
}

void WidgetGraphique::updateGraphique(std::list<Combinaison> * combinaison)
{
    // Vide le widget des barres
    if(m_vectorBarres.size()==0){
        m_labelNoResults->setText("");
    }
    else{
        int i;
        for(i=0; i < m_vectorBarres.size(); i++){
            m_layoutBarres->removeWidget(m_vectorBarres[i]);
            delete m_vectorBarres[i];
        }
        m_vectorBarres.resize(0);
    }

    for(std::list<Combinaison>::iterator it=combinaison->begin();
        it != combinaison->end();
        ++it){
        m_vectorBarres.resize(m_vectorBarres.size()+1);
        m_vectorBarres.last() = new BarreGraphique(&(*it));
        m_layoutBarres->addWidget(m_vectorBarres.last(), 0, Qt::AlignTop);
    }
}

