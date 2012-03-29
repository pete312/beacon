#include "appsettings.h"
#include <map>


AppSettings::AppSettings()
{
}


bool AppSettings::getValue(const QString &name, QString &value){
    std::map<QString, QString>::iterator it;

    it = _nv_pair.find(name);
    if (it == _nv_pair.end()){
        value = "";
        return false;
    }
    else {
        value = it->second;
        return true;
    }
}


void AppSettings::setValue(const QString & name, const QString & value){
    _nv_pair[name] = value;
}


bool AppSettings::getDBLocation(QString & result){
    return getValue("_DBFile", result);
}
