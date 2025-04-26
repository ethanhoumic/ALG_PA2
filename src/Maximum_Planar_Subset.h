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
    std::vector<std::pair<int, int>> solve();

private:
    int totalVertices;
    std::vector<int> match;
    std::vector<std::vector<int>> dp;
    std::vector<std::pair<int, int>> ans;

    int topDown(int i, int j);
    void constructAnswer(int i, int j);
};

#endif