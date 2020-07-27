#include "EulerMethod.h"

#include <math.h>

double f(double t, double u){
    return u * (1 - (u / 10));
}

double true_f(double t){
    return 10 / (1 + (9 * exp(-t)));
}

int main() {

    //When h = (8 / 50 = 0.16) START
    const int MAX_ITER_50 = 50;

    EulerMethod method = EulerMethod(f, MAX_ITER_50);
    method.set_initial_y(1);
    method.set_range_t(0, 8);
    method.run(MAX_ITER_50, false);

    Matrix mat_error = method.get_error_matrix(true_f);
    Matrix mat = method.get_calculated_matrix();

    printf("U(N = 50)  =  %1.2e\n", mat.at(MAX_ITER_50 + 1, 2));
    printf("|U(N) - U(T)| = %1.2e\n", mat_error.at(MAX_ITER_50 + 1, 2));
    //When h = (8 / 50 = 0.16) END

    //When h = (8 / 100 = 0.08) START
    const int MAX_ITER_100 = 100;

    method = EulerMethod(f, MAX_ITER_100);
    method.set_initial_y(1);
    method.set_range_t(0, 8);
    method.run(MAX_ITER_100, true);

    mat_error = method.get_error_matrix(true_f);
    mat = method.get_calculated_matrix();

    printf("U(N = 100)  =  %1.2e\n", mat.at(MAX_ITER_100 + 1, 2));
    printf("|U(N) - U(T)| = %1.2e\n", mat_error.at(MAX_ITER_100 + 1, 2));
    //When h = (8 / 100 = 0.08) END

    //When h = (8 / 200 = 0.04) START
    const int MAX_ITER_200 = 200;

    method = EulerMethod(f, MAX_ITER_200);
    method.set_initial_y(1);
    method.set_range_t(0, 8);
    method.run(MAX_ITER_200, false);

    mat_error = method.get_error_matrix(true_f);
    mat = method.get_calculated_matrix();

    printf("U(N = 200)  =  %1.2e\n", mat.at(MAX_ITER_200 + 1, 2));
    printf("|U(N) - U(T)| = %1.2e\n", mat_error.at(MAX_ITER_200 + 1, 2));
    //When h = (8 / 200 = 0.04) END

    //When h = (8 / 400 = 0.02) START
    const int MAX_ITER_400 = 400;

    method = EulerMethod(f, MAX_ITER_400);
    method.set_initial_y(1);
    method.set_range_t(0, 8);
    method.run(MAX_ITER_400, false);

    mat_error = method.get_error_matrix(true_f);
    mat = method.get_calculated_matrix();

    printf("U(N = 400)  =  %1.2e\n", mat.at(MAX_ITER_400 + 1, 2));
    printf("|U(N) - U(T)| = %1.2e\n", mat_error.at(MAX_ITER_400 + 1, 2));
    //When h = (8 / 400 = 0.02) END

    return 0;
}
