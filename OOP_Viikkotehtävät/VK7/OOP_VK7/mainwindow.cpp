#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lisaaNappi_clicked()
{
    // 1. lue numero elementistä
    QString str = ui->numeroNaytto->text();
    int num = str.toInt();
    qDebug() << "Numero=" << num;
    // 2. kasvata numeroa yhellä
    num++;
    // 3. aseta numero takaisin elementtiin
    qDebug() << "Kasvatettu numero=" << num;
    QString uusStr = QString::number(num);
    ui->numeroNaytto->setText(uusStr);
}


void MainWindow::on_resetNappi_clicked()
{
    int num = 0;
    // 1. aseta numero takaisin elementtiin
    ui->numeroNaytto->setText(QString::number(num));
}

