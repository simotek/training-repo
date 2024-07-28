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

<<<<<<< HEAD
    void setLabelTwo(QString text);

public slots:
=======
    void imageChanged(QString path);
    void setLabelTwo(QString text);

public slots:
    void setImage(QString path);
>>>>>>> 1c5df8f8a99187cf2ca5bc6b64de1aa04f667eeb
    void setLabelOneNumber(int number);
    void setLabelTwoNumber(int number);
    void setLabelThreeNumber(int number);

    void setLabelThree(QString text);

protected:
<<<<<<< HEAD
=======
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
>>>>>>> 1c5df8f8a99187cf2ca5bc6b64de1aa04f667eeb
    void keyPressEvent(QKeyEvent * pEvent);
    void paintEvent(QPaintEvent * pEvent);

private:
<<<<<<< HEAD
=======
    QString m_imagePath;

>>>>>>> 1c5df8f8a99187cf2ca5bc6b64de1aa04f667eeb
    QLabel * m_pLabel1;
    QLabel * m_pLabel2;
    QLabel * m_pLabel3;

    bool m_blue;
};

#endif // VIEWER_HPP
