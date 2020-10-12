//
// Created by eric on 2020-10-11.
//
#include "pagerank.hpp"

PageRank::PageRank(vector<double> v) : Matrix(v) {
    p = 0.85;
    setImportance();
    setEmptyColumn();
}

void PageRank::setImportance() {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            sums[i] += mat[i][j];
        }
    }
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            if (sums[i] != 0) {
                mat[i][j] /= sums[i];
            }
        }
    }
}

void PageRank::setEmptyColumn() {
    vector<int> columns;
    vector<bool> allZero;
    for (int i = 0; i < mat.size(); i++) {
        bool empt = true;
        for (int j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] != 0)
                empt = false;
                return;
        }
        if (empt) {
            columns.push_back(i);
        }
    }
    for (int i = 0; i < columns.size(); i++) {
        for (int j = 0; j < mat[columns[i]].size(); j++) {
            mat[columns[i]][j] = 0.25;
        }
    }
}

void PageRank::transitionM() {

}

void PageRank::rank() {

}

ostream &operator<<(ostream &os, const PageRank &page) {
    for (int i = 0; i < page.mat.size(); i++) {
        for (int j = 0; j < page.mat[0].size(); j++) {
            os << page.mat[i][j]<< " ";
        }
        os << endl;
    }
    os << endl;
    return os;
}
