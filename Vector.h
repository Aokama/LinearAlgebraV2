//
// Created by 神林楽人 on 2020/07/13.
//

#ifndef LINEARALGEBRA_VECTOR_H
#define LINEARALGEBRA_VECTOR_H

#include  "Dimension.h"
#include <vector>

class Vector {
private:
    std::vector<double> vector;
    Dimension dimension;
public:
    Vector();
    Vector(const std::vector<double>& vector);
    Vector(Dimension dimension);

    Dimension get_dim();

    double at(int index);
    void set(int index, double value);

    double norm(int n);
    void scale(double factor);
    void normalize();

    Vector operator + (Vector right);
    Vector operator - (Vector right);

    void show(const char name[]);
    void show8d(const char name[]);
};


#endif //LINEARALGEBRA_VECTOR_H
