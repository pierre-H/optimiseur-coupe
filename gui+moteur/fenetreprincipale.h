#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <list>
#include "formulaireSaisie.h"
#include "widgetresultats.h"
#include "moteur/Combinaison.h"
#include "graphique/widgetgraphique.h"
#include <convertunit.h>

// Moteur
#include "moteur/List.h"
#include "moteur/MoteurCalculs.h"

class FenetrePrincipale : public QWidget
{
    Q_OBJECT
public:
    explicit FenetrePrincipale(QWidget *parent = 0);

signals:

private:
    QTabWidget * m_tabs;
    FormulaireSaisie * m_formulaireSaisie;
    WidgetResultats * m_widgetResultats;
    WidgetGraphique * m_widgetGraphique;
public slots:
    void traiterFormulaire();
};

#endif // FENETREPRINCIPALE_H
