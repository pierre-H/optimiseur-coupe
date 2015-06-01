#include "widgetresultats.h"

WidgetResultats::WidgetResultats(QWidget *parent) : QWidget(parent)
{
    // Label Titre
    QLabel * labelTitre = new QLabel(tr("Résultats"));
    QFont fontTitre1("Droid Sans", 12);
    fontTitre1.setBold(true);
    labelTitre->setFont(fontTitre1);

    // Label Résultats
    m_labelResultat = new QLabel(tr("Veuillez remplir le formulaire de saisie et cliquer sur \"Appliquer\"."));
    m_labelResultat->setTextFormat(Qt::RichText);

    // Bouton quitter
    QPushButton * buttonQuitter = new QPushButton(tr("Quitter"));
    QPushButton * buttonSaveHTML = new QPushButton(tr("Enregistrer en HTML"));
    QHBoxLayout * layoutBouttons = new QHBoxLayout;
    QWidget * widgetBouttons = new QWidget();
    layoutBouttons->addWidget(buttonSaveHTML);
    layoutBouttons->addWidget(buttonQuitter);
    widgetBouttons->setLayout(layoutBouttons);

    // Layout
    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addWidget(labelTitre,0, Qt::AlignTop);
    mainLayout->addWidget(m_labelResultat,0,Qt::AlignTop);
    mainLayout->addStretch();
    mainLayout->addWidget(widgetBouttons, 0, Qt::AlignBottom | Qt::AlignRight);

    setLayout(mainLayout);

    // Connexion
    QObject::connect(buttonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void WidgetResultats::updateResultats(QString & text){
    m_labelResultat->setText(text);
}

