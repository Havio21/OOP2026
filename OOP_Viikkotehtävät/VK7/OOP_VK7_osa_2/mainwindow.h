#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_plus_clicked();
    void on_miinus_clicked();
    void on_kerto_clicked();
    void on_jako_clicked();
    void on_clearNappi_clicked();
    void on_enterNappi_clicked();


    void on_nro1_clicked();

    void on_nro2_clicked();

    void on_nro3_clicked();

    void on_nro4_clicked();

    void on_nro5_clicked();

    void on_nro6_clicked();

    void on_nro7_clicked();

    void on_nro8_clicked();

    void on_nro9_clicked();

    void on_nro0_clicked();

private:
    void numberClickHandler(int n);
    Ui::MainWindow *ui;
    int tila = 1;
};
#endif // MAINWINDOW_H
