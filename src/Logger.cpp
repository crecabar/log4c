/* 
 * File:   Logger.cpp
 * Author: crecabar
 *
 * Created on May 15, 2015, 3:19 PM
 */

#include <iostream>
#include <cstring>
#include <LoggerInterface.h>
#include <LogLevel.h>
#include <LogContext.h>
#include <Logger.h>

using namespace log;

bool Logger::instanceFlag = false;
Logger* Logger::logger = NULL;
Context _context;

Logger* Logger::getInstance()
{
    if(!instanceFlag) {
        logger = new Logger();
        instanceFlag = true;
    }
    
    return logger;
}

char* Logger::getLogLabbel(LogLevel level)
{
    char* labbel = new char[10];
    switch(level) {
        case EMERGENCY:
            strcpy(labbel, "EMERGENCY");
            return labbel;
            break;
        case ALERT:
            strcpy(labbel, "ALERT");
            return labbel;
            break;
        case CRITICAL:
            strcpy(labbel, "CRITICAL");
            return labbel;
            break;
        case ERROR:
            strcpy(labbel, "ERROR");
            return labbel;
            break;
        case WARNING:
            strcpy(labbel, "WARNING");
            return labbel;
            break;
        case NOTICE:
            strcpy(labbel, "NOTICE");
            return labbel;
            break;
        case INFO:
            strcpy(labbel, "INFO");
            return labbel;
            break;
        case DEBUG:
            strcpy(labbel, "DEBUG");
            return labbel;
            break;
    }
}

void Logger::log(LogLevel level, char* message, Context context)
{
    Context::iterator it = context.begin();
    
    std::cout 
            << "[" << (*it).first << "." << (*it).second << "]: "
            << this->getLogLabbel(level) << ": " << message << std::endl;
}

void Logger::registerContext(Context context)
{
    _context.insert(context.begin(), context.end());
}

void Logger::registerContext(std::string file, std::string function)
{
    _context.insert(std::pair<std::string,std::string>(file, function));
}
