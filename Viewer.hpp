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

    void imageChanged(QString path);
    void setLabelTwo(QString text);

signals:
    void pathChanged(QString path);

public slots:
    void setImage(QString path);
    void setPixmapData(QString data);
    void setLabelOneNumber(int number);
    void setLabelTwoNumber(int number);
    void setLabelThreeNumber(int number);

    void setLabelThree(QString text);

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void keyPressEvent(QKeyEvent * pEvent);
    void paintEvent(QPaintEvent * pEvent);

private:
    QString m_imagePath;
    QPixmap m_pixmap;

    QLabel * m_pLabel1;
    QLabel * m_pLabel2;
    QLabel * m_pLabel3;

    bool m_blue;
    bool m_loadFromFile;
};

#endif // VIEWER_HPP
