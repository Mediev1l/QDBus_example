#include "Ui.h"

UI::UI(QObject *parent)
    : QObject{parent}
{
    m_cacheInterface = new com::scythestudio::cache(com::scythestudio::cache::staticInterfaceName(),  "/Cache", QDBusConnection::sessionBus(), this);
    m_hardwareInterface = new com::scythestudio::hardware(com::scythestudio::hardware::staticInterfaceName(), "/Hardware", QDBusConnection::sessionBus(), this);

    startTimer(1000);
}


void UI::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    if (m_cacheInterface->isValid()) {
       setCacheConnected(true);
    } else {
       setCacheConnected(false);
    }

    if (m_hardwareInterface->isValid()){
       setHardwareConnected(true);
    } else {
       setHardwareConnected(false);
    }

    if(m_cacheTimer > 0 && !m_cachePingMessage.isEmpty()) {
       m_cacheTimer--;
    } else if (!m_cachePingMessage.isEmpty()) {
       setCachePingMessage("");
    }

    if(m_hardwareTimer > 0 && !m_hardwarePingMessage.isEmpty()) {
       m_hardwareTimer--;
    } else if (!m_hardwarePingMessage.isEmpty()) {
       setHardwarePingMessage("");
    }
}

void UI::cachePingClicked()
{
    qDebug() << "[UI][Cache proxy] ping called";

    if (!m_cacheInterface->isValid()) {
       qDebug() << "Interface not connected";
       return;
    }

    auto ret = m_cacheInterface->ping("Ping!");
    m_cacheTimer = 2;
    setCachePingMessage(ret);
}

void UI::cacheStatusClicked()
{
    qDebug() << "[UI][Cache proxy] status called";

    if (!m_cacheInterface->isValid()) {
       qDebug() << "Interface not connected";
        return;
    }

    auto ret = m_cacheInterface->status();
    setCacheStatus(ret);
}

void UI::hardwarePingClicked()
{
    qDebug() << "[UI][Hardware proxy] ping called";

    if (!m_hardwareInterface->isValid()) {
        qDebug() << "Interface not connected";
        return;
    }

    auto ret = m_hardwareInterface->ping("Ping!");
    m_hardwareTimer = 2;
    setHardwarePingMessage(ret);
}

void UI::hardwareStatusClicked()
{
    qDebug() << "[UI][Hardware proxy] status called";

    if (!m_hardwareInterface->isValid()) {
        qDebug() << "Interface not connected";
        return;
    }

    auto ret = m_hardwareInterface->status();
    setHardwareStatus(ret);
}

void UI::ramUsageClicked()
{
    qDebug() << "[UI][Hardware proxy] ramUsage called";

    if (!m_hardwareInterface->isValid()) {
        qDebug() << "Interface not connected";
        return;
    }

    auto ret = m_hardwareInterface->ramUsage();
    setRamUsage(ret);
}

bool UI::cacheConnected() const
{
    return m_cacheConnected;
}

void UI::setCacheConnected(bool newCacheConnected)
{
    if (m_cacheConnected == newCacheConnected) {
        return;
    }
    m_cacheConnected = newCacheConnected;
    emit cacheConnectedChanged();
}

bool UI::hardwareConnected() const
{
    return m_hardwareConnected;
}

void UI::setHardwareConnected(bool newHardwareConnected)
{
    if (m_hardwareConnected == newHardwareConnected) {
        return;
    }
    m_hardwareConnected = newHardwareConnected;
    emit hardwareConnectedChanged();
}

QString UI::cachePingMessage() const
{
    return m_cachePingMessage;
}

void UI::setCachePingMessage(const QString &newCachePingMessage)
{
    if (m_cachePingMessage == newCachePingMessage) {
        return;
    }
    m_cachePingMessage = newCachePingMessage;
    emit cachePingMessageChanged();
}

QString UI::cacheStatus() const
{
    return m_cacheStatus;
}

void UI::setCacheStatus(const QString &newCacheStatus)
{
    if (m_cacheStatus == newCacheStatus) {
        return;
    }
    m_cacheStatus = newCacheStatus;
    emit cacheStatusChanged();
}

QString UI::hardwarePingMessage() const
{
    return m_hardwarePingMessage;
}

void UI::setHardwarePingMessage(const QString &newHardwarePingMessage)
{
    if (m_hardwarePingMessage == newHardwarePingMessage) {
        return;
    }
    m_hardwarePingMessage = newHardwarePingMessage;
    emit hardwarePingMessageChanged();
}

QString UI::hardwareStatus() const
{
    return m_hardwareStatus;
}

void UI::setHardwareStatus(const QString &newHardwareStatus)
{
    if (m_hardwareStatus == newHardwareStatus) {
        return;
    }
    m_hardwareStatus = newHardwareStatus;
    emit hardwareStatusChanged();
}

int UI::ramUsage() const
{
    return m_ramUsage;
}

void UI::setRamUsage(int newRamUsage)
{
    if (m_ramUsage == newRamUsage) {
        return;
    }
    m_ramUsage = newRamUsage;
    emit ramUsageChanged();
}
