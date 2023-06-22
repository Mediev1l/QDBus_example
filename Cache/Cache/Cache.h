#ifndef CACHE_H
#define CACHE_H

#include <QObject>
#include "cache_adaptor.h"

class Cache : public QObject
{
    Q_OBJECT
public:
    explicit Cache(QObject *parent = nullptr);

public slots:
    QString ping(const QString &message);
    QString status();

private:
    CacheAdaptor* m_cacheAdaptor;
    int m_status{0};
};

#endif // CACHE_H
