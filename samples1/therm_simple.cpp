#include <math.h>
#include <float.h>
#include <print.h>

const double T0 = 25 + 273.15;
const double RT0 = 10000.0;
const double B = 3435.0;

float readTemp(double val)
{
    return (1 / ((1/T0) + (1/B) * log(val / RT0))) - 273.15;
}

int main()
{
    double val = readTemp(5000.0);

    print("temp : %f", val);

    return 0;
}


