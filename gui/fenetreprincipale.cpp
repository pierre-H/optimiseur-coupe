#include "fenetreprincipale.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) : QWidget(parent)
{
    // Titre de la fenêtre
    setWindowTitle(tr("Optimiseur de coupe"));
    setWindowIcon(QIcon("mainIcon.ico"));

    // Tabs
    m_tabs = new QTabWidget(this);
    m_formulaireSaisie = new FormulaireSaisie;
    m_tabs->addTab(m_formulaireSaisie, tr("Formulaire de saisie"));

    // Résultats
    m_widgetResultats = new WidgetResultats;
    m_tabs->addTab(m_widgetResultats, tr("Résultats"));

    //Layout
    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_tabs);
    setLayout(mainLayout);

    // Connexions
    QObject::connect(m_formulaireSaisie->buttonAppliquer(), SIGNAL(clicked()),
                     this, SLOT(traiterFormulaire()) );
}

void FenetrePrincipale::traiterFormulaire(){
    QVector <Saisie *> resultatsBarres = m_formulaireSaisie->groupeSaisieBarres()->saisies();
    QVector <Saisie *> resultatsTron = m_formulaireSaisie->groupeSaisieTron()->saisies();
    int i, erreur=0;

    // Détection de l'erreur : total longueur des barres av découpe < total longueur tronçons demandés
    double totalBarre = 0, totalTron = 0;
    for(i = 0; i != resultatsBarres.size();i++)
        totalBarre += resultatsBarres[i]->longueur();
    for(i = 0; i != resultatsTron.size();i++)
        totalTron += resultatsTron[i]->longueur();
    if(totalBarre < totalTron){
        QMessageBox::warning(this, tr("Erreur"),
                             tr("La longueur totale des barres avant la découpe "
                             "est plus petite que la longueur totale des tronçons demandés."));
        erreur++;
    }

    // Détection de l'erreur : épaisseur de la lame > + petite longueur
    double temp = resultatsBarres.at(0)->longueur();
    for(i=1;i!=resultatsBarres.size();i++){
        if(resultatsBarres.at(i)->longueur() < temp)
            temp = resultatsBarres.at(i)->longueur();
    }
    if(ConvertUnit::toMm(m_formulaireSaisie->epaisseurLame()->value(),
                         m_formulaireSaisie->uniteEpaisseurLame()->currentText() ) > temp ){
        QMessageBox::warning(this,tr("Erreur"),
                             tr("L'épaisseur de la lame est plus grande que la plus "
                             "petite longueur des barres avant la découpe."));
        erreur++;
    }
    if(erreur==0){
        m_tabs->setCurrentIndex(1);
    }
}
