#include "fenetreprincipale.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) : QWidget(parent)
{
    // Titre de la fenêtre
    setWindowTitle("Optimiseur de coupe");

    // Layout principal
    QVBoxLayout * layoutPrincipal = new QVBoxLayout;

    // Label : demande de remplir les infos
    QLabel * labelRemplirInfos = new QLabel("Veuillez remplir les informations suivantes :");
    QFont fontTitre1("Droid Sans", 12);
    fontTitre1.setBold(true);
    labelRemplirInfos->setFont(fontTitre1);

    // Groupes de saisie
    QFont fontTitre2("Droid Sans", 10);
    fontTitre2.setBold(true);
    GroupeSaisie * groupeSaisieBarres = new GroupeSaisie("Barres avant la découpe :", fontTitre2);
    GroupeSaisie * groupeSaisieTron = new GroupeSaisie("Tronçons désirés :", fontTitre2);

    // Label Epaisseur de lame
    QLabel * labelEpaisseur = new QLabel(" Epaisseur de lame");
    labelEpaisseur->setFont(fontTitre2);

    // Epaisseur de lame
    QDoubleSpinBox * epaisseurLame = new QDoubleSpinBox;
    epaisseurLame->setMinimum(0);

    // Unité épaisseur de lame
    QComboBox * uniteEpaisseurLame = new QComboBox;
    uniteEpaisseurLame->addItem("mm");
    uniteEpaisseurLame->addItem("in");

    // Bouton Appliquer et Quitter et changement de mode
    QPushButton * buttonAppliquer = new QPushButton("Appliquer");
    buttonAppliquer->setDefault(true);
    QPushButton * buttonQuitter = new QPushButton("Quitter");

    // Layout pour Epaisseur et les boutons Appliquer/Quitter
    QHBoxLayout * layoutEpaiButt = new QHBoxLayout;
    layoutEpaiButt->addWidget(epaisseurLame);
    layoutEpaiButt->addWidget(uniteEpaisseurLame);
    layoutEpaiButt->addStretch();
    layoutEpaiButt->addWidget(buttonAppliquer);
    layoutEpaiButt->addWidget(buttonQuitter);

    // ajout des widgets au  Layout Principal
    layoutPrincipal->addWidget(labelRemplirInfos);
    layoutPrincipal->addWidget(groupeSaisieBarres);
    layoutPrincipal->addWidget(groupeSaisieTron);
    layoutPrincipal->addWidget(labelEpaisseur);
    layoutPrincipal->addLayout(layoutEpaiButt);

    // Set Layout Principal
    setLayout(layoutPrincipal);

    // Connexion signaux/slots
    QObject::connect(buttonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
}

FenetrePrincipale::~FenetrePrincipale()
{

}

