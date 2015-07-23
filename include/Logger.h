/* 
 * File:   Logger.h
 * Author: crecabar
 *
 * Created on May 15, 2015, 3:19 PM
 */

#ifndef ___LOGGER_H__
#define	___LOGGER_H__

#include <LoggerInterface.h>
#include <LogContext.h>
#include <LogLevel.h>

using namespace log;

class Logger : public LoggerInterface
{
public:
    void emergency(char *message, Context context) { log(log::EMERGENCY, message, context); }
    void alert(char *message, Context context) { log(log::ALERT, message, context); }
    void critical(char *message, Context context) { log(log::CRITICAL, message, context); }
    void error(char *message, Context context) { log(log::ERROR, message, context); }
    void warning(char *message, Context context) { log(log::WARNING, message, context); }
    void notice(char *message, Context context) { log(log::NOTICE, message, context); }
    void info(char *message, Context context) { log(log::INFO, message, context); }
    void debug(char *message, Context context) { log(log::DEBUG, message, context); }
    void log(LogLevel level, char *message, Context context);
    void registerContext(Context context);
    void registerContext(std::string file, std::string function);
    char* getLogLabbel(LogLevel level);
    static Logger* getInstance();
private:
    static Logger* logger;
    static bool instanceFlag;
    Logger()
    {
        //
    }
};

#endif	/* LOGGER_H */

/*
    class LogLevelLabbel
    {
    public:
        char* getLogLabbel(LogLevel level);
        static LogLevelLabbel* getInstance();
    private:
        static LogLevelLabbel* log;
        static bool instanceFlag;
        LogLevelLabbel ()
        {
            //
        }
    };
 */
