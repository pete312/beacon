#include "query.h"

Query::Query(QObject *parent) :
    QObject(parent)
{
}


void Query::copyBuff(QByteArray &buff)
{
    buff = _buff;
}
