#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <QFileDialog>
#include <QFile>
#include <QTemporaryFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_pUi(new Ui::MainWindow)
    , m_useHex(true)
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

    connect(m_pUi->actionImport, SIGNAL(triggered(bool)), this, SLOT(onImport()));
    connect(m_pUi->actionQuit, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(quit()));
    connect(m_pUi->actionAbout_Qt, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(aboutQt()));

    connect(m_pUi->viewer, SIGNAL(pathChanged(QString)), this, SLOT(onImagePathChanged(QString)));
    connect(m_pUi->textEdit, SIGNAL(textChanged()),this, SLOT(onTextChanged()));

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

void MainWindow::onImagePathChanged(QString path)
{
    QFile image(path);
    QString data;

    if ( !image.exists()) {
        qDebug("Error: File doesn't exist: %s", path.toUtf8().data());
        return;
    }
    if (!image.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug("Error: Couldn't open file: %s", path.toUtf8().data());
        return;
    }

    if (0 != 0) {
        goto cleanup;
    }

    if (!m_useHex) {
        data = image.readAll();
    } else {
        while (!image.atEnd()) {
            QByteArray line = image.readLine();
            for (int i=0; i< line.size(); i++) {
                QString byte = QString::number((quint64)line.at(i),64);

                data.append(byte);
            }
        }
    }
    m_pUi->textEdit->setPlainText(data);

cleanup:
    image.close();
}

void MainWindow::onTextChanged()
{
    m_pUi->viewer->setPixmapData(m_pUi->textEdit->toPlainText());
    QTemporaryFile tmpFile;
    if (! tmpFile.open()) {
        qDebug("Couldn't open tmp file");
    } else {
        qDebug("TempFile: %s",tmpFile.fileName().toUtf8().data());
        tmpFile.write(m_pUi->textEdit->toPlainText().toUtf8().data(), m_pUi->textEdit->toPlainText().size());
        tmpFile.close();
    }

}

void MainWindow::onImport()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/simon", tr("Image Files (*.png *.jpg *.bmp)"));
    m_pUi->viewer->setImage(fileName);
}

QString *MainWindow::getVersion()
{
    return &m_version;
}

