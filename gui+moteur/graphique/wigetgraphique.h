/*
 * \file widgetgraphique.h
 * \brief Header de la classe WidgetGraphique
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 */

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

// \class WidgetGraphique widgetgraphique.h
// \brief Classe chargée d'afficher le résultat sour forme graphique
class WidgetGraphique : public QWidget
{
    Q_OBJECT
public:
    // \brief Constructeur de la classe WidgetGraphique
    // \param fontTitre Police du titre
    explicit WidgetGraphique(QFont & fontTitre ,QWidget *parent = 0);

    // \brief Créé ou met à jour le graphique
    // \param combinaison La combinaison des tronçons désirés
    void updateGraphique(std::list<Combinaison> *combinaison);
private:
    QVBoxLayout * m_layoutBarres;
    QLabel * m_labelNoResults;
    QVector <BarreGraphique *> m_vectorBarres;
signals:

public slots:
    // \brief Slot lance l'affichage de l'aire
    void afficheAide();
};

#endif // WIGETGRAPHIQUE_H
