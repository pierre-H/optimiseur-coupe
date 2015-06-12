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
    m_layoutBarres->setMargin(0);
    widgetBarres->setLayout(m_layoutBarres);

    // Bouton quitter
    QPushButton * buttonQuitter = new QPushButton(tr("Quitter"));

    // Layout
    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addWidget(labelTitre,0, Qt::AlignTop);
    mainLayout->addWidget(widgetBarres);
    mainLayout->addStretch();
    mainLayout->addWidget(buttonQuitter, 0, Qt::AlignBottom | Qt::AlignRight);

    setLayout(mainLayout);

    // Connexion
    QObject::connect(buttonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

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
        m_layoutBarres->addWidget(m_vectorBarres.last());
    }
}

