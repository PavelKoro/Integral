#include <iostream>
#include <math.h>
#include "integral.h"

#define EPS 0.0001

double integral::estim() {
    return ((1/factorial(10))/(M_PI-1));
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
        return x*Taylor(x, k)/(k/2);
    } else {
        return 0;
    }
}

double integral::Taylor(double x, int k) {
    double result = 0;
    
    if(k == 2) {
        result = 0.5;
    } else if((k-1)%2 != 0) {
        result = pow_my(x, (k/2)-1)/factorial(k);
    } else {
        result = 0;
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