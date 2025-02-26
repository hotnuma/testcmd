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
    CSWP_RGB_TRS,
};

typedef struct _color
{
    int r;
    int g;
    int b;
    int val;

} color;

void img_filter(gdImage *src, enum ColorSwapType type, int val);
void rgb2rbg(color *cl);
void rgb2bgr(color *cl);
void rgb2brg(color *cl);
void rgb2grb(color *cl);
void rgb2gbr(color *cl);
void rgb2trs(color *cl);
int color_trans(int c, int val);

void img_filter(gdImage *src, enum ColorSwapType type, int val)
{
    void (*func)(color*);

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

        case CSWP_RGB_TRS:
            func = &rgb2trs;
            break;
        default:
            func = &rgb2rbg;
            break;
    }

    color cl = {0};
    int c, a, new_pxl;

    c = gdImageGetPixel(src, 0, 0);
    a = gdImageAlpha(src, c);

    printf("alpha = %d\n", a);

    for (int y = 0; y < src->sy; ++y)
    {
        for (int x = 0; x < src->sx; ++x)
        {
            c = gdImageGetPixel(src, x, y);
            a = gdImageAlpha(src, c);

            cl.r = gdImageRed(src, c);
            cl.g = gdImageGreen(src, c);
            cl.b = gdImageBlue(src, c);
            cl.val = val;

            func(&cl);

            new_pxl = gdImageColorAllocateAlpha(src, cl.r, cl.g, cl.b, a);
            if (new_pxl == -1)
            {
                new_pxl = gdImageColorClosestAlpha(src, cl.r, cl.g, cl.b, a);
            }

            gdImageSetPixel (src, x, y, new_pxl);
        }
    }
}

void rgb2rbg(color *cl)
{
    int tmp = cl->b;
    cl->b = cl->g;
    cl->g = tmp;
}

void rgb2bgr(color *cl)
{
    int tmp = cl->b;
    cl->b = cl->r;
    cl->r = tmp;
}

void rgb2brg(color *cl)
{
    int tmp = cl->b;
    cl->b = cl->r;
    cl->r = cl->g;
    cl->g = tmp;
}

void rgb2grb(color *cl)
{
    int tmp = cl->g;
    cl->g = cl->r;
    cl->r = tmp;
}

void rgb2gbr(color *cl)
{
    int tmp = cl->g;
    cl->g = cl->r;
    cl->r = cl->b;
    cl->b = tmp;
}

void rgb2trs(color *cl)
{
    cl->r = color_trans(cl->r, cl->val);
    cl->g = color_trans(cl->g, cl->val);
    cl->b = color_trans(cl->b, cl->val);
}

int color_trans(int c, int val)
{
    c += val;

    c &= 0xFF;

    return c;

    while (1)
    {
        if (c >= 0 && c <= 255)
            return c;
        else if (c < 0)
            c += 255;
        else if (c > 255)
            c -= 255;
    }
}

int main(int argc, char **argv)
{
    const char *appname = argv[0];

    if (argc < 5)
    {
        printf("%s input.png output.png 0 0\n", appname);

        return EXIT_FAILURE;
    }

    const char *inpath = argv[1];
    const char *outpath = argv[2];
    int color_type = atoi(argv[3]);
    int val = atoi(argv[4]);

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

    img_filter(img, color_type, val);

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


