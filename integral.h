#ifndef INTEGRAlL
#define INTEGRAlL

class integral {
    private:
        int count;
        double pow_my(double x, int k); // x^k
        long int factorial(int x); // факториал
        double antider(double x, int k); // первообразная f(x) = (ch(sqrt(x))-1)/x
    public:
        double estim(); // оценка остатка, используя сравнение с геометрической прогрессией
        double equation(); // интеграл от f(x) = (ch(sqrt(x))-1)/x
        double Taylor(double x, int k); // Тейлор ch(sqrt(x))
};

#endif // INTEGRAlL