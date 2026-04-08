#include "lukija.h"
#include <QDebug>
#include <QSerialPortInfo>

Lukija::Lukija(QObject *parent):QObject(parent)
{
    qDebug() << "Lukija luotu"; //lukijan debug joka kertoo millon lukija avataan
    port = new QSerialPort(this); //Luo uuden QSerialPort olion jonka se yhdistää lukijaan
}

Lukija::~Lukija()
{
    qDebug() << "Lukija tuhottu"; //lukijan debug joka kertoo millon lukija suljetaan
}

void Lukija::readInfo() //Tarkistaa missä porteissa on laitteita ja kertoo niitten tiedot
{
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &portInfo : serialPortInfos) {
        qDebug() << "\n"
                 << "Port:" << portInfo.portName() << "\n"
                 << "Location:" << portInfo.systemLocation() << "\n"
                 << "Description:" << portInfo.description() << "\n"
                 << "Manufacturer:" << portInfo.manufacturer() << "\n"
                 << "Serial number:" << portInfo.serialNumber() << "\n"
                 << "Vendor Identifier:"
                 << (portInfo.hasVendorIdentifier()
                         ? QByteArray::number(portInfo.vendorIdentifier(), 16)
                         : QByteArray()) << "\n"
                 << "Product Identifier:"
                 << (portInfo.hasProductIdentifier()
                         ? QByteArray::number(portInfo.productIdentifier(), 16)
                         : QByteArray());
    }
    qDebug() << "Infon lopussa";
}

bool Lukija::open()
{
    bool returnValue = false; //alustetaan muuttuja returnValue false jotta voi nähdä myöhemmin onnistuiko portin avaus
    const auto SerialPortInfos = QSerialPortInfo::availablePorts(); //kertoo mitä COM portteja on saatavilla
    for (const QSerialPortInfo &portInfo : SerialPortInfos) { //tarkistaa kaikki portit läpi
        if (portInfo.serialNumber() == "OL56E09005B8EC3") // tarkistaa portin sarjanumeron jonka avulla RFID laitetta voi käyttää kaikilla koneilla
        {
            port->setPortName(portInfo.portName()); //asettaan nimen serialPortille esim. COM4
            qDebug() << "portName set = " << port->portName(); // debug joka näyttää mikö portti valittiin
            returnValue = port->open(QIODeviceBase::ReadOnly); // avaa portin readOnlyssa

            connect(port,&QSerialPort::readyRead, // luo signaali slot yhteyden
                    this,&Lukija::handleInterrupt); // joka käsitellään handleInterruptissa
        }
    }

    return returnValue;
    // qDebug() << "open funktiossa";

    // //OL56E09005B8EC3
    // bool returnValue = false;
    // port->setPortName("COM4");
    // returnValue = port->open(QIODeviceBase::ReadOnly);
    // qDebug() << "returnValue = " << returnValue;
    // if(returnValue == true)
    // {
    //     connect(port,&QSerialPort::readyRead,
    //             this,&Lukija::handleInterrupt);
    // }
    // qDebug() << "open funktion lopussa";
    // return returnValue;
}

void Lukija::handleInterrupt()
{
    qDebug() << "Luettavaa sarjaportissa"; // kertoo että portissa on jotain luettavaa, esim kun lukija lukee kortin
    // static QByteArray buffer;   //Staattinen muuttuja "buffer" joka on QByteArray tyyppinen
    QByteArray luettu = port->readAll(); // RFID lukee kaiken kortissa olevan tiedon
    qDebug() <<(QString::fromUtf8(luettu)); //kertoo mitä RFID lukija luki
    QString clean = QString::fromUtf8(luettu) //puhistaa luetun kortin poistamalla merkit jotka ei ole hexa merkkejä
                        .remove(QRegularExpression("[^0-9A-Fa-f]"));
    emit sendSerialData(clean.toUtf8()); //lähettää puhistetun signaalin
    // buffer.append(luettu);
    // if(buffer.contains('\n'))
    // {
    //     qDebug() <<(QString::fromUtf8(buffer));
    //     emit sendSerialData(buffer);
    //     buffer = "";
    // }
}
