#include <libapp.h>

#define __USE_XOPEN
#include <time.h>

#include <print.h>

int main()
{
    CStringAuto *result = cstr_new_size(32);

    get_localtime(result, "%b %d %H:%M:%S");

    print(c_str(result));

    struct tm tm;
    time_t epoch;

    if (strptime(c_str(result), "%b %d %H:%M:%S", &tm) != NULL)
    {
        epoch = mktime(&tm);

        print("%" PRIu64, epoch);
    }

    return 0;
}


