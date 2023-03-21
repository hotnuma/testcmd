/*
 * Copyright (c) 2003 Riccardo Persichetti <riccardo.persichetti@tin.it>
 * Copyright (c) 2010 Florian Rivoal <frivoal@xfce.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PROC_STAT "/proc/stat"

static unsigned long oldtotal;
static unsigned long oldused;

double cpuload()
{
    unsigned long long int user, unice, usystem, idle, iowait, irq, softirq, guest;
    unsigned long used, total;

    double cpu_used;

    FILE *fd = fopen(PROC_STAT, "r");
    if (!fd)
    {
        //print("File /proc/stat not found!");

        return 0;
    }

    // Don't count steal time. It is neither busy nor free time.

    int nb_read = fscanf(fd, "%*s %llu %llu %llu %llu %llu %llu %llu %*u %llu",
                         &user, &unice, &usystem, &idle, &iowait, &irq, &softirq, &guest);

    fclose(fd);

    if (nb_read <= 4) iowait = 0;
    if (nb_read <= 5) irq = 0;
    if (nb_read <= 6) softirq = 0;
    if (nb_read <= 7) guest = 0;

    used = user + unice + usystem + irq + softirq + guest;
    total = used + idle + iowait;

    if ((total - oldtotal) != 0)
    {
        cpu_used = (double) (100.0 * (double) (used - oldused)) / (double) (total - oldtotal);
    }
    else
    {
        cpu_used = 0;
    }

    oldused = used;
    oldtotal = total;

    return cpu_used;
}

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    int tick = 1;

    int n = 1;
    while (n < argc)
    {
        if (strcmp(argv[n], "-s") == 0)
        {
            if (++n >= argc)
                return 1;

            tick = atoi(argv[n]);
        }
        else
        {
            printf("wrong option\n");
            return 1;
        }

        n++;
    }

    if (tick < 1 || tick > 120)
        tick = 1;

    while (1)
    {
        double cpu = cpuload();

        printf("cpuload : %lf\n", cpu);

        sleep(tick);
    }

    return 0;
}


