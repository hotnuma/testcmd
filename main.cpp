#include <libapp.h>
#include <stdio.h>

#include <print.h>

int main()
{
    setbuf(stdout, NULL);

    pexec("/usr/bin/mpv /home/hotnuma/Downloads/test.avi");

    print("end");

    return 0;
}


