//
// Created by 神林楽人 on 2020/07/27.
//

#ifndef LINEARALGEBRA_EULERMETHOD_H
#define LINEARALGEBRA_EULERMETHOD_H

#include "Matrix.h"


class EulerMethod {
private:
    double (*f)(double, double){};
    Matrix mat_y;
    double min_t{};
    double max_t{};
public:
    EulerMethod();
    EulerMethod(double (*du)(double, double), int max_count);
    void set_initial_y(double y);
    void set_range_t(double min, double max);
    void run(int max_iteration, bool debug_mode);
    Matrix get_error_matrix(double (*func)(double));
    Matrix get_calculated_matrix();
};


#endif //LINEARALGEBRA_EULERMETHOD_H
