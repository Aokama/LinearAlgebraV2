//
// Created by 神林楽人 on 2020/07/13.
//

#ifndef LINEARALGEBRA_POWERITERATIONMETHOD_H
#define LINEARALGEBRA_POWERITERATIONMETHOD_H

#include "Matrix.h"
#include "Vector.h"

class PowerIterationMethod {
private:
    Matrix A;
    Vector x;
    Vector x_old;
    double r;
    double r_old;
    double epsilon;
public:
    PowerIterationMethod();
    PowerIterationMethod(Matrix A);
    void set_initial_vector(Vector initial_vector);
    void set_convergense_condition(double epsilon);
    void run(int max_iteration, bool debug_mode);
};


#endif //LINEARALGEBRA_POWERITERATIONMETHOD_H
