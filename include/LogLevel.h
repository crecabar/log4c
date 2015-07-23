/* 
 * File:   LogLevels.h
 * Author: crecabar
 *
 * Created on May 15, 2015, 1:45 PM
 * 
 * @ver 1.0
 */

#ifndef ___LOGLEVEL_H__
#define	___LOGLEVEL_H__

namespace log
{
    enum LogLevel {
        EMERGENCY, 
        ALERT, 
        CRITICAL,
        ERROR,
        WARNING,
        NOTICE,
        INFO,
        DEBUG
    };
    
}

#endif	/* LOGLEVEL_H */

