#include <math.h>
#include <stdio.h>

double dtok(double temp)
{
    return temp + 273.15;
}

int main()
{
    double T1 = 13.10;
    double R1 = 17240.0;
    double T2 = 25.0;
    double R2 = 10830.0;

    double beta = (log(R1 / R2)) / ((1.0 / dtok(T1)) - (1.0 / dtok(T2)));

    printf("beta : %f\n", beta);

    return 0;
}


