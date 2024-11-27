#ifndef IMAGESERVER_H
#define IMAGESERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include <fstream>
#include <cstring>

class ImageServer : public QObject
{
    Q_OBJECT
public:
    explicit ImageServer(QObject *parent = nullptr);

signals:

public slots:
    void onNewConnection();

private:
    QTcpServer* server;
};

#endif // IMAGESERVER_H
