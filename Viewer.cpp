#include "Viewer.hpp"

#include <QKeyEvent>

#include <QHBoxLayout>
#include <QLabel>

#include <QBrush>
#include <QPainter>
#include <QPixmap>

Viewer::Viewer(QWidget *parent): QWidget(parent),
    m_pLabel1(new QLabel("Test")),
    m_pLabel2(new QLabel("123")),
    m_pLabel3(new QLabel("ABC")),
    m_blue(false)
{
    QWidget * pBob = new QWidget();
    QHBoxLayout * pBobLayout = new QHBoxLayout(pBob);

    pBobLayout->addWidget(m_pLabel1);
    pBobLayout->addWidget(new QLabel(":"));
    pBobLayout->addWidget(m_pLabel2);
    pBobLayout->addWidget(new QLabel(":"));
    pBobLayout->addWidget(m_pLabel3);
    pBobLayout->addWidget(new QLabel(";"),1);

    m_pLabel1->setAlignment(Qt::AlignLeft);
    m_pLabel2->setAlignment(Qt::AlignCenter);
    m_pLabel3->setAlignment(Qt::AlignRight);

    QHBoxLayout * pLayout = new QHBoxLayout(this);
    pLayout->addWidget(pBob);

    setFocusPolicy(Qt::StrongFocus);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

Viewer::~Viewer() {
    delete m_pLabel1;
    delete m_pLabel2;
    delete m_pLabel3;
}

void Viewer::setImage(QString path)
{
    m_imagePath = path;
}

void Viewer::setLabelOneNumber(int number)
{
    m_pLabel1->setText(QString::number(number,10));
}

void Viewer::setLabelTwoNumber(int number)
{
    QString numberStr = QString::number(number,2);

    while (numberStr.size() < 8)
    {
        numberStr = QString("0")+numberStr;
    }

    m_pLabel2->setText(numberStr);
}

void Viewer::setLabelThreeNumber(int number)
{
    QString numberStr = QString::number(number,16);

    while (numberStr.size() < 2)
    {
        numberStr = QString("0")+numberStr;
    }
    m_pLabel3->setText(QString("0x")+numberStr);
}

void Viewer::setLabelTwo(QString text)
{
    m_pLabel2->setText(text);
}

void Viewer::setLabelThree(QString text)
{
    m_pLabel3->setText(text);
}

void Viewer::keyPressEvent(QKeyEvent *pEvent)
{
    switch (pEvent->key())
    {
        case Qt::Key_B:
            m_blue = true;
            update();
            break;
        case Qt::Key_A:
            m_pLabel1->setText("Apple");
        case Qt::Key_R:
            update();
            m_blue = false;
            break;
    }
}

void Viewer::paintEvent(QPaintEvent * pEvent)
{
    int border = 5;
    QPainter painter(this);

    QPixmap pixmap = QPixmap(m_imagePath);

    float widthScale = pixmap.width()/width();
    float heightScale = pixmap.height()/height();

    if (m_imagePath != "") {
        if (heightScale > widthScale) {
            pixmap = pixmap.scaledToHeight(height()-11);
        } else {
            pixmap = pixmap.scaledToWidth(width()-11);
        }
    }

    painter.setPen(Qt::black);
    if (hasFocus()) {
        if (m_blue) {
            painter.setBrush(QBrush(QColor(Qt::blue)));
        } else {
            painter.setBrush(QBrush(QColor(Qt::red)));
        }

    } else {
        painter.setBrush(QBrush(QColor(Qt::white)));
    }

    painter.drawRect(0,0, width()-1, height()-1);
    if (m_imagePath != "") {
        painter.drawPixmap(border/2+width()/2-pixmap.width()/2-1, border/2+height()/2-pixmap.height()/2-1, pixmap);
    }

    QWidget::paintEvent(pEvent);
}
