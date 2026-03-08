#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pQtimer = new QTimer(this);
    connect(pQtimer, &QTimer::timeout, this, &MainWindow::updateTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateProgressbar()
{
    ui->progressBar1->setValue(player1Time);
    ui->progressBar2->setValue(player2Time);


}

void MainWindow::setGameInfoText(QString ohje, short koko)
{
    ui->gameState->setText(ohje);
    QFont font = ui->gameState->font();
    font.setPointSize(koko);
    ui->gameState->setFont(font);

    if(player1Time == 0) {
        ui->gameState->setText("player 2 won!");
    }
    else if (player2Time == 0) {
        ui->gameState->setText("player 1 won!");
    }

}

void MainWindow::on_startNappi_clicked()
{
    if (gameTime == 0) return;
    gameRunning = true;
    currentPlayer = 1;
    pQtimer->start(1000);
    ui->gameState->setText("Game ongoing");
}


void MainWindow::on_stopNappi_clicked()
{
    pQtimer->stop();
    gameRunning = false;
    ui->gameState->setText("Game stopped. Select time to start again.");
}


void MainWindow::on_pelimuoto_sek_clicked()
{
    gameTime = 120;
    player1Time = gameTime;
    player2Time = gameTime;

    ui->progressBar1->setMaximum(gameTime);
    ui->progressBar2->setMaximum(gameTime);

    ui->progressBar1->setValue(gameTime);
    ui->progressBar2->setValue(gameTime);
    ui->gameState->setText("Time selected. Press START.");
    gameRunning = false;
    currentPlayer = 1;
}


void MainWindow::on_pelimuoto_min_clicked()
{
    gameTime = 300;
    player1Time = gameTime;
    player2Time = gameTime;

    ui->progressBar1->setMaximum(gameTime);
    ui->progressBar2->setMaximum(gameTime);

    ui->progressBar1->setValue(gameTime);
    ui->progressBar2->setValue(gameTime);
    ui->gameState->setText("Time selected. Press START.");
    gameRunning = false;
    currentPlayer = 1;
}


void MainWindow::on_switch1_nappi_clicked()
{
    if (!gameRunning) return;
    if (currentPlayer == 1) {
        currentPlayer = 2;
    }
}


void MainWindow::on_switch2_nappi_clicked()
{
    if (!gameRunning) return;
    if (currentPlayer == 2) {
        currentPlayer = 1;
    }
}

void MainWindow::updateTime()
{
    if (!gameRunning) return;
    if (currentPlayer == 1)
    {
        player1Time--;
        ui->progressBar1->setValue(player1Time);
        if (player1Time <= 0)
        {
            pQtimer->stop();
            gameRunning = false;
            ui->gameState->setText("Player 2 wins!");
        }
    }
    else if (currentPlayer == 2)
    {
        player2Time--;
        ui->progressBar2->setValue(player2Time);
        if (player2Time <= 0)
        {
            pQtimer->stop();
            gameRunning = false;
            ui->gameState->setText("Player 1 wins!");
        }
    }
}
