#if 0

#include <cstringlist.h>
#include <locale.h>

#include <print.h>

int main()
{
    setlocale(LC_ALL, "");

    const char *path = "./à/b/c.txt";
    int len = strxfrm(NULL, path, 0);

    CStringAuto *result = cstr_new_size(len + 1);
    strxfrm(cstr_data(result), path, len);
    cstr_terminate(result, len);

    print("%d", len);
    print("%s", c_str(result));

    return EXIT_SUCCESS;
}

#endif


