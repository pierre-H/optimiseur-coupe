/*
 * \file formulaireSaisie.h
 * \brief Header de la classe FormulaireSaisie
 * \author Pierre-Emmanuel PIRNAY 11296315
 * \date 2015
 *
 */

#ifndef FORMULAIRESAISIE_H
#define FORMULAIRESAISIE_H

#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QFont>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QMessageBox>
#include <QVector>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include "saisies/groupesaisie.h"
#include "convertunit.h"

// \class FormulaireSaisie formulaireSaisie.h
// \brief Créé le formulaire de saisie

class FormulaireSaisie : public QWidget
{
    Q_OBJECT
public:
    // \brief Constructeur de la classe FormulaireSaisie
    // \param fontTitre la police du titre principal
    explicit FormulaireSaisie(QFont & fontTitre, QWidget *parent = 0);

    // \brief Déconstructeur de la classe FormulaireSaisie
    ~FormulaireSaisie();

    // \brief Méthode d'accès au bouton 'Appliquer'
    // \return pointeur vers le bouton 'Appliquer'
    QPushButton * buttonAppliquer() const;

    // \brief Méthode d'accès au groupe de saisies des barres avant la découpe
    // \return pointeur vers le groupe de saisies des barres avant la découpe
    GroupeSaisie * groupeSaisieBarres() const;

    // \brief Méthode d'accès au groupe de saisies des tronçons demandés
    // \return pointeur vers le groupe de saisies des tronçons demandés
    GroupeSaisie * groupeSaisieTron() const;

    // \brief Méthode d'accès à l'épaisseur de la lame
    // \return l'épaisseur de la lame
    double epaisseurLame() const;

    // \brief Méthode d'accès à l'unité de la l'épaisseur de la lame
    // \return un pointeur vers le QComboBox gérant l'unité de l'épaisseur de la lame
    QComboBox * uniteEpaisseurLame() const;

private:
    GroupeSaisie * m_groupeSaisieBarres;
    GroupeSaisie * m_groupeSaisieTron;
    QDoubleSpinBox * m_epaisseurLame;
    QComboBox * m_uniteEpaisseurLame;
    QPushButton * m_buttonAppliquer;
    QPushButton * m_buttonQuitter;
signals:

public slots:
    // \brief Slot lançant l'affichage de l'aire
    void afficheAide();
};

#endif // FORMULAIRESAISIE_H
