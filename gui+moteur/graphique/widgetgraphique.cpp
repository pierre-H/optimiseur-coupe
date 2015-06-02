#include "widgetgraphique.h"

WidgetGraphique::WidgetGraphique(QFont & fontTitre, QWidget *parent) : QWidget(parent)
{
    // Titre
    QLabel * labelTitre = new QLabel("Graphique des résultats");
    labelTitre->setFont(fontTitre);

    // Bouton quitter et sauvegarder
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
    mainLayout->addStretch();
    mainLayout->addWidget(widgetBouttons, 0, Qt::AlignBottom | Qt::AlignRight);

    setLayout(mainLayout);

    // Connexion
    QObject::connect(buttonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

}

