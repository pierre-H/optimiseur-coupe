#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QWidget>
#include <QIcon>
#include <QTabWidget>
#include <QVBoxLayout>
#include "formulaireSaisie.h"
#include "widgetresultats.h"

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
public slots:
    void traiterFormulaire();
};

#endif // FENETREPRINCIPALE_H
