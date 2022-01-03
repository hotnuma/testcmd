#include <stdio.h>
#include <string.h>

int main()
{
    setbuf(stdout, 0);

    char buffer[32] = "blableblie";

    printf("not null terminated\n");
    strncpy(buffer, "abc", 3);
    printf("%s\n", buffer);

    printf("null terminated\n");
    strncpy(buffer, "abc", 4);
    printf("%s\n", buffer);

    return 0;
}


