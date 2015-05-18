#ifndef SAISIE_H
#define SAISIE_H

#include <QWidget>
#include <QWidget>
#include <QLayout>
#include <QSpinBox>
#include <QComboBox>
#include <QLabel>
#include "convertunit.h"

/* Une saisie est un widget qui contient :
 * - un champ DoubleSpinBox concernant la longueur
 * - un champ Combobox concernant l'unité
 * - un champ SpinBox concernant la quantité
 *
 *
 * On accède au valeurs des champs via les méthodes longueur(), unite() et quantite()
 */

class Saisie : public QWidget
{
    Q_OBJECT
public:
    explicit Saisie(int numero, QWidget *parent = 0);
    ~Saisie();
    double longueur() const;
    int unite() const;
    int quantite() const;
private:
    QDoubleSpinBox * m_longueur;
    QComboBox * m_unite;
    QSpinBox * m_quantite;
signals:

public slots:
};

#endif // SAISIE_H
