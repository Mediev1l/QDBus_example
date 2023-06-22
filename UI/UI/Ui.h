#ifndef UI_H
#define UI_H

#include "qdebug.h"
#include <QObject>
#include "cache_proxy.h"
#include "hardware_proxy.h"

class UI : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool cacheConnected READ cacheConnected WRITE setCacheConnected NOTIFY cacheConnectedChanged)
    Q_PROPERTY(QString cachePingMessage READ cachePingMessage WRITE setCachePingMessage NOTIFY cachePingMessageChanged)
    Q_PROPERTY(QString cacheStatus READ cacheStatus WRITE setCacheStatus NOTIFY cacheStatusChanged)
    Q_PROPERTY(bool hardwareConnected READ hardwareConnected WRITE setHardwareConnected NOTIFY hardwareConnectedChanged)
    Q_PROPERTY(QString hardwarePingMessage READ hardwarePingMessage WRITE setHardwarePingMessage NOTIFY hardwarePingMessageChanged)
    Q_PROPERTY(QString hardwareStatus READ hardwareStatus WRITE setHardwareStatus NOTIFY hardwareStatusChanged)
    Q_PROPERTY(int ramUsage READ ramUsage WRITE setRamUsage NOTIFY ramUsageChanged)

public:
    explicit UI(QObject *parent = nullptr);

    bool cacheConnected() const;
    void setCacheConnected(bool newCacheConnected);

    bool hardwareConnected() const;
    void setHardwareConnected(bool newHardwareConnected);

    QString cachePingMessage() const;
    void setCachePingMessage(const QString &newCachePingMessage);

    QString cacheStatus() const;
    void setCacheStatus(const QString &newCacheStatus);

    QString hardwarePingMessage() const;
    void setHardwarePingMessage(const QString &newHardwarePingMessage);

    QString hardwareStatus() const;
    void setHardwareStatus(const QString &newHardwareStatus);

    int ramUsage() const;
    void setRamUsage(int newRamUsage);

public slots:
    void cachePingClicked();
    void cacheStatusClicked();
    void hardwarePingClicked();
    void hardwareStatusClicked();
    void ramUsageClicked();

signals:
    void cacheConnectedChanged();
    void cachePingMessageChanged();
    void cacheStatusChanged();

    void hardwareConnectedChanged();
    void hardwarePingMessageChanged();
    void hardwareStatusChanged();

    void ramUsageChanged();

protected:
    void timerEvent(QTimerEvent *event);

private:
    com::scythestudio::cache* m_cacheInterface;
    com::scythestudio::hardware* m_hardwareInterface;

    bool m_cacheConnected;
    QString m_cachePingMessage;
    QString m_cacheStatus;
    int m_cacheTimer{};

    bool m_hardwareConnected;
    QString m_hardwarePingMessage;
    QString m_hardwareStatus;
    int m_hardwareTimer{};
    int m_ramUsage;
};

#endif // UI_H
