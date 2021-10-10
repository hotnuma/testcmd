#include <syslog.h>

char logTxt[]="test";

int main()
{
    openlog(logTxt, LOG_CONS | LOG_PID, LOG_LOCAL7);
    syslog(LOG_DEBUG, "log test...");
    closelog();

    return 0;
}


