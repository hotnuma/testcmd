#include <print.h>

int main()
{
    int capacity = 8;
    int size = 8;
    int start = 5;

    for (int i = 0; i < size; ++i)
    {
        print("%d", ((i + start) % capacity));
    }

    return 0;
}


