#ifndef LOGS_SYSTEM
#define LOGS_SYSTEM

#include <stdio.h>

#ifdef ANSI_DEBUG
#define GREEN   "\x1b[32m"
#define RED     "\x1b[31m"
#define BLUE    "\x1b[34m"
#define YELLOW  "\x1b[33m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#else
#define RED     ""
#define GREEN   ""
#define YELLOW  ""
#define BLUE    ""
#define MAGENTA ""
#define CYAN    ""
#define RESET   ""
#endif

enum logType {
    ERROR,
    INFO,
    WARNING,
    DEBUG
};

#define logs(type, message) _logs(type, __FILE__, __FUNCTION__, __LINE__, (message))
void _logs(int type, const char *file, const char *function, long line, const char *message){   
    switch (type)
    {
    case ERROR:{
        printf(RED);
        printf("[%s -> %s][%ld] -> %s\n", file, function, line, message);
    }break;
    case INFO:{
        printf(GREEN);
        printf("[%s -> %s][%ld] -> %s\n", file, function, line, message);
    }break;
    case WARNING:{
        printf(YELLOW);
        printf("[%s -> %s][%ld] -> %s\n", file, function, line, message);
    }break;
    case DEBUG:{
        printf(BLUE);
        printf("[%s -> %s][%ld] -> %s\n", file, function, line, message);
    }break;    
    default:
        printf(RED "log type undefined\n");
        break;
    }
    printf(RESET);
}



#endif