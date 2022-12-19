#include <cstring.h>

#include <print.h>

int main()
{
    const char *buffer = "bla\nble\nblie";
    const char *ptr = buffer;

    CStringAuto *line = cstr_new_size(32);

    while (str_getline(&ptr, line))
    {
        print(c_str(line));
    }

    return 0;
}


