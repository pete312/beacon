#include "payload.h"
#include <QDataStream>

Payload::Payload(const QString &hostname, const QIODevice * device)
{
    _hostname = hostname;
    _device = device;
}

void Payload::sendInfo(const QString & name)
{

}


void Payload::sendSystemCommand(const QString & command, const QStringList &args )
{

}
