#ifndef SAISIE_H
#define SAISIE_H

#include <QWidget>
#include <QWidget>
#include <QLayout>
#include <QSpinBox>
#include <QComboBox>
#include "convertunit.h"

/* Une saisie est un widget qui contient :
 * - un champ DoubleSpinBox concernant la longueur
 * - un champ Combobox concernant l'unité
 * - un champ SpinBox concernant la quantité
 */

class Saisie : public QWidget
{
    Q_OBJECT
public:
    explicit Saisie(QWidget *parent = 0);
    ~Saisie();
    double longueur() const;
    int unite() const;
    double quantite() const;
private:
    QDoubleSpinBox * m_longueur;
    QComboBox * m_unite;
    QSpinBox * m_quantite;
signals:

public slots:
};

#endif // SAISIE_H
