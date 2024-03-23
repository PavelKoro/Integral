#include <iostream>
#include <math.h>
#include "integral.h"

#define EPS 0.0001

double integral::estim() {
    int k = 2;
    while(1) {
        if(Taylor(M_PI, k) != 0 && Taylor(M_PI, k) < EPS*0.01) {
            double x1 = 1/pow_my(2, k);
            double x2 = 1-1/2;
            return x1/x2;
        }
        k++;
    }
}

double integral::equation() {
    double result = 0;
    count = 0;
    while(1) {
        result += antider(M_PI, count);  
        if(antider(M_PI, count) != 0) {
            if(antider(M_PI, count) < EPS) {
                return result;
            }
        }
        count++;
    }
    return result;
}

double integral::antider(double x, int k) {
    if(k > 1) {
        return Taylor(x, k)/(k/2);
    } else {
        return 0;
    }
}

double integral::Taylor(double x, int k) {
    double result = 0;
    if((k-1)%2 == 0) {
        result = 0;
    } else {
        result = pow_my(x, k/2)/factorial(k);
    }
    return result;
}

double integral::pow_my(double x, int k) {
    double copy = x;
    for(int i=0; i<k-1; i++) {
        x = x*copy;
    }
    return x;
}

long int integral::factorial(int x) {
    if(x <= 1) {
        return 1;
    } else {
        return x*factorial(x-1);
    }
}