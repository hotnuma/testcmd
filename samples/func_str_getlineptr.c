#include <cstring.h>
#include <libstr.h>
#include <print.h>

int main()
{
    char buffer[] = "bla\nble\nblie";

    char *ptr = buffer;
    char *result;
    int length;

    while (str_getlineptr(&ptr, &result, &length))
    {
        result[length] = '\0';
        print(result);
    }

    return 0;
}


