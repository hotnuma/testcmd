#include <libapp.h>
#include <time.h>

#include <print.h>

int main()
{
    CStringAuto *result = cstr_new_size(32);

    get_localtime(result, "%b %d %H:%M:%S");

    print("Local time : %s", c_str(result));

    struct tm tm;
    time_t epoch;

    if (strptime(c_str(result), "%b %d %H:%M:%S", &tm) != NULL)
    {
        epoch = mktime(&tm);

        print("Unix  time : %"PRIu64, epoch);
    }

    return EXIT_SUCCESS;
}


