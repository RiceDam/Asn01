//
// Created by eric on 2020-10-11.
//
#ifndef ASN01_PAGERANK_HPP
#define ASN01_PAGERANK_HPP


#include "matrix.hpp"

class PageRank: public Matrix {
private:
    vector<int> sums;
    double p;
public:
    PageRank(vector<double> v);
    void setImportance();
    void setEmptyColumn();
    void transitionM();
    void rank();
    friend ostream& operator <<(ostream& os, const PageRank& page);
};


#endif //ASN01_PAGERANK_HPP
