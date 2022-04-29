
#include <print.h>

void calcBox(double l, double w, double h, double e)
{
    e /= 10;

    print("top   (x2) %.2f x %.2f", l, w);
    print("sides (x2) %.2f x %.2f", l, h - (2 * e));
    print("sides (x2) %.2f x %.2f", w - (2 * e), h - (2 * e));
}

int main()
{
    calcBox(5, 4, 2, 2);

    return 0;
}


