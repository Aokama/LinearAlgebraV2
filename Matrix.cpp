//
// Created by 神林楽人 on 2020/07/13.
//

#include "Matrix.h"

#include "Dimension.h"

Matrix::Matrix() = default;

Matrix::Matrix(std::vector<std::vector<double> > arrays) {
    this->matrix =  arrays;
    this->dimension = Dimension(arrays.size(), arrays.at(0).size());
}

Matrix::Matrix(Dimension dimension) {
    this->matrix = std::vector<std::vector<double>>(dimension.row(), std::vector<double>(dimension.col()));
    this->dimension = dimension;
}

Dimension Matrix::get_dim() {
    return dimension;
}

double Matrix::at(int i, int j) {
    if(!dimension.include(i, j)) {
        printf("\n(%d, %d) is not referencable because the matrix dimension is below.\n",  i, j);
        dimension.show("the matrix");
        printf("Function returned 0.\n");
        return 0;
    }
    return matrix[i - 1][j - 1];
}

void Matrix::set(int i, int j, double value) {
    if(!dimension.include(i, j)) {
        printf("\n(%d, %d) is not referencable because the matrix dimension is below.\n",  i, j);
        dimension.show("the matrix");
    }
    matrix[i - 1][j - 1] = value;
}

Vector Matrix::operator*(Vector right) {
    if(!dimension.can_multiply(right.get_dim())){
        printf("Unable to multiply.\n");
        return Vector();
    }
    Vector result = Vector(right.get_dim());
    for(int i = 1; i <= dimension.row(); i++){
        double sum = 0;
        for(int k = 1; k <= dimension.col(); k++){
            sum += at(i, k) * right.at(k);
        }
        result.set(i, sum);
    }
    return result;
}

