#ifndef AGENTBASE_H
#define AGENTBASE_H
#include <applicationsettings.h>

class AgentBase : ApplicationSettings
{
public:
    //AgentBase();
    virtual void start() = 0;
    virtual void stop() = 0;

    void setPeriod(int milliseconds){ _period = milliseconds; }

private :
    int _period;

};

#endif // AGENTBASE_H
