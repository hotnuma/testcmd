#include "dirent.h"
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>

char *myname;
int process(const char *dir);

/* main --- loop over directory arguments */

int
nodots(const struct dirent *dp)
{
    return (dp->d_name[0] != '.');
}

int main(int argc, char **argv)
{
    const char *dir = "D:/_Supprimer";

    DIR *dp;
    struct dirent **entries;
    int nents, i;

    nents = scandir(dir, & entries, nodots, alphasort);
    if (nents < 0) {
        fprintf(stderr, "%s: scandir failed: %s\n", myname,
                strerror(errno));
        return 1;
    }

    for (i = 0; i < nents; i++) {
        printf("%8ld %s\n", entries[i]->d_ino, entries[i]->d_name);
        free(entries[i]);
    }

    free(entries);

    return 0;
}


