/* 
 * File:   test.cpp
 * Author: crecabar
 *
 * Created on May 15, 2015, 2:59 PM
 */

#include <iostream>
#include <map>

#include <Logger.h>


using namespace std;
using namespace log;

int main(int argc, char* argv[])
{
    Logger *logger = Logger::getInstance();
    char message[] = "Hello world!";
    Context context;
    context.insert(pair<string,string>(string("test"), string("main")));
    logger->registerContext(context);
    
    logger->emergency(message, context);
    logger->alert(message, context);
    logger->critical(message, context);
    logger->error(message, context);
    logger->warning(message, context);
    logger->notice(message, context);
    logger->info(message, context);
    logger->debug(message, context);
    
    return 0;
}