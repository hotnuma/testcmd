#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include <print.h>

#define BSIZE 32
extern int errno;

int main()
{
    char buff[BSIZE] = "123456789";

    int fd = open("/home/hotnuma/test3", O_RDONLY);
    if (fd < 0)
        return 1;

    int nb_read = read(fd, buff, BSIZE - 1);

    print("%d bytes read", nb_read);

    //buff[nb_read] = '\0';

    print(buff);

    close(fd);

    return 0;
}


