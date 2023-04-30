#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define GC_UNUSED __attribute__((__unused__))
#define GC_CLEANUP(func) __attribute__((cleanup(func)))

#define test_autofree GC_CLEANUP(_freeBufferTest)

GC_UNUSED static inline void _freeBufferTest(void *p)
{
    void **pp = (void**) p;

    if (*pp)
    {
        printf("free : %p\n", *pp);
        free(*pp);
    }
}

int main()
{
    test_autofree char *ptr = NULL;
    char *bla = strdup("bla");
    char *ble = strdup("ble");

    ptr = bla;
    printf("bla %p\n", bla);
    printf("ptr %p\n", ptr);

    ptr = ble;
    printf("ble %p\n", ble);
    printf("ptr %p\n", ptr);

    free(bla);

    return 0;
}


