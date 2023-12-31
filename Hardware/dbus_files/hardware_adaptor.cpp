/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -a hardware_adaptor ../../Interfaces/com.scythestudio.hardware.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "hardware_adaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class HardwareAdaptor
 */

HardwareAdaptor::HardwareAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

HardwareAdaptor::~HardwareAdaptor()
{
    // destructor
}

QString HardwareAdaptor::ping(const QString &in0)
{
    // handle method call com.scythestudio.hardware.ping
    QString out0;
    QMetaObject::invokeMethod(parent(), "ping", Q_RETURN_ARG(QString, out0), Q_ARG(QString, in0));
    return out0;
}

int HardwareAdaptor::ramUsage()
{
    // handle method call com.scythestudio.hardware.ramUsage
    int out0;
    QMetaObject::invokeMethod(parent(), "ramUsage", Q_RETURN_ARG(int, out0));
    return out0;
}

QString HardwareAdaptor::status()
{
    // handle method call com.scythestudio.hardware.status
    QString out0;
    QMetaObject::invokeMethod(parent(), "status", Q_RETURN_ARG(QString, out0));
    return out0;
}

