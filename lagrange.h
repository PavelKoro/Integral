#ifndef LAGRANGE
#define LAGRANGE

class lagrange {
    public:
        int n = 5;
        int num[5] = {0, 1, 2, 3, 4};

        virtual double y_x(double x) = 0;
        virtual double P(double x) = 0;

        virtual double Pi(double x, int j) = 0;
        virtual double P0(double x) = 0;
        virtual double P1(double x) = 0;
        virtual double P2(double x) = 0;
        virtual double P3(double x) = 0;
        virtual double P4(double x) = 0;
};

#endif // LAGRANGE
