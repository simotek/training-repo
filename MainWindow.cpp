#include "MainWindow.hpp"
#include "ui_MainWindow.h"

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

    connect(m_pUi->actionQuit, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(quit()));
    connect(m_pUi->actionAbout_Qt, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(aboutQt()));
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
}

QString *MainWindow::getVersion()
{
    return &m_version;
}

