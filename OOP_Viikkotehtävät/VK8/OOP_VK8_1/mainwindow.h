#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // public slots tyyppiä : void timeOut();
private:
    short player1Time;
    short player2Time;
    short currentPlayer = 1;
    short gameTime;
    bool gameRunning = false;
    QTimer * pQtimer;
    Ui::MainWindow *ui;

    void updateProgressbar();
    void setGameInfoText(QString, short);
private slots:
    void on_startNappi_clicked();
    void on_stopNappi_clicked();
    void on_pelimuoto_sek_clicked();
    void on_pelimuoto_min_clicked();
    void on_switch1_nappi_clicked();
    void on_switch2_nappi_clicked();
    void updateTime();

};
#endif // MAINWINDOW_H
