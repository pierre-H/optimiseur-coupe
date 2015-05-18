#include "widgetresultats.h"

WidgetResultats::WidgetResultats(QWidget *parent) : QWidget(parent)
{
    // Label Titre
    QLabel * labelTitre = new QLabel(tr("Résultats"));
    QFont fontTitre1("Droid Sans", 12);
    fontTitre1.setBold(true);
    labelTitre->setFont(fontTitre1);

    // Layout
    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addWidget(labelTitre,0, Qt::AlignTop);

    setLayout(mainLayout);
}

