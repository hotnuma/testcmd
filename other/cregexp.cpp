#include "CRegExp.h"
#include "libtest.h"

#include "string.h"
#include "libfile.h"
#include "print.h"

extern char g_root[];

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

void test_CRegExp()
{
    const char *str = "01,bla,02,blé,03,blie";

    CString output = str;
    output += "\n";
    output += "blé\n";

    CRegExp rx("(\\w+)");

    bool found = false;
    int pos = 0;

    while ((pos = rx.indexIn(str, pos)) != -1)
    {
        CString part = rx.cap(0);

        //print("count = %i", rx.captureCount());

        print(part);
        output += part;
        output += "\n";

        //if (strcmp(part.c_str(), "blé") == 0)
        //    found = true;

        //if (part.compare("bla") == 0)
        //    found = true;

        pos += rx.matchedLength();
    }

    //ASSERT(found);

    CString filepath = strFmt("%s\\%s", g_root, "\\regexp.txt");
    fileWrite(filepath, output);

}


