//
// Created by 神林楽人 on 2020/07/13.
//

#include "PowerIterationMethod.h"

#include <cmath>

PowerIterationMethod::PowerIterationMethod() = default;

PowerIterationMethod::PowerIterationMethod(Matrix A) {
    this->A = A;
    Dimension dim = A.get_dim();
    dim.reset(dim.row(), 1);
    this->x = Vector(dim);
    this->x_old = Vector(dim);
    this->r = 0;
    this->r_old = 0;
    this->epsilon = 1.0e-8;
    for(int i = 1; i <= x.get_dim().row(); i++){
        x.set(i, 1);
        x_old.set(i, 1);
    }
}

void PowerIterationMethod::set_initial_vector(Vector initial_vector) {
    this->x = initial_vector;
    this->x_old = initial_vector;
}

void PowerIterationMethod::set_convergense_condition(double epsilon) {
    this->epsilon = epsilon;
}

void PowerIterationMethod::run(int max_iteration, bool debug_mode) {
    bool converged = false;
    int  c = 0;
    for(int m = 0; m < max_iteration; m++){
        x_old = x;
        r_old = r;
        x_old.normalize();
        x = A * x_old;
        int l = 1;
        while(x_old.at(l) == 0){
            l++;
        }
        r = x.at(l) / x_old.at(l);
        if((abs(r - r_old) / abs(r)) < epsilon){
            converged = true;
            break;
        }
        c++;
    }
    if(!converged){
        printf("Did not converged in %d times iterations.\n", max_iteration);
    }
    else {
        if(debug_mode){
            printf("Converged in %d times iterations.\n", c);
            printf("Max absolute eigenvalue is rambda = %1.8e\n", abs(r));
            printf("Eigenvector is below...\n");
            x.show8d("Eigenvector x");
        }
    }
}


