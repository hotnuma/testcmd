#include "CString.h"
#include "string.h"

#include "print.h"

bool parseList(const char **buffer, CString &result)
{
    const char *start = *buffer;

    if (*start == '\0')
        return false;

    const char *p = start;

    while (true)
    {
        if (*p == ',')
        {
            result.clear();
            result.append(start, p - start);

            *buffer = ++p;

            return true;
        }
        else if (*p == '\0')
        {
            result.clear();
            result.append(start, p - start);

            *buffer = p;

            return true;
        }

        ++p;
    }
}

bool parseSub(const CString &buffer, CString *part1, CString *part2)
{
    const char *start = buffer.c_str();
    const char *col = strchr(start, ':');

    if (col)
    {
        part1->clear();
        part1->append(start, col - start);

        part2->clear();
        part2->append(col + 1);

        return true;
    }

    return false;
}

int main()
{
    const char *test = "first1:last1,first2:last2,first3:last3";

    const char *buffer = test;
    CString result;
    CString part1;
    CString part2;

    while (parseList(&buffer, result))
    {
        if (parseSub(result, &part1, &part2))
        {
            print(part1);
            print(part2);
        }
    }

    return 0;
}


