#include "plotWindow.hpp"

#include <QVBoxLayout>

plotWindow::plotWindow(QWidget *parent) : QWidget(parent)
{
    m_view = new QGraphicsView(this);
    m_scene = new QGraphicsScene(this);
    m_view->setScene(m_scene);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_view);
    setLayout(layout);

    m_scene->addRect(0,0, 40, 40, Qt::NoPen, QColor("#FFBB33"));
    m_scene->addLine(0, 0, 0, 100);
    m_scene->addLine(0, 0, 100, 0);
    //rect1->setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
}