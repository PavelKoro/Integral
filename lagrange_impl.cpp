#include <iostream>
#include <cmath>
#include "lagrange_impl.h"
#include "lagrange.h"

double lagrange_impl::y_x(double x) {
    if(x != 0) {
        double y1 = (cosh(sqrt(x))-1);
        double y2 = x;
        return y1/y2;
    } else {
        return 0.5;
    }
}

double lagrange_impl::P(double x) {
    double res = 0;
    for(int i=0; i<n; i++) {
        res += y_x(num[i])*Pi(x, num[i]);
    }
    return res;
}

double lagrange_impl::Pi(double x, int j) {
    double y = 1;
    for(int k=0; k < n; k++) {
        if(k != j) {
            y *= ((x-num[k])/(num[j]-num[k]));
        }
    }
    return y;
}

double lagrange_impl::P0(double x) {
    return y_x(num[0])*Pi(x, 0);
}

double lagrange_impl::P1(double x) {
    return y_x(num[1])*Pi(x, 1);
}

double lagrange_impl::P2(double x) {
    return y_x(num[2])*Pi(x, 2);
}

double lagrange_impl::P3(double x) {
    return y_x(num[3])*Pi(x, 3);
}

double lagrange_impl::P4(double x) {
    return y_x(num[4])*Pi(x, 4);
}

extern "C" {
    lagrange* create_lagrange() {
        return new lagrange_impl();
    }

    void destroy_lagrange(lagrange* ptr) {
        delete ptr;
    }

    double y_x(lagrange* ptr, double x) {
        return ptr->y_x(x);
    }

    double P(lagrange* ptr, double x) {
        return ptr->P(x);
    }

    double Pi(lagrange* ptr, double x, int j) {
        return ptr->Pi(x, j);
    }

    double P0(lagrange* ptr, double x) {
        return ptr->P0(x);
    }

    double P1(lagrange* ptr, double x) {
        return ptr->P1(x);
    }

    double P2(lagrange* ptr, double x) {
        return ptr->P2(x);
    }

    double P3(lagrange* ptr, double x) {
        return ptr->P3(x);
    }

    double P4(lagrange* ptr, double x) {
        return ptr->P4(x);
    }
}
