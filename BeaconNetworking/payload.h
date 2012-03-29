#ifndef PAYLOAD_H
#define PAYLOAD_H
#include <QIODevice>

class Payload
{
public:
    explicit Payload( const QString & hostname, const QIODevice * device );

    void sendInfo(const QString & name );
    void sendSystemCommand( const QString & command, const QStringList &args );

private:

    QString _hostname;
    const QIODevice * _device;

};




#endif // PAYLOAD_H
