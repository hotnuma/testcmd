#include "gd.h"
#include <stdio.h>
#include <stdlib.h>

// cbuild resize resize.c libgd

int main(int argc, char **argv)
{
    // Help
    if (argc <= 4)
    {
        printf("%s  input.png  output.png  width  height\n", argv[0]);
        return 1;
    }

    // Size
    int w = atoi(argv[3]);
    int h = atoi(argv[4]);
    if (w <= 0 || h <= 0)
    {
        fprintf(stderr, "Bad size %dx%d\n", h, w);
        return 2;
    }

    // Input

    FILE *fp = fopen(argv[1], "rb");
    if (!fp)
    {
        fprintf(stderr, "Can't read image %s\n", argv[1]);
        return 3;
    }

    gdImagePtr imgin = gdImageCreateFromPng(fp);
    fclose(fp);
    if (!imgin)
    {
        fprintf(stderr, "Can't create image from %s\n", argv[1]);
        return 4;
    }

    // Resize
    gdImageSetInterpolationMethod(imgin, GD_LANCZOS3);
    gdImagePtr imgout = gdImageScale(imgin, w, h);
    if (!imgout)
    {
        fprintf(stderr, "gdImageScale fails\n");
        return 5;
    }

    // Output
    fp = fopen(argv[2], "wb");
    if (!fp)
    {
        fprintf(stderr, "Can't save image %s\n", argv[2]);
        return 6;
    }

    gdImagePng(imgout, fp);
    fclose(fp);

    // Cleanups
    gdImageDestroy(imgin);
    gdImageDestroy(imgout);

    return 0;
}


