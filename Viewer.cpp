#include "Viewer.hpp"

#include <QHBoxLayout>
#include <QLabel>

Viewer::Viewer(QWidget *parent)
  : QWidget(parent)
{
    QWidget * pBob = new QWidget();
    QHBoxLayout * pBobLayout = new QHBoxLayout(pBob);

    pBobLayout->addWidget(new QLabel("Test"));
    pBobLayout->addWidget(new QLabel("123"));
    pBobLayout->addWidget(new QLabel("ABC"));

    QHBoxLayout * pLayout = new QHBoxLayout(this);
    pLayout->addWidget(pBob);


}

