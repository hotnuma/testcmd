#include "gd.h"
#include <stdio.h>
#include <stdlib.h>

// cbuild resize resize.c libgd

enum ColorSwapType
{
    CSWP_RGB_RBG,
    CSWP_RGB_BGR,
    CSWP_RGB_BRG,
    CSWP_RGB_GRB,
    CSWP_RGB_GBR,
};

void img_filter(gdImage *src, enum ColorSwapType type);
void rgb2rbg(int *r, int *g, int *b);
void rgb2bgr(int *r, int *g, int *b);
void rgb2brg(int *r, int *g, int *b);
void rgb2grb(int *r, int *g, int *b);
void rgb2gbr(int *r, int *g, int *b);

void img_filter(gdImage *src, enum ColorSwapType type)
{
    int c, a, r, g, b, new_pxl;

    void (*func)(int*, int*, int*);

    switch (type)
    {
        case CSWP_RGB_RBG:
            func = &rgb2rbg;
            break;
        case CSWP_RGB_BGR:
            func = &rgb2bgr;
            break;
        case CSWP_RGB_BRG:
            func = &rgb2brg;
            break;
        case CSWP_RGB_GRB:
            func = &rgb2grb;
            break;
        case CSWP_RGB_GBR:
            func = &rgb2gbr;
            break;
        default:
            func = &rgb2rbg;
            break;
    }

    for (int y = 0; y < src->sy; ++y)
    {
        for (int x = 0; x < src->sx; ++x)
        {
            c = gdImageGetPixel(src, x, y);

            r = gdImageRed(src, c);
            g = gdImageGreen(src, c);
            b = gdImageBlue(src, c);
            a = gdImageAlpha(src, c);

            func(&r, &g, &b);

            new_pxl = gdImageColorAllocateAlpha(src, r, g, b, a);
            if (new_pxl == -1)
            {
                new_pxl = gdImageColorClosestAlpha(src, r, g, b, a);
            }

            gdImageSetPixel (src, x, y, new_pxl);
        }
    }
}

void rgb2rbg(int *r, int *g, int *b)
{
    (void) r;

    int tmp = *b;
    *b = *g;
    *g = tmp;
}

void rgb2bgr(int *r, int *g, int *b)
{
    (void) g;

    int tmp = *b;
    *b = *r;
    *r = tmp;
}

void rgb2brg(int *r, int *g, int *b)
{
    int tmp = *b;
    *b = *r;
    *r = *g;
    *g = tmp;
}

void rgb2grb(int *r, int *g, int *b)
{
    (void) b;

    int tmp = *g;
    *g = *r;
    *r = tmp;
}

void rgb2gbr(int *r, int *g, int *b)
{
    int tmp = *g;
    *g = *r;
    *r = *b;
    *b = tmp;
}

int main(int argc, char **argv)
{
    const char *appname = argv[0];

    if (argc < 4)
    {
        printf("%s input.png output.png 0\n", appname);

        return EXIT_FAILURE;
    }

    const char *inpath = argv[1];
    const char *outpath = argv[2];
    int color_type = atoi(argv[3]);

    FILE *fp = fopen(inpath, "rb");
    if (!fp)
    {
        fprintf(stderr, "can't read image %s\n", inpath);

        return EXIT_FAILURE;
    }

    gdImage *img = gdImageCreateFromPng(fp);
    fclose(fp);

    if (!img || !img->trueColor)
    {
        fprintf(stderr, "Can't create image from %s\n", inpath);

        return EXIT_FAILURE;
    }

    img_filter(img, color_type);

    fp = fopen(outpath, "wb");
    if (!fp)
    {
        gdImageDestroy(img);

        fprintf(stderr, "Can't save image %s\n", outpath);

        return EXIT_FAILURE;
    }

    gdImagePng(img, fp);
    fclose(fp);

    gdImageDestroy(img);

    return EXIT_SUCCESS;
}


