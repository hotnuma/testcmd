
#include <syslog.h>
#include <stdarg.h>

#define APP_NAME "myapp"

int app_log(int level, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vsyslog(level, fmt, args);
    va_end(args);

    return 0;
}

int main()
{
    //openlog(APP_NAME, LOG_PID, LOG_USER);

    syslog(LOG_INFO, "Start logging");

    //closelog();
}


