#ifndef APPLICATIONSETTINGS_H
#define APPLICATIONSETTINGS_H

#include <QString>


class ApplicationSettings
{

public:
    enum BeaconConnectionType { KCTypeHostString, KCTypeIpv4 };

    ApplicationSettings();

    void setConnHostname(const QString host, const int port);
    void setConnIPv4( const int n_1
                        , const int n_2
                        , const int n_3
                        , const int n_4
                        , const int port);

    int getPort() { return _port; }
    QString getHostString();


    BeaconConnectionType _type;
    int _ip_1;
    int _ip_2;
    int _ip_3;
    int _ip_4;

    QString _host;
    int _port;
};

#endif // APPLICATIONSETTINGS_H
