/*
 * \file formulaireSaisie.cpp
 * \brief Source de la classe FormulaireSaisie
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 */

#include "formulaireSaisie.h"

FormulaireSaisie::FormulaireSaisie(QFont & fontTitre, QWidget *parent) : QWidget(parent)
{
    // Layout principal
    QVBoxLayout * layoutPrincipal = new QVBoxLayout;

    // Label : demande de remplir les infos
    QLabel * labelRemplirInfos = new QLabel(tr("Veuillez remplir les informations suivantes :"));
    labelRemplirInfos->setFont(fontTitre);

    // Groupes de saisie
    QFont fontTitre2;
    fontTitre2.setPointSize(11);
    fontTitre2.setBold(true);
    m_groupeSaisieBarres = new GroupeSaisie(tr("Barres avant la découpe :"), fontTitre2);
    m_groupeSaisieTron = new GroupeSaisie(tr("Tronçons désirés :"), fontTitre2);

    // Label Epaisseur de lame
    QLabel * labelEpaisseur = new QLabel(tr("Epaisseur de lame"));
    labelEpaisseur->setFont(fontTitre2);

    // Epaisseur de lame
    m_epaisseurLame = new QDoubleSpinBox;
    m_epaisseurLame->setMinimum(0);

    // Unité épaisseur de lame
    m_uniteEpaisseurLame = new QComboBox;
    m_uniteEpaisseurLame->addItem("mm");
    m_uniteEpaisseurLame->addItem("in");

    // Bouton Appliquer, Aide et Quitter et changement de mode
    m_buttonAppliquer = new QPushButton(tr("Appliquer"));
    m_buttonAppliquer->setDefault(true);
    QPushButton * buttonAide = new QPushButton(tr("Aide"));
    m_buttonQuitter = new QPushButton(tr("Quitter"));

    // Layout pour Epaisseur et les boutons Appliquer/Quitter
    QHBoxLayout * layoutEpaiButt = new QHBoxLayout;
    layoutEpaiButt->addWidget(m_epaisseurLame);
    layoutEpaiButt->addWidget(m_uniteEpaisseurLame);
    layoutEpaiButt->addStretch();
    layoutEpaiButt->addWidget(m_buttonAppliquer);
    layoutEpaiButt->addWidget(buttonAide);
    layoutEpaiButt->addWidget(m_buttonQuitter);

    // ajout des widgets au  Layout Principal
    layoutPrincipal->addWidget(labelRemplirInfos);
    layoutPrincipal->addWidget(m_groupeSaisieBarres);
    layoutPrincipal->addWidget(m_groupeSaisieTron);
    layoutPrincipal->addWidget(labelEpaisseur);
    layoutPrincipal->addLayout(layoutEpaiButt);

    // Set Layout Principal
    setLayout(layoutPrincipal);

    // Connexion signaux/slots
    QObject::connect(m_buttonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(buttonAide, SIGNAL(clicked()), this, SLOT(afficheAide()));
}

void FormulaireSaisie::afficheAide(){
    QDesktopServices::openUrl(QUrl::fromLocalFile(QDir::currentPath() + tr("/help/index.fr.html")));
}

QPushButton * FormulaireSaisie::buttonAppliquer() const{
    return m_buttonAppliquer;
}

GroupeSaisie * FormulaireSaisie::groupeSaisieBarres() const{
    return m_groupeSaisieBarres;
}

GroupeSaisie * FormulaireSaisie::groupeSaisieTron() const{
    return m_groupeSaisieTron;
}

double FormulaireSaisie::epaisseurLame() const{
    return ConvertUnit::toMm(m_epaisseurLame->value(), m_uniteEpaisseurLame->currentText());
}

QComboBox * FormulaireSaisie::uniteEpaisseurLame() const{
    return m_uniteEpaisseurLame;
}

FormulaireSaisie::~FormulaireSaisie()
{

}
