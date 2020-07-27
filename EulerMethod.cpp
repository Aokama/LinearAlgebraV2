//
// Created by 神林楽人 on 2020/07/27.
//

#include "EulerMethod.h"
#include "Matrix.h"

#include <math.h>

EulerMethod::EulerMethod() = default;

EulerMethod::EulerMethod(double (*du)(double, double), int max_count) {
    this->f = du;
    this->mat_y = Matrix(Dimension(max_count + 1, 2));
    this->mat_y.set(1, 2, 0);
}

void EulerMethod::set_initial_y(double y) {
    this->mat_y.set(1, 2, y);
}

void EulerMethod::set_range_t(double min, double max) {
    this->min_t = min;
    this->max_t = max;
}

void EulerMethod::run(int max_iteration, bool debug_mode) {
    this->mat_y.set(1, 1, min_t);
    double h = (max_t - min_t) / max_iteration;
    for(int i = 1; i <= max_iteration; i++){
        mat_y.set(i + 1, 1, min_t + h * i);
        mat_y.set(i + 1, 2, mat_y.at(i, 2) + h * f(min_t + h * (i - 1), mat_y.at(i, 2)));
    }
    if(debug_mode){
        mat_y.show10d("(Col 1 = t(n), Col 2 = y(n))");
    }
}

Matrix EulerMethod::get_error_matrix(double (*func)(double)) {
    Matrix mat = mat_y;
    for(int i = 1; i <= mat.get_dim().row(); i++){
        mat.set(i, 2, abs(mat.at(i, 2) - func(mat.at(i, 1))));
    }
    return mat;
}

Matrix EulerMethod::get_calculated_matrix() {
    return this->mat_y;
}


