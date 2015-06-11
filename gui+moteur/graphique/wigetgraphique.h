#ifndef WIGETGRAPHIQUE_H
#define WIGETGRAPHIQUE_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>
#include <QVector>
#include <list>
#include "../moteur/Combinaison.h"
#include "barregraphique.h"

class WidgetGraphique : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetGraphique(QFont & fontTitre,QWidget *parent = 0);
    void updateGraphique(std::list<Combinaison> *combinaison);
private:
    QVBoxLayout * m_layoutBarres;
    QLabel * m_labelNoResults;
    QVector <BarreGraphique *> m_vectorBarres;
signals:

public slots:
};

#endif // WIGETGRAPHIQUE_H
