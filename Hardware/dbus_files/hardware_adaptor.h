/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -a hardware_adaptor ../../Interfaces/com.scythestudio.hardware.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef HARDWARE_ADAPTOR_H
#define HARDWARE_ADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

/*
 * Adaptor class for interface com.scythestudio.hardware
 */
class HardwareAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.scythestudio.hardware")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"com.scythestudio.hardware\">\n"
"    <method name=\"ping\">\n"
"      <arg direction=\"out\" type=\"s\"/>\n"
"      <arg direction=\"in\" type=\"s\"/>\n"
"    </method>\n"
"    <method name=\"status\">\n"
"      <arg direction=\"out\" type=\"s\"/>\n"
"    </method>\n"
"    <method name=\"ramUsage\">\n"
"      <arg direction=\"out\" type=\"i\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    HardwareAdaptor(QObject *parent);
    virtual ~HardwareAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    QString ping(const QString &in0);
    int ramUsage();
    QString status();
Q_SIGNALS: // SIGNALS
};

#endif