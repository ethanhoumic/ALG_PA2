// **************************************************************************
//  File       [Maximum_Planar_Subset.h]
//  Author     [I-An Hou]
//  Synopsis   [Header of 2025 spring Algorithm PA2]
// **************************************************************************
#ifndef MAXIMUM_PLANAR_SUBSET_H
#define MAXIMUM_PLANAR_SUBSET_H

#include <vector>
#include <utility>

class MPSolver {
public:
    MPSolver(int totalVertices, const std::vector<std::pair<int, int>>& chords);
    ~MPSolver();

    std::vector<std::pair<int, int>> solve();

private:
    int totalVertices;
    int* match;
    int* dp;

    inline int& DP(int i, int j);
    void computeDP();
    void constructAnswer(int i, int j, std::vector<std::pair<int, int>>& ans);
};

#endif // MAXIMUM_PLANAR_SUBSET_H
