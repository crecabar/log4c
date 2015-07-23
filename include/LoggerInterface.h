/* 
 * File:   LoggerInterface.h
 * Author: crecabar
 *
 * Created on May 15, 2015, 1:39 PM
 * 
 * @ver 1.0
 */

#ifndef ___LOGGERINTERFACE_H__
#define	___LOGGERINTERFACE_H__

#include <LogLevel.h>
#include <LogContext.h>

namespace log
{
    class LoggerInterface
    {
    public:
        
        /**
         * System is unusable.
         * 
         * @param char* message
         * @param Context context
         */
        virtual void emergency(char *message, Context context) = 0;
        
        /**
         * Action must be taken immediately.
         * 
         * Example: Entire software down, database unavailable, etc. This should
         * trigger the SMS alerts and wake you up.
         *  
         * @param char* message
         * @param Context context
         */
        virtual void alert(char *message, Context context) = 0;
        
        /**
         * Critical conditions.
         * 
         * Example: Application component unavailable, unexpected exception.
         *  
         * @param char* message
         * @param Context context
         */
        virtual void critical(char *message, Context context) = 0;
        
        /**
         * Runtime errors that do not require immediate action but should typically
         * be logged and monitored.
         *  
         * @param char* message
         * @param Context context
         */
        virtual void error(char *message, Context context) = 0;
        
        /**
         * Exceptional occurrences that are not errors.
         * 
         * Example: Use of deprecated APIs, poor use of an API, undesirable things
         * that are not necessarily wrong.
         * 
         * @param char* message
         * @param Context context
         */
        virtual void warning(char *message, Context context) = 0;
        
        /**
         * Normal but significant events.
         * 
         * @param char* message
         * @param Context context
         */
        virtual void notice(char *message, Context context) = 0;
        
        /**
         * Interesting events.
         * 
         * Example: User logs in, SQL logs.
         * 
         * @param char* message
         * @param Context context
         */
        virtual void info(char *message, Context context) = 0;
        
        /**
         * Detailed debug information.
         * 
         * @param char* message
         * @param Context context
         */
        virtual void debug(char *message, Context context) = 0;
        
        /**
         * Logs with an arbitrary level.
         * 
         * @param LogLevel level
         * @param char* message
         * @param Context context
         */
        virtual void log(LogLevel level, char *message, Context context) = 0;
    };
}


#endif	/* LOGGERINTERFACE_H */

