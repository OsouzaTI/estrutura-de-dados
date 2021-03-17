#ifndef LOGS_SYSTEM
#define LOGS_SYSTEM

#include <stdio.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

enum LogType {
    ERROR = 0,
    INFO,
    WARNING,
    DEBUG
};

#define logs(type, message) _logs(type, __FILE__, __LINE__, (message))
void _logs(int type, const char *file, long line, const char *message){   
    switch (type)
    {
    case ERROR:
        printf(RED "[%s][%ld] -> %s\n" RESET, file, line, message);
        break;
    case INFO:
        printf(GREEN "[%s][%ld] -> %s\n" RESET, file, line, message);
        break;
    case WARNING:
        printf(YELLOW "[%s][%ld] -> %s\n" RESET, file, line, message);
        break;
    case DEBUG:
        printf(BLUE "[%s][%ld] -> %s\n" RESET, file, line, message);
        break;    
    default:
        printf("log type error\n");
        break;
    }

}



#endif