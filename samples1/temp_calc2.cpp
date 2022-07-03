#include <math.h>
#include <float.h>
#include <stdio.h>

// https://www.onlinegdb.com/online_c_compiler

const double T0 = 25 + 273.15;
const double RT0 = 10000.0;
const double B = 3435.0;

double readTemp(double Rval)
{
    return (1 / ((1/T0) + (1/B) * log(Rval / RT0))) - 273.15;
}

double calcR2(double Ut)
{
    return (Ut / (5.0 - Ut)) * 5600.0;
}

int main()
{
    double R2 = calcR2(2.58);
    
    double val = readTemp(R2);

    printf("temp : %f\n", val);

    return 0;
}


