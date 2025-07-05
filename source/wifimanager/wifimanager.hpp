#ifndef WIFIMANAGER_HPP
#define WIFIMANAGER_HPP

#include "QObject"
#include "QString"
#include "QDebug"

class wifimanager : public QObject
{
    Q_OBJECT
private:
    /* data */
public:
    wifimanager(QObject * parent = nullptr);
    ~wifimanager();
};

#endif