#ifndef BARREGRAPHIQUE_H
#define BARREGRAPHIQUE_H

#include <QWidget>
#include <QPainter>
#include "../moteur/Combinaison.h"

class BarreGraphique : public QWidget
{
    Q_OBJECT
public:
    explicit BarreGraphique(Combinaison & combinaison ,QWidget *parent = 0);

private:
    Combinaison * m_combinaison;

signals:

public slots:

protected:
    void paintEvent(QPaintEvent * e);
};

#endif // BARREGRAPHIQUE_H
