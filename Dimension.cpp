//
// Created by 神林楽人 on 2020/07/13.
//

#include "Dimension.h"

#include <cstdio>

Dimension::Dimension() = default;

Dimension::Dimension(int row_dim, int col_dim){
    this->row_dimension = row_dim;
    this->col_dimension = col_dim;
}

int Dimension::row() const {
    return row_dimension;
}

int Dimension::col() const {
    return col_dimension;
}

void Dimension::reset(int row_dim, int col_dim) {
    this->row_dimension = row_dim;
    this->col_dimension = col_dim;
}

bool Dimension::include(int i, int j) const {
    return i <= row_dimension && j <= col_dimension;
}

bool Dimension::equals(Dimension comparer) const {
    return row_dimension == comparer.row() && col_dimension == comparer.col();
}

bool Dimension::is_vector() {
    return row_dimension == 1;
}

bool Dimension::can_multiply(Dimension comparer) const {
    return col_dimension  == comparer.row();
}

void Dimension::show(const char *name) const {
    printf("Dimension of %s is (%d x %d).\n", name, row_dimension, col_dimension);
}


