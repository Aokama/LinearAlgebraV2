//
// Created by 神林楽人 on 2020/07/13.
//

#ifndef LINEARALGEBRA_DIMENSION_H
#define LINEARALGEBRA_DIMENSION_H


class Dimension{

private:
    int row_dimension{};
    int col_dimension{};

public:
    Dimension();
    Dimension(int row_dim, int col_dim);

    int row() const;
    int col() const;

    void reset(int row_dim, int col_dim);

    bool include(int i, int j) const;

    bool equals(Dimension comparer) const;
    bool is_vector();

    bool can_multiply(Dimension comparer) const;

    void show(const char name[]) const;
};


#endif //LINEARALGEBRA_DIMENSION_H
