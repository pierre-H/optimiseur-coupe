#include "barregraphique.h"

BarreGraphique::BarreGraphique(Combinaison & combinaison, QWidget *parent) : QWidget(parent)
{
    m_combinaison = &combinaison ;
}

void BarreGraphique::paintEvent(QPaintEvent *e)
{

}

