#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <map>
#include <stdio.h>
#include <QString>


class AppSettings
{
public:
    AppSettings();

    bool getValue(const QString & name, QString & value  );
    void setValue(const QString & name, const QString & value);
    bool getDBLocation(QString & result);

private:
    std::map<QString, QString > _nv_pair;

};

#endif // APPSETTINGS_H
