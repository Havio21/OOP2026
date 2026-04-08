#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pLukija = new Lukija(this);
    pLukija->readInfo();
    connect(pLukija,&Lukija::sendSerialData, // kun saa signaalin lukijan sendSerialDatasta se käsitellään handleCardNumberissa
            this,&MainWindow::handleCardNumber);
    qDebug() << "Aukesiko portti " << pLukija->open(); // debug joka kertoo onnistuiko portin avaus
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleCardNumber(QByteArray A)
{
    qDebug() << "MainWindow handleCardNumber"; //debug joka kertoo päästäänkö tähä funktioon
    qDebug() << "CardNumber = " << A; // debug tulostaa kortin numeron joka tuli sendSerialDatasta
    ui->lineEdit->setText(A); // asettaa kortin numeron käyttöliittymään eli lineEdittiin
}
