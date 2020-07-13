#include "Matrix.h"
#include "PowerIterationMethod.h"

int main() {

    Matrix A = Matrix({
        {6,5,4,3,2,1},
        {5,5,4,3,2,1},
        {4,4,4,3,2,1},
        {3,3,3,3,2,1},
        {2,2,2,2,2,1},
        {1,1,1,1,1,1}
    });

    /*
    Matrix B = Matrix({
        {1,1,0},
        {1,2,1},
        {2,5,3}
    });
     */

    PowerIterationMethod pim = PowerIterationMethod(A);
    pim.set_convergense_condition(1.0e-8);
    pim.run(50, true);


    return 0;
}
