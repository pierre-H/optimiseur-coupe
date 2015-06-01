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
#include "groupesaisie.h"
#include "convertunit.h"

/* Fenêtre principale du programme
 * Elle inclut le formulaire et les résultats (pas encore codée)
 */

class FormulaireSaisie : public QWidget
{
    Q_OBJECT
public:
    explicit FormulaireSaisie(QWidget *parent = 0);
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
};

#endif // FORMULAIRESAISIE_H
