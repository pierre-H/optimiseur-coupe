#include "barregraphique.h"

BarreGraphique::BarreGraphique(Combinaison * combinaison, QWidget *parent) :QWidget(parent), m_combinaison(combinaison)
{
    setMinimumHeight(65);
    setMinimumWidth(500);
    m_liste = m_combinaison->getPaires();
    m_barre = m_combinaison->getBarre();
}


// Dessine la découpe d'une barre
void BarreGraphique::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    // Affiche "Sur une barre de ...
    painter.drawText(QPoint(0,10), tr("Sur une barre de ") + ConvertUnit::toStrSimplifie(m_barre) + " :");

    // Calcul le nb de pixels dispos
    int longueur = 0, i;
    std::list<Paire>::iterator it;
    for (it = m_liste.begin(); it != m_liste.end(); it++)
        longueur++;
    longueur = 500 - (longueur*5);

    // QPoints
    QPoint a(0,20), b;
    b.setY(55);

    QRect rec;

    // Affichage des rectangles
    for (it = m_liste.begin(); it != m_liste.end(); it++){
        i = (longueur * (int) it->getLongueur()) / m_barre;
        b.setX(a.x() + i);
        rec.setTopLeft(a);
        rec.setBottomRight(b);
        painter.drawRect(rec);
        painter.drawText(rec, Qt::AlignCenter, it->toStr());
        a.setX(b.x() + 5);
    }
}
