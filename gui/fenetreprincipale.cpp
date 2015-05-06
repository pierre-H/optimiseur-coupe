#include "fenetreprincipale.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) : QWidget(parent)
{
    // Titre de la fenêtre
    setWindowTitle("Optimiseur de coupe");
    setWindowIcon(QIcon("mainIcon.ico"));

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
    m_groupeSaisieBarres = new GroupeSaisie("Barres avant la découpe :", fontTitre2);
    m_groupeSaisieTron = new GroupeSaisie("Tronçons désirés :", fontTitre2);

    // Label Epaisseur de lame
    QLabel * labelEpaisseur = new QLabel(" Epaisseur de lame");
    labelEpaisseur->setFont(fontTitre2);

    // Epaisseur de lame
    m_epaisseurLame = new QDoubleSpinBox;
    m_epaisseurLame->setMinimum(0);

    // Unité épaisseur de lame
    m_uniteEpaisseurLame = new QComboBox;
    m_uniteEpaisseurLame->addItem("mm");
    m_uniteEpaisseurLame->addItem("in");

    // Bouton Appliquer et Quitter et changement de mode
    QPushButton * buttonAppliquer = new QPushButton("Appliquer");
    buttonAppliquer->setDefault(true);
    QPushButton * buttonQuitter = new QPushButton("Quitter");

    // Layout pour Epaisseur et les boutons Appliquer/Quitter
    QHBoxLayout * layoutEpaiButt = new QHBoxLayout;
    layoutEpaiButt->addWidget(m_epaisseurLame);
    layoutEpaiButt->addWidget(m_uniteEpaisseurLame);
    layoutEpaiButt->addStretch();
    layoutEpaiButt->addWidget(buttonAppliquer);
    layoutEpaiButt->addWidget(buttonQuitter);

    // ajout des widgets au  Layout Principal
    layoutPrincipal->addWidget(labelRemplirInfos);
    layoutPrincipal->addWidget(m_groupeSaisieBarres);
    layoutPrincipal->addWidget(m_groupeSaisieTron);
    layoutPrincipal->addWidget(labelEpaisseur);
    layoutPrincipal->addLayout(layoutEpaiButt);

    // Set Layout Principal
    setLayout(layoutPrincipal);

    // Connexion signaux/slots
    QObject::connect(buttonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(buttonAppliquer, SIGNAL(clicked()), this, SLOT(traiterFormulaire()));
}

void FenetrePrincipale::traiterFormulaire(){
    QVector <Saisie *> resultatsBarres = m_groupeSaisieBarres->saisies();
    QVector <Saisie *> resultatsTron = m_groupeSaisieTron->saisies();
    int i;

    // Détection de l'erreur : total longueur des barres av découpe < total longueur tronçons demandés
    double totalBarre = 0, totalTron = 0;
    for(i = 0; i != resultatsBarres.size();i++)
        totalBarre += resultatsBarres[i]->longueur();
    for(i = 0; i != resultatsTron.size();i++)
        totalTron += resultatsTron[i]->longueur();
    if(totalBarre < totalTron)
        QMessageBox::warning(this, "Erreur",
                             "La longueur totale des barres avant la découpe "
                             "est plus petite que la longueur totale des tronçons demandés.");

    // Détection de l'erreur : épaisseur de la lame > + petite longueur
    double temp = resultatsBarres.at(0)->longueur();
    for(i=1;i!=resultatsBarres.size();i++){
        if(resultatsBarres.at(i)->longueur() < temp)
            temp = resultatsBarres.at(i)->longueur();
    }
    if(ConvertUnit::toMm(m_epaisseurLame->value(), m_uniteEpaisseurLame->currentText())
            > temp )
        QMessageBox::warning(this,"Erreur",
                             "L'épaisseur de la lame est plus grande que la plus "
                             "petite longueur des barres avant la découpe.");
}

FenetrePrincipale::~FenetrePrincipale()
{

}
