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

    //Déclarations diverses
    QVector <Saisie *> resultatsBarres = m_formulaireSaisie->groupeSaisieBarres()->saisies();
    QVector <Saisie *> resultatsTron = m_formulaireSaisie->groupeSaisieTron()->saisies();
    int i,j, erreur=0;

    // Détection de l'erreur : total longueur des barres av découpe < total longueur tronçons demandés
    double totalBarre = 0, totalTron = 0;
    for(i = 0; i != resultatsBarres.size();i++){
        for(j=0; j!= resultatsBarres[i]->quantite();j++)
            totalBarre += resultatsBarres[i]->longueur();
    }
    for(i = 0; i != resultatsTron.size();i++){
        for(j=0; j!= resultatsTron[i]->quantite();j++)
            totalTron += resultatsTron[i]->longueur();
    }
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
    if(m_formulaireSaisie->epaisseurLame() > temp){
        QMessageBox::warning(this,tr("Erreur"),
                             tr("L'épaisseur de la lame est plus grande que la plus "
                             "petite longueur des barres avant la découpe."));
        erreur++;
    }

    // Pas d'erreur détectée : lancement du moteur
    if(erreur==0){
        QString text("");
        List * tronconsList = new List();
        List * barresList =  new List();
        createSortedList(tronconsList, resultatsTron);
        createSortedList(barresList, resultatsBarres);
        MoteurCalculs * moteur = new MoteurCalculs(tronconsList, barresList, m_formulaireSaisie->epaisseurLame());

        moteur->pilote();

        List * listFinaletroncons = moteur->getTroncons();
        if(not listFinaletroncons->empty()){
            erreur=10;
            text = tr("Vous n'avez pas eu assez de matière première pour "
                              "couper tous les tronçons que vous désiriez.<br>Liste de troncons restants:<br>");
            text += listFinaletroncons->toStr(true);
            QMessageBox::warning(this, tr("Erreur"), text);
        }

        text="";

        List * listFinaleBarres = moteur->getBarres();
        if(not listFinaleBarres->empty()){
            text = tr("Il vous reste des barres entières que vous n'avez pas utilisées :<br>Liste des barres restantes :<br>");
            text += listFinaleBarres->toStr(true) + "<hr>";
        }

        if(erreur==10){
            text += tr("Vous n'avez pas eu assez de matière première pour "
                              "couper tous les tronçons que vous désiriez.<br>Liste de troncons restants:<br>");
            text += listFinaletroncons->toStr(true) + "<hr>";
        }

        text += tr("<br>Voici la liste des coupes que vous devez effectuer :<br>");
        list<Combinaison> listResultats = moteur->getResultatFinal();
        for(list<Combinaison>::iterator it=listResultats.begin();
            it != listResultats.end();
            ++it){
            text+=it->toStr()+"<br>";
        }
        text += tr("Exigence : ") + QString::number(moteur->getExigence()) + "<br>";
        text += tr("Vous avez un rendement moyen de ") + QString::number(moteur->calculeRendementFinal(),'g', 4) + "%.";
        m_widgetResultats->updateResultats(text);
        m_tabs->setCurrentIndex(1);
        delete tronconsList;
        delete barresList;
        delete moteur;
    }
}
