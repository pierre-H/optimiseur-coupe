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
#include <QScrollArea>
#include <QDesktopServices>
#include <QDir>
#include <QUrl>
#include "../moteur/Combinaison.h"
#include "barregraphique.h"

class WidgetGraphique : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetGraphique(QFont & fontTitre ,QWidget *parent = 0);
    void updateGraphique(std::list<Combinaison> *combinaison);
private:
    QVBoxLayout * m_layoutBarres;
    QLabel * m_labelNoResults;
    QVector <BarreGraphique *> m_vectorBarres;
signals:

public slots:
    void afficheAide();
};

#endif // WIGETGRAPHIQUE_H
