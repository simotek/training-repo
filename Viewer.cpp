#include "Viewer.hpp"

#include <QHBoxLayout>
#include <QLabel>

Viewer::Viewer(QWidget *parent)
  : QWidget(parent)
{
    QWidget * pBob = new QWidget();
    QHBoxLayout * pBobLayout = new QHBoxLayout(pBob);

    pBobLayout->addWidget(new QLabel("THIS"));
    pBobLayout->addWidget(new QLabel("is"));
    pBobLayout->addWidget(new QLabel("Sparta!"));

    QHBoxLayout * pLayout = new QHBoxLayout(this);
    pLayout->addWidget(pBob);


}

