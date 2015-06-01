#ifndef WIDGETRESULTATS_H
#define WIDGETRESULTATS_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>

class WidgetResultats : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetResultats(QWidget *parent = 0);
    void updateResultats(QString & text);
private:
    QLabel * m_labelResultat;
signals:

public slots:
};

#endif // WIDGETRESULTATS_H
