#include "applicationsettings.h"
#include <beaconipc.h>

ApplicationSettings::ApplicationSettings() :
    _type(KCTypeHostString),
    _host(""),
    _port(0)
{

}

void ApplicationSettings::setConnHostname(const QString host, const int port)
{
    _host = host;
    _port = port;
    _type = KCTypeHostString;

}

void ApplicationSettings::setConnIPv4( const int n_1
                               , const int n_2
                               , const int n_3
                               , const int n_4
                               , const int port )
{
    _ip_1 = n_1;
    _ip_2 = n_2;
    _ip_3 = n_3;
    _ip_4 = n_4;
    _type = KCTypeIpv4;
}



QString ApplicationSettings::getHostString()
{

    if (_type == KCTypeHostString ){
        return _host;
    }
    else {
        return QString("%1.%2.%3.%4").arg(_ip_1).arg(_ip_2).arg(_ip_3).arg(_ip_4);
    }
}
