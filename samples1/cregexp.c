#include <cregexp.h>
#include <string.h>

#include <print.h>

int main()
{
    const char *str = "01,bla,02,blé,03,blie";

    CRegExpAuto *rx = cregexp_new_pattern("(\\w+)");

    int pos = 0;

    CStringAuto *part = cstr_new_size(32);

    while ((pos = cregexp_indexin(rx, str, pos)) != -1)
    {
        cregexp_cap(rx, part, 0);

        print("count = %i", cregexp_capturecount(rx));

        const char *p = c_str(part);

        print(p);

        if (strcmp(p, "blé") == 0)
        {
            print("> found : %s", p);
        }

        pos += cregexp_matchedlength(rx);
    }

    return 0;
}


