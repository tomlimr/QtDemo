#ifndef IMAGECLIENT_H
#define IMAGECLIENT_H

#include <QObject>
#include <iostream>
#include <fstream>
#include <QTcpSocket>

class ImageClient : public QObject
{
    Q_OBJECT
public:
    explicit ImageClient(QObject *parent = nullptr);

signals:

public slots:
    void onDataReceived();

private:
    QTcpSocket* socket;
};

#endif // IMAGECLIENT_H
