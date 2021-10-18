#include <CString.h>
#include <string.h>
#include <stdio.h>

#include <print.h>

void strshow(const char *str)
{
    CString result;
    char buff[20];

    int len = strlen(str);
    for (int i = 0; i < len; ++i)
    {
        if (i > 0)
            result.append("\\");

        signed char c = str[i];

        snprintf(buff, sizeof(buff), "%u", c);
        result.append(buff);

    }

    print(result);

}

int main()
{
    strshow("blabléblie");

    return  0;
}


