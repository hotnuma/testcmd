#include <libmacros.h>
#include <stdlib.h>
#include <string.h>
#include <print.h>

int main()
{
    c_autofree char *buffer = (char*) malloc(sizeof(char) * 32);

    strcpy(buffer, "blablie");
    print(buffer);

    return EXIT_SUCCESS;
}


