#include "Logger.h"
#include <stdarg.h>

typedef std::ostream &(*fPtr)(std::ostream &);

void LogMessage(LogLevels logLevel, const char *message, ...)
{
    const char *logLevelString[4] = {"[Error]: ", "[Warning]: ", "[Debug]: ", "[Info]: "};
    fPtr colorOuts[4] = {red, pink, yellow, green};

    char outMessage[32000];
    std::memset(outMessage, 0, sizeof(outMessage));

    va_list args;
    va_start(args, message);
    vsnprintf_s(outMessage, sizeof(outMessage), message, args);
    va_end(args);

    char formatMessage[32000];
    sprintf(formatMessage, "%s%s\n", logLevelString[logLevel], outMessage);

    std::cout << colorOuts[logLevel] << formatMessage;

    if(logLevel == LogLevels::LERROR)
        std::cout << white;
}
