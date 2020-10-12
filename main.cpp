#include <iostream>
#include <fstream>
#include <string>
#include "matrix.hpp"
#include "pagerank.hpp"

int main() {
    /*vector<double> v = {1, 2, 3, 4};
    vector<double> v2 = {2,3,4,5};
    Matrix mat(v);
    Matrix mat2(2, 1);
    Matrix mat4(v2);
    mat2.set_value(1, 0, 3);
    mat2.set_value(0, 0, 1);
    Matrix mat3 = mat * mat2;
    cout << mat2;
    cout << mat3;*/

    ifstream text("connectivity.txt");
    string line;
    vector<double> v3;
    while (getline(text, line)) {
        double hold;
        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line.at(i))) {
                hold = line.at(i) - '0';
                v3.push_back(hold);
            }
        }
    }
    cout << v3.size() << endl;
    PageRank p(v3);
    cout << p;
    return 0;
}
