/*
 * \file groupesaisie.h
 * \brief Header de la classe GroupeSaisie
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 */

#ifndef GROUPESAISIE_H
#define GROUPESAISIE_H

#include <QWidget>
#include <QLabel>
#include <QVector>
#include <QScrollArea>
#include <QScrollBar>
#include <QPushButton>
#include <QFont>
#include <QLayout>
#include <QString>
#include "saisie.h"

/*
 * \class GroupeSaisie groupesaisie.h
 * \brief Cette classe gère les saisies.
 * Cette classe gère l'affichage des saisies ainsi que les boutons
 * d'ajout et de suppression de saisie.
 */

class GroupeSaisie : public QWidget
{
    Q_OBJECT
public:

    // \brief Constructeur de la classe GroupeSaisie
    // \param titre Titre du Groupe de Saisie (Barres av. la déc. ou Tronçons désirés)
    // \param fontTitre Police du titre
    explicit GroupeSaisie(QString titre, QFont & fontTitre, QWidget *parent = 0);

    // \Déconstructeur de la classe GroupeSaisie
    ~GroupeSaisie();

    // \brief Méthode d'accès au vecteur des saisies
    // \return QVector des saisies
    QVector<Saisie *> saisies() const;
private:
    QVBoxLayout * m_layoutSaisies;
    QVector<Saisie *> m_vectorSaisies;
    QLabel * m_labelNbSaisies;
    QPushButton * m_buttonSupprSaisies;
    QString m_stringNbSaisies;
    QScrollArea * m_scrollSaisies;
signals:

public slots:
    // \brief Slot qui ajoute une saisie
    void ajoutSaisie();

    // \brief Slot qui supprime la dernière saisie
    void supprSaisie();
};

#endif // GROUPESAISIE_H
