#include "groupesaisie.h"

GroupeSaisie::GroupeSaisie(QString titre, QFont & fontTitre, QWidget *parent) : QWidget(parent)
{
    // Label : titre
    QLabel * labelTitre = new QLabel(titre);
    labelTitre->setFont(fontTitre);

    // Labels Longueur, Unité, Quantité
    QLabel * labelLongueur = new QLabel("Longueur");
    QLabel * labelUnite = new QLabel("Unité");
    QLabel * labelQuantite = new QLabel("Quantité");

    // Création du Widget contenant les saisies
    QScrollArea * scrollSaisies = new QScrollArea;
    QWidget * widgetSaisies = new QWidget;
    m_layoutSaisies = new QVBoxLayout;
    Saisie * premiereSaisie = new Saisie;
    Saisie * secondeSaisie = new Saisie;
    m_vectorSaisies.append(premiereSaisie);
    m_vectorSaisies.append(secondeSaisie);
    m_layoutSaisies->addWidget(premiereSaisie);
    m_layoutSaisies->addWidget(secondeSaisie);
    m_layoutSaisies->setAlignment(Qt::AlignTop);
    m_layoutSaisies->setSizeConstraint(QLayout::SetMinAndMaxSize);
    m_layoutSaisies->setMargin(0);
    widgetSaisies->setLayout(m_layoutSaisies);
    scrollSaisies->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollSaisies->setWidgetResizable(true);
    scrollSaisies->setMaximumHeight(100);
    //scrollSaisies->setMinimumWidth(270);
    //scrollSaisies->setMaximumWidth(270);
    scrollSaisies->setFrameShape(QFrame::NoFrame);
    scrollSaisies->setWidget(widgetSaisies);

    // Boutons d'ajout et de suppresion de saisie pour les barres avant la découpe
    QPushButton * buttonAjoutSaisie = new QPushButton("Ajouter une saisie");
    m_buttonSupprSaisies = new QPushButton("Supprimer une saisie");
    m_labelNbSaisies = new QLabel("Nombre de saisie : 2");

    // Main Layout
    QGridLayout * mainLayout = new QGridLayout;
    mainLayout->addWidget(labelTitre,0,0,1,3,Qt::AlignBottom);
    mainLayout->setRowMinimumHeight(0,25);
    mainLayout->addWidget(labelLongueur,1,0, Qt::AlignLeft);
    mainLayout->addWidget(labelUnite,1,1, Qt::AlignCenter);
    mainLayout->addWidget(labelQuantite,1,2, Qt::AlignLeft);
    mainLayout->addWidget(scrollSaisies,2,0,2,3, Qt::AlignCenter);
    mainLayout->addWidget(buttonAjoutSaisie, 2,4);
    mainLayout->addWidget(m_buttonSupprSaisies, 2,5);
    mainLayout->addWidget(m_labelNbSaisies,3,4,1,2,Qt::AlignRight|Qt::AlignTop);
    setLayout(mainLayout);

    // Connexions signaux/slots
    QObject::connect(buttonAjoutSaisie, SIGNAL(clicked()), this, SLOT(ajoutSaisie()));
    QObject::connect(m_buttonSupprSaisies, SIGNAL(clicked()), this, SLOT(supprSaisie()));
}

// Slot permettant l'ajout de saisie
void GroupeSaisie::ajoutSaisie(){
    Saisie * newSaisie = new Saisie;
    m_vectorSaisies.append(newSaisie);
    m_layoutSaisies->addWidget(m_vectorSaisies.last());
    m_buttonSupprSaisies->setDisabled(false);
    QString strNbBarre("Nombre de saisie : ");
    strNbBarre += QString::number(m_vectorSaisies.size());
    m_labelNbSaisies->setText(strNbBarre);
}

// Slot permettant la suppression de saisie
void GroupeSaisie::supprSaisie(){
    if(m_vectorSaisies.size()>1){
        m_layoutSaisies->removeWidget(m_vectorSaisies.last());
        delete m_vectorSaisies.last();
        m_vectorSaisies.pop_back();
    }
    if(m_vectorSaisies.size()==1)
        m_buttonSupprSaisies->setDisabled(true);
    QString strNbBarre("Nombre de saisie : ");
    strNbBarre += QString::number(m_vectorSaisies.size());
    m_labelNbSaisies->setText(strNbBarre);
}

QVector<Saisie *> GroupeSaisie::saisies() const{
    return m_vectorSaisies;
}

GroupeSaisie::~GroupeSaisie()
{

}
