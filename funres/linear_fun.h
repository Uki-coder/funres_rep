#ifndef LINEAR_FUN_H
#define LINEAR_FUN_H
#include <vector>

// lines are using by equation A*x + B*y + C = 0
// that gives ability to use lines which are parallel to Ox or Oy

class linear_fun
{
    long double a_X, b_Y, c; // koeffs A, B, C
public:
    linear_fun(long double a, long double b, long double c);
    long double integrate(long double first_limit, long double second_limit);
    long double derivative();
    bool check_perpendicular(linear_fun fun2);
    std::vector<long double> get_koeffs();
    bool check_parrallel(linear_fun fun2);
    void set_koeffs(std::vector<long double> setting);
};

#endif // LINEAR_FUN_H
