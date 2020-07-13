//
// Created by 神林楽人 on 2020/07/13.
//

#ifndef LINEARALGEBRA_MATRIX_H
#define LINEARALGEBRA_MATRIX_H

#include "Dimension.h"

#include "Vector.h"
#include <vector>

class Matrix {

private:
    std::vector<std::vector<double>> matrix;
    Dimension dimension;

public:
    Matrix();
    Matrix(std::vector<std::vector<double>> arrays);
    Matrix(Dimension dimension);
    Dimension get_dim();
    double at(int i, int j);
    void set(int i, int j, double value);

    Vector operator * (Vector right);
};


#endif //LINEARALGEBRA_MATRIX_H
