#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString *getVersion();

signals:
    void sendingText(QString);

public slots:
    void setLabelToBob();
    void onOkClicked();
<<<<<<< HEAD
=======
    void onImport();
>>>>>>> 1c5df8f8a99187cf2ca5bc6b64de1aa04f667eeb

protected:
private:
    Ui::MainWindow *m_pUi;

    QString m_version;
};
#endif // MAINWINDOW_HPP
