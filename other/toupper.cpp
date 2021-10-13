#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "print.h"
#include "strconv.h"
#include "CFile.h"

CString toUpper(const char *str)
{
    wchar_t *wstr = utf8ToWchar(str);

    int size = wcslen(wstr);
    for (int i = 0; i < size; ++i)
    {
        wstr[i] = towupper(wstr[i]);
    }

    CString result = wcharToCString(wstr);
    free(wstr);

    return result;
}

int main()
{
    print(setlocale(LC_ALL, ""));

    CString test = "eéè";

    CString result = toUpper(test);

    CFile file;
    file.open("D:/test.txt", "wb");

    file << result;
    file << "\n";

    return 0;
}

