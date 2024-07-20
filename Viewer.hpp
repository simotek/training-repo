#ifndef VIEWER_HPP
#define VIEWER_HPP

#include <QHBoxLayout>
#include <QWidget>

class QLabel;

class Viewer : public QWidget
{
    Q_OBJECT

public:
    Viewer(QWidget *parent = nullptr);
    ~Viewer();

    void setLabelTwo(QString text);

public slots:
    void setLabelOneNumber(int number);
    void setLabelTwoNumber(int number);
    void setLabelThreeNumber(int number);

    void setLabelThree(QString text);

protected:
    void keyPressEvent(QKeyEvent * pEvent);
    void paintEvent(QPaintEvent * pEvent);

private:
    QLabel * m_pLabel1;
    QLabel * m_pLabel2;
    QLabel * m_pLabel3;

    bool m_blue;
};

#endif // VIEWER_HPP
