#include <iostream>
#include "matrix.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<double> v = {1, 2, 3, 4};
    vector<double> v2 = {2,3,4,5};
    Matrix mat(v);
    Matrix mat2(v2);
    Matrix mat3 = mat * mat2;
    cout << mat3;

    return 0;
}
