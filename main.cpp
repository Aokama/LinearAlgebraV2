#include "EulerMethod.h"

double f(double t, double u){
    return u * (1 - (u / 10));
}

int main() {
    const int MAX_ITER = 100;

    EulerMethod method = EulerMethod(f, MAX_ITER);
    method.set_initial_y(1);
    method.set_range_t(0, 8);

    method.run(MAX_ITER, true);

    return 0;
}
