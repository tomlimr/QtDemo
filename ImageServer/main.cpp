#include <QCoreApplication>
#include "imageserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
     ImageServer server;
    return a.exec();
}
