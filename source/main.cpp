#include <iostream>
#include "networkmanager/networkmanager.hpp"
#include <QCoreApplication>
#include <QtCore/QString>
#include <QTimer>
#include "QDebug"


int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    std::cout << "hello all i'm the Actual code Version 1.1" << std::endl;
    networkmanager mNetworkManger;
    QTimer *timer = new QTimer();
    // Connect timeout signal to a lambda (no need for a class/slot)
    QObject::connect(timer, &QTimer::timeout, [&]() {
        std::cout << "Timer triggered!" << std::endl;
    });
    // timer->start(1000);
    return app.exec();
}