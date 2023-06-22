#ifndef HARDWARE_H
#define HARDWARE_H

#include <QObject>
#include "hardware_adaptor.h"

class Hardware : public QObject
{
    Q_OBJECT
public:
    explicit Hardware(QObject *parent = nullptr);

public slots:
    QString ping(const QString &message);
    int ramUsage();
    QString status();

private:
    HardwareAdaptor* m_hardwareAdaptor;
    int m_status{0};
};

#endif // HARDWARE_H
