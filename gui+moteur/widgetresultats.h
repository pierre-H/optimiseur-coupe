#ifndef WIDGETRESULTATS_H
#define WIDGETRESULTATS_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QScrollArea>
#include <QPalette>

class WidgetResultats : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetResultats(QFont & fontTitre, QWidget *parent = 0);
    void updateResultats(QString & text);
private:
    QTextEdit * m_labelResultat;
signals:

public slots:
};

#endif // WIDGETRESULTATS_H
