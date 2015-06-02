#ifndef WIDGETGRAPHIQUE_H
#define WIDGETGRAPHIQUE_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include "barregraphique.h"

class WidgetGraphique : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetGraphique(QFont & fontTitre,QWidget *parent = 0);

signals:

public slots:
};

#endif // WIDGETGRAPHIQUE_H
