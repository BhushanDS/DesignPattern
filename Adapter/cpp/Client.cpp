#include "adapter.h"

int main()
{
    string mylog = "Console";
    LoggerAdapter *logMechanism = LoggerAdapter::CreateInstance(mylog);

    logMechanism->LogMsg("I Love Coding");

    mylog = "File";
    logMechanism->SetLogSystem(mylog);
    logMechanism->LogMsg("I Change Log Mechanism");
    logMechanism->LogMsg("I Love Coding");
    return 0;
}