#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QFont>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QFrame>
#include <QMessageBox>
#include <QVector>
#include "groupesaisie.h"
#include "saisie.h"
#include "convertunit.h"

class FenetrePrincipale : public QWidget
{
    Q_OBJECT
public:
    explicit FenetrePrincipale(QWidget *parent = 0);
    ~FenetrePrincipale();

private:
    GroupeSaisie * m_groupeSaisieBarres;
    GroupeSaisie * m_groupeSaisieTron;
    QDoubleSpinBox * m_epaisseurLame;
    QComboBox * m_uniteEpaisseurLame;
signals:

public slots:
    void traiterFormulaire();
};

#endif // FENETREPRINCIPALE_H
