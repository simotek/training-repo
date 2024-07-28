#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_pUi(new Ui::MainWindow)
{
    m_pUi->setupUi(this);

    m_version = QString("0.0b1");
    qDebug("this 0x%X", this);

    m_pUi->viewer->setFocus();

    connect(m_pUi->okButton, SIGNAL(clicked()), this, SLOT(setLabelToBob()));
    connect(m_pUi->okButton, SIGNAL(clicked()), this, SLOT(onOkClicked()));

    connect(this, SIGNAL(sendingText(QString)), m_pUi->viewer, SLOT(setLabelThree(QString)));
    connect(m_pUi->horizontalSlider, SIGNAL(valueChanged(int)), m_pUi->viewer, SLOT(setLabelOneNumber(int)));
    connect(m_pUi->horizontalSlider, SIGNAL(valueChanged(int)), m_pUi->viewer, SLOT(setLabelTwoNumber(int)));;
    connect(m_pUi->horizontalSlider, SIGNAL(valueChanged(int)), m_pUi->viewer, SLOT(setLabelThreeNumber(int)));;

<<<<<<< HEAD
=======
    connect(m_pUi->actionImport, SIGNAL(triggered(bool)), this, SLOT(onImport()));
    connect(m_pUi->actionQuit, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(quit()));
    connect(m_pUi->actionAbout_Qt, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(aboutQt()));
>>>>>>> 1c5df8f8a99187cf2ca5bc6b64de1aa04f667eeb

}

MainWindow::~MainWindow()
{
    delete m_pUi;
}

void MainWindow::setLabelToBob()
{
    m_pUi->viewer->setLabelTwo("Bob");
}

void MainWindow::onOkClicked()
{
    emit sendingText(m_pUi->person->text());
<<<<<<< HEAD
=======
}

void MainWindow::onImport()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/simon", tr("Image Files (*.png *.jpg *.bmp)"));
    m_pUi->viewer->setImage(fileName);
>>>>>>> 1c5df8f8a99187cf2ca5bc6b64de1aa04f667eeb
}

QString *MainWindow::getVersion()
{
    return &m_version;
}
