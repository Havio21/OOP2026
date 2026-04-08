#ifndef LUKIJA_H
#define LUKIJA_H

#include <QObject>
#include <QtSerialPort>
#include <QByteArray>

class Lukija : public QObject
{
    Q_OBJECT
public:
    Lukija(QObject * parent = nullptr);
    ~Lukija();
    void readInfo();
    bool open();

signals:
    void sendSerialData(QByteArray);

private slots:
    void handleInterrupt();

private:
    QSerialPort * port;

};

#endif // LUKIJA_H
