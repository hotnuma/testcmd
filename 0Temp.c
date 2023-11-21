#if 0

#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <print.h>


int main()
{
    //setlocale(LC_COLLATE, "fr_FR.UTF-8");
    setlocale(LC_COLLATE, "");
    //setlocale(LC_ALL, "");

    print("cmp = %d", strcasecmp("b", "à"));

    //print("char = %c", (char) tolower('à'));

    return EXIT_SUCCESS;
}



#endif


