#include "Hardware.h"

Hardware::Hardware(QObject *parent)
    : QObject{parent}
{
    m_hardwareAdaptor = new HardwareAdaptor(this);
    QDBusConnection connection = QDBusConnection::sessionBus();

    if(!connection.registerService("com.scythestudio.hardware")) {
        qDebug() << "service registration error " << QDBusConnection::sessionBus().lastError().message();
    }

    if(!connection.registerObject("/Hardware", this)) {
        qDebug() << "object registration error " << QDBusConnection::sessionBus().lastError().message();
    }

    qDebug() << "[Hardware adaptor] Created";
}

QString Hardware::ping(const QString &message)
{
    qDebug() << "[Hardware adaptor] ping received: " << message;
    return "[Hardware adaptor] Pong!";
}

QString Hardware::status()
{
    qDebug() << "[Hardware adaptor] status received";
    QString ret{};

    switch(m_status) {
    case 0:
        ret = "FULL";
        m_status = 1;
        break;
    case 1:
        ret = "MEDIUM";
        m_status = 2;
        break;
    case 2:
        ret = "EMPTY";
        m_status = 0;
        break;
    }

    return ret;
}

int Hardware::ramUsage()
{
    qDebug() << "[Hardware adaptor] ramUsage received";

    srand((unsigned) time(NULL));

    return rand();
}
