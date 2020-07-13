//
// Created by 神林楽人 on 2020/07/13.
//

#include "Vector.h"

#include "Dimension.h"
#include <vector>
#include <cstdio>
#include <cmath>

Vector::Vector() = default;
Vector::Vector(const std::vector<double>& array){
    this->vector = array;
    this->dimension = Dimension(array.size(), 1);
}

Vector::Vector(Dimension dimension){
    if(dimension.col() != 1){
        printf("Column dimension %d cannot be vector.\n", dimension.col());
    }
    else{
        vector = std::vector<double>(dimension.row());
        this->dimension = dimension;
    }
}

Dimension Vector::get_dim(){
    return dimension;
}

double Vector::at(int index){
    if(dimension.row() < index){
        printf("You cannot assign index %d, this vector is %d-dimensional.\n", index, dimension.row());
        return -1;
    }
    return vector[index - 1];
}

void Vector::set(int index, double value){
    if(dimension.row() < index){
        printf("You cannot assign index %d, this vector is %d-dimensional.\n", index, dimension.row());
    }
    vector[index - 1] = value;
}

double Vector::norm(int n){
    if(n == 0){
        double max = 0;
        for(int i = 1; i <= dimension.row(); i++){
            if(abs(at(i)) > max){
                max = abs(at(i));
            }
        }
        return max;
    }
    else{
        double sum = 0;
        for(int i = 1; i <= dimension.row(); i++){
            sum += pow(abs(at(i)), n);
        }
        return pow(sum, 1 / n);
    }
}

void Vector::scale(double factor){
    for(int i = 1; i <= dimension.row(); i++){
        set(i, at(i) * factor);
    }
}

void Vector::normalize(){
    double factor = norm(2);
    scale(1 / factor);
}

Vector Vector::operator + (Vector right){
    if(!dimension.equals(right.get_dim())){
        printf("Unable to add vector with a different dimension.\n");
        return Vector();
    }
    else{
        Vector result = Vector(dimension);
        for(int i = 1; i <= dimension.row(); i++){
            result.set(i, at(i) + right.at(i));
        }
        return result;
    }
}
Vector Vector::operator - (Vector right){
    if(!dimension.equals(right.get_dim())){
        printf("Unable to subtract vector with a different dimension.\n");
        return Vector();
    }
    else{
        Vector result = Vector(dimension);
        for(int i = 1; i <= dimension.row(); i++){
            result.set(i, at(i) - right.at(i));
        }
        return result;
    }
}

void Vector::show(const char name[]){
    printf("======== %s ========\n", name);
    for(int i = 1; i <= dimension.row(); i++){
        printf("%1.2e\n", at(i));
    }
    printf("======== %s ========\n", name);
}

void Vector::show8d(const char name[]){
    printf("======== %s ========\n", name);
    for(int i = 1; i <= dimension.row(); i++){
        printf("%1.8e\n", at(i));
    }
    printf("======== %s ========\n", name);
}