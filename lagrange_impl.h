#ifndef LAGRANGE_IMPL
#define LAGRANGE_IMPL

#include "lagrange.h"

class lagrange_impl : public lagrange 
{
    public:
        double y_x(double x) override;
        double P(double x);

        double Pi(double x, int j);
        double P0(double x);
        double P1(double x);
        double P2(double x);
        double P3(double x);
        double P4(double x);
};

#endif // LAGRANGE_IMPL
