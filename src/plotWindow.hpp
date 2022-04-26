#pragma once

#include <QWidget>
#include <QGraphicsView>

class plotWindow : public QWidget
{
    Q_OBJECT

public:
    explicit plotWindow(QWidget *parent = nullptr);

private:
    QGraphicsView *m_view;
    QGraphicsScene *m_scene;

};