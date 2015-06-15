/* fenetreprincipale.h
 * Optimiseur de Coupe
 * 2015 - Pierre-Emmanuel PIRNAY 11296315
 */

#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <list>
#include "formulaireSaisie.h"
#include "widgetresultats.h"
#include "moteur/Combinaison.h"
#include "convertunit.h"
#include "./graphique/wigetgraphique.h"

// Moteur
#include "moteur/List.h"
#include "moteur/MoteurCalculs.h"

/* Cette classe est la fenètre principale.
 * C'est elle qui gère les tabs, les widgets de formulaire, résultat et graphique.
 * C'est aussi elle qui lance le moteur et génère le texte des résultats.
 */

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
