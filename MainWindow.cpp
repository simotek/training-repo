#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);

    m_version = QString("0.0b1");
    qDebug("this 0x%X", this);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

QString *MainWindow::getVersion()
{
    return &m_version;
}

