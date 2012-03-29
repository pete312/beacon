#ifndef QUERY_H
#define QUERY_H

#include <QObject>
#include <metric.h>

class Query : public QObject
{
    Q_OBJECT
public:
    explicit Query(QObject *parent = 0);

    void addMetric(Metric &m);

signals:

    void hasData();

public slots:
    void copyBuff(QByteArray &buff);

private:
    QByteArray _buff;

};

#endif // QUERY_H
