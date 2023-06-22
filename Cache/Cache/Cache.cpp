#include "Cache.h"
#include <iostream>


Cache::Cache(QObject *parent)
    : QObject{parent}
{

    m_cacheAdaptor = new CacheAdaptor(this);
    QDBusConnection connection = QDBusConnection::sessionBus();

    if(!connection.registerService("com.scythestudio.cache")) {
        qDebug() << "service registration error " << QDBusConnection::sessionBus().lastError().message();
    }

    if(!connection.registerObject("/Cache", this)) {
       qDebug() << "object registration error " << QDBusConnection::sessionBus().lastError().message();
    }

    qDebug() << "[Cache adaptor] Created";
}

QString Cache::ping(const QString &message)
{
    qDebug() << "[Cache adaptor] ping received: " << message;
    return "[Cache adaptor] Pong!";
}

QString Cache::status()
{
    qDebug() << "[Cache adaptor] status received";
    QString ret{};

    switch(m_status) {
    case 0:
       ret = "RUNNING";
       m_status = 1;
       break;
    case 1:
       ret = "EXITING";
       m_status = 2;
       break;
    case 2:
       ret = "INIT";
       m_status = 0;
       break;
    }

    return ret;
}

