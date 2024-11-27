#include "imageserver.h"
#include <QFile>
#include <QLoggingCategory>

ImageServer::ImageServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
           if (!server->listen(QHostAddress::Any, 12345)) {
               std::cerr << "Server failed to start!" << std::endl;
               return;
           }
           connect(server, &QTcpServer::newConnection, this, &ImageServer::onNewConnection);
}

void ImageServer::onNewConnection()
{
    QTcpSocket* socket = server->nextPendingConnection();
            QFile file("E://vpn.jpg");
            if (file.open(QIODevice::ReadOnly)) {
                QByteArray imageData = file.readAll();
                socket->write(imageData);  // 发送图片数据
                socket->waitForBytesWritten();
                socket->disconnectFromHost();
            }else {
                qInfo() << QString("open image failed ");
            }
            file.close();
}
