/*
 * \file barregraphique.h
 * \brief Header de la classe BarreGraphique
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 */

#ifndef BARREGRAPHIQUE_H
#define BARREGRAPHIQUE_H

#include <QWidget>
#include <QPainter>
#include <list>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include "../convertunit.h"
#include "../moteur/Paire.h"
#include "../moteur/Combinaison.h"

// \class BarreGraphique barregraphique.h
// \brief Classe chargée de la création d'un graphique représentant un tronçon
class BarreGraphique : public QWidget
{
    Q_OBJECT
public:
    // \brief Constructeur de la classe BarreGraphique
    // \param combinaison Le pointeur vers la combinaison des tronçons
    explicit BarreGraphique(Combinaison * combinaison ,QWidget *parent = 0);

private:
    Combinaison * m_combinaison;
    std::list<Paire> m_liste;
    double m_barre;
signals:

public slots:

protected:
    // \brief Slot, spécial Qt, qui est chargé de dessiner le graphique
    void paintEvent(QPaintEvent * e);
};

#endif // BARREGRAPHIQUE_H
