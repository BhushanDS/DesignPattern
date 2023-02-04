#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ILogger
{
    public:
        virtual void Log(string &iLogMessage)  = 0;
       // virtual ~ILogger();
};

class ConsoleLogger: public ILogger
{
    public:
        void Log(string &iLogMessage);
        virtual ~ConsoleLogger(){}

};

class FileLogger:public ILogger
{
    public:
        void Log(string &iLogMessage);
        virtual ~FileLogger(){}
};

class LoggerAdapter
{
    private:
        ILogger *log;
        static LoggerAdapter * instance;
        LoggerAdapter(){};
    public:
        void SetLogSystem(string &LogSystem)
        {
            if(LogSystem == "Console")
            {
                delete log;
                log = nullptr;
                if(log == nullptr)
                    log = new ConsoleLogger();
            }
            else if (LogSystem == "File")
            {
                delete log;
                log =nullptr;
                if(log == nullptr)
                    log = new FileLogger();
            }

        }
        static LoggerAdapter* CreateInstance(string &LogSystem)
        {
            if(instance == nullptr)
            {
                instance = new LoggerAdapter();
                instance->SetLogSystem(LogSystem);
            }
            return instance;
        }

        void LogMsg(string iMessage)
        {
            this->log->Log(iMessage);
        }
};
LoggerAdapter * LoggerAdapter::instance = nullptr;

void FileLogger ::Log(string &iLogMessage)
        {
            std::ofstream file;
            file.open("filegogger.txt", std::ios::app);  

            if (!file.is_open()) {  
                file.open("filegogger.txt", std::ios::out);
            }

            file << iLogMessage << std::endl;  
            file.close();
        }


void ConsoleLogger:: Log(string &iLogMessage)
        {
            cout<<iLogMessage<<endl;
        }