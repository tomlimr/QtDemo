#include "imageclient.h"
#include <QFile>

ImageClient::ImageClient(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
           socket->connectToHost("localhost", 12345);
           connect(socket, &QTcpSocket::readyRead, this, &ImageClient::onDataReceived);
}

void ImageClient::onDataReceived()
{
    QByteArray data = socket->readAll();
            QFile file("E://received_image.jpg");
            if (file.open(QIODevice::WriteOnly)) {
                file.write(data);  // 保存接收到的图片数据
                file.close();
            }
            socket->disconnectFromHost();
}
