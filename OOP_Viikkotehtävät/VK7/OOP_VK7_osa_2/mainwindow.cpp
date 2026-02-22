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

void MainWindow::on_plus_clicked()
{
    if (tila == 2)  {
    QString num1Str = ui->num1->text();
    int num1 = num1Str.toInt();

    QString num2Str = ui->num2->text();
    int num2 = num2Str.toInt();

    int tulos = num1+num2;
    qDebug() << "Plus: " << tulos << "=" << num1 << "+" << num2;

    QString tulosStr = QString::number(tulos);
    ui->tulos->setText(tulosStr);

    tila = 1;
    qDebug() << "Laskun jalkeen taas tila 1";
    }
    else    {
        qDebug() << "Virhe! Molempia numeroita ei syötetty!";
    }
}


void MainWindow::on_miinus_clicked()
{
    if (tila == 2) {
    QString num1Str = ui->num1->text();
    int num1 = num1Str.toInt();

    QString num2Str = ui->num2->text();
    int num2 = num2Str.toInt();

    int tulos = num1-num2;
    qDebug() << "Miinus: " << tulos << "=" << num1 << "-" << num2;

    QString tulosStr = QString::number(tulos);
    ui->tulos->setText(tulosStr);

    tila = 1;
    qDebug() << "Laskun jalkeen taas tila 1";
    }
    else    {
            qDebug() << "Virhe! Molempia numeroita ei syötetty!";
        }
}


void MainWindow::on_kerto_clicked()
{
    if (tila == 2) {
    QString num1Str = ui->num1->text();
    int num1 = num1Str.toInt();

    QString num2Str = ui->num2->text();
    int num2 = num2Str.toInt();

    int tulos = num1*num2;
    qDebug() << "Kerto: " << tulos << "=" << num1 << "*" << num2;

    QString tulosStr = QString::number(tulos);
    ui->tulos->setText(tulosStr);

    tila = 1;
    qDebug() << "Laskun jalkeen taas tila 1";
    }
    else    {
        qDebug() << "Virhe! Molempia numeroita ei syötetty!";
    }
}


void MainWindow::on_jako_clicked()
{
    if (tila == 2) {
    QString num1Str = ui->num1->text();
    int num1 = num1Str.toInt();

    QString num2Str = ui->num2->text();
    int num2 = num2Str.toInt();

    int tulos = num1/num2;
    qDebug() << "Jako: " << tulos << "=" << num1 << "/" << num2;

    QString tulosStr = QString::number(tulos);
    ui->tulos->setText(tulosStr);

    tila = 1;
    qDebug() << "Laskun jalkeen taas tila 1";
    }
    else    {
        qDebug() << "Virhe! Molempia numeroita ei syötetty!";
    }
}


void MainWindow::on_clearNappi_clicked()
{
    qDebug() << "Clear! Tila on taas 1";
    tila = 1;
    ui->num1->clear();
    ui->num2->clear();
    ui->tulos->clear();

}


void MainWindow::on_enterNappi_clicked()
{
    /* Tila 1. syötä numero 1
     * Tila 2. syötä numero 2
     * Tila 3. laske tulos
     * palaa tila 1
     */
    tila++;
    qDebug() << "Valittu num" << tila;
    if (tila == 3) {
        tila = 1;
    }
}



void MainWindow::numberClickHandler(int n)
{
    qDebug() << "Valittu numero=" << n;
    QString str = QString::number(n);
    if (tila == 1)  {
        qDebug() << "Elementti num1";
          // laita n -> num1
        ui->num1->setText(str);
    }
    else if (tila == 2) {
        qDebug() << "Elementti num2";
        // laita n -> num2
        ui->num2->setText(str);
    }
}


void MainWindow::on_nro1_clicked()
{
    QString str = ui->nro1->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_nro2_clicked()
{
    QString str = ui->nro2->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_nro3_clicked()
{
    QString str = ui->nro3->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_nro4_clicked()
{
    QString str = ui->nro4->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_nro5_clicked()
{
    QString str = ui->nro5->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_nro6_clicked()
{
    QString str = ui->nro6->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_nro7_clicked()
{
    QString str = ui->nro7->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_nro8_clicked()
{
    QString str = ui->nro8->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_nro9_clicked()
{
    QString str = ui->nro9->text();
    int n = str.toInt();
    numberClickHandler(n);
}


void MainWindow::on_nro0_clicked()
{
    QString str = ui->nro0->text();
    int n = str.toInt();
    numberClickHandler(n);
}

