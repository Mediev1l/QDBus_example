/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -a cache_adaptor ../../Interfaces/com.scythestudio.cache.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef CACHE_ADAPTOR_H
#define CACHE_ADAPTOR_H

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
 * Adaptor class for interface com.scythestudio.cache
 */
class CacheAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.scythestudio.cache")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"com.scythestudio.cache\">\n"
"    <method name=\"ping\">\n"
"      <arg direction=\"out\" type=\"s\"/>\n"
"      <arg direction=\"in\" type=\"s\"/>\n"
"    </method>\n"
"    <method name=\"status\">\n"
"      <arg direction=\"out\" type=\"s\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    CacheAdaptor(QObject *parent);
    virtual ~CacheAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    QString ping(const QString &in0);
    QString status();
Q_SIGNALS: // SIGNALS
};

#endif
