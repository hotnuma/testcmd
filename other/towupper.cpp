#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "print.h"
#include "strconv.h"
#include "CFile.h"

int main()
{
    print(setlocale(LC_ALL, ""));

    wchar_t str[] = L"eéè";

    CFile file;
    file.open("D:/Downloads/test.txt", "wb");

    CString result = wcharToCString(str);
    file << result;
    file << "\n";

    int size = wcslen(str);
    for (int i = 0; i < size; ++i)
    {
        str[i] = towupper(str[i]);
    }

    result = wcharToCString(str);

    file << result;
    file << "\n";

    return 0;
}

