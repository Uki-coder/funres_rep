#include "linear_fun.h"

linear_fun::linear_fun(long double a, long double b, long double c) : a_X(a), b_Y(b), c(c)
{

}

long double linear_fun::integrate(long double first_limit, long double second_limit)
{
    long double result;
    if(!a_X)
    {
        long double y = b_Y / c * -1;
        result = (second_limit - first_limit) * y;
    }

    else
    {
        if(!b_Y)
        {
            //std::cout << "Error";
            result = 0.;
        }

        else
        {
            result = -(a_X * 0.5 * (second_limit * second_limit - first_limit * first_limit) + c) / b_Y;
        }
    }

    return result;
}

long double linear_fun::derivative()
{
    return -a_X / b_Y;
}

bool linear_fun::check_perpendicular(linear_fun fun2)
{
    std::vector<long double> fun2_koeffs = fun2.get_koeffs();

    long double result = (-a_X / b_Y) * (-fun2_koeffs[0] / fun2_koeffs[1]); // because of inaccuracy of computer calculations we can't coompare
    // result with -1 with if(result == -1), so, we need the next operations:

    result *= -1000;
    result -= 1000;


    if (result < 1 && result > 0) return true;
    else return false;

}

std::vector<long double> linear_fun::get_koeffs()
{
    std::vector<long double> koeffs(3);
    koeffs[0] = a_X;
    koeffs[1] = b_Y;
    koeffs[2] = c;

    return koeffs;
}

void linear_fun::set_koeffs(std::vector<long double> setting)
{
    // don't forget about checking exceptions

    a_X = setting[0];
    b_Y = setting[1];
    c = setting[2];

}

bool linear_fun::check_parrallel(linear_fun fun2)
{
    std::vector<int> koef_f1(2);
    std::vector<int> koef_f2(2);
    std::vector<long double> koef_f2_double = fun2.get_koeffs();

    for(int i = 0; i < 2; ++i)
    {
        koef_f2[i] = koef_f2_double[i] * 1000;
    }

    koef_f1[0] = a_X * 1000;
    koef_f1[1] = b_Y * 1000;
    //koef_f1[2] = c * 1000;

    double k1_double = -1.*koef_f1[1]/koef_f1[0];
    double k2_double = -1.*koef_f2[1]/koef_f2[0];

    int k1 = k1_double * 1000;
    int k2 = k2_double * 1000;

    if(k1 == k2) return true;
    else return false;
}
