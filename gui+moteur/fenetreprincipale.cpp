/*
 * \file fenetreprincipale.cpp
 * \brief Source de la classe FenetrePrincipale
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 */

#include "fenetreprincipale.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) : QWidget(parent)
{
    // Titre de la fenêtre
    setWindowTitle(tr("Optimiseur de coupe"));
    setWindowIcon(QIcon("mainIcon.ico"));

    // Police titre
    QFont fontTitre;
    fontTitre.setPointSize(12);
    fontTitre.setBold(true);
    fontTitre.setStyleHint(QFont::SansSerif);

    // Formulaire
    m_tabs = new QTabWidget(this);
    m_formulaireSaisie = new FormulaireSaisie(fontTitre);
    m_tabs->addTab(m_formulaireSaisie, tr("Formulaire de saisie"));

    // Résultats
    m_widgetResultats = new WidgetResultats(fontTitre);
    m_tabs->addTab(m_widgetResultats, tr("Résultats"));

    // Graphique
    m_widgetGraphique = new WidgetGraphique(fontTitre);
    m_tabs->addTab(m_widgetGraphique, tr("Graphique des résultats"));

    // Infos
    OngletInfo * infos = new OngletInfo;
    m_tabs->addTab(infos, tr("A propos"));
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

        if(moteur->pilote() == -1){
            QMessageBox::warning(this, tr("Calculs arrétés"), tr("Les calculs demandés sont trop grands. Aucun résultat ne sera affiché."));
            //return;
        }

        List * listFinaletroncons = moteur->getTroncons();
        if(not listFinaletroncons->empty()){
            erreur=10;
            text = tr("Vous n'avez pas assez de matière première pour "
                              "couper tous les tronçons désirés.<br>Liste des troncons restants:<br>");
            text += listFinaletroncons->toStr(true);
            QMessageBox::warning(this, tr("Erreur"), text);
        }

        text="";

        List * listFinaleBarres = moteur->getBarres();
        if(not listFinaleBarres->empty()){
            text = tr("Il vous reste une/des barre(s) entière(s) non utilisée(s) :<br>Liste de la/des barre(s) restante(s) :<br>");
            text += listFinaleBarres->toStr(true) + "<hr>";
        }

        if(erreur==10){
            text += tr("Vous n'avez pas eu assez de matière première pour "
                              "couper tous les tronçons que vous désiriez.<br>Liste de troncons restants:<br>");
            text += listFinaletroncons->toStr(true) + "<hr>";
        }

        // Liste des coupes
        text += tr("<br>Voici la liste des coupes que vous devez effectuer :<ul>");
        list<Combinaison> * listResultats = moteur->getPointResultatFinal();
        for(list<Combinaison>::iterator it=listResultats->begin();
            it != listResultats->end();
            ++it){
            text+=it->toStr();
        }
        text += tr("</ul>Vous avez un rendement moyen de ") + QString::number(moteur->calculeRendementFinal(),'g', 4) + "%.";
        m_widgetResultats->updateResultats(text);
        m_widgetGraphique->updateGraphique(listResultats);
        m_tabs->setCurrentIndex(1);
        delete tronconsList;
        delete barresList;
        delete moteur;
    }
}
