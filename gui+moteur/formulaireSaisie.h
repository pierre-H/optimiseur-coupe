/* formulaireSaisie.h
 * Optimiseur de Coupe
 * 2015 - Pierre-Emmanuel PIRNAY 11296315
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

// Onglet formulaire de saisie

class FormulaireSaisie : public QWidget
{
    Q_OBJECT
public:
    explicit FormulaireSaisie(QFont & fontTitre, QWidget *parent = 0);
    ~FormulaireSaisie();
    QPushButton * buttonAppliquer() const;
    GroupeSaisie * groupeSaisieBarres() const;
    GroupeSaisie * groupeSaisieTron() const;
    double epaisseurLame() const;
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
    void afficheAide();
};

#endif // FORMULAIRESAISIE_H
