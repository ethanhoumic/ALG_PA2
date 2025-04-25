// **************************************************************************
//  File       [Maximum_Planar_Subset.h]
//  Author     [I-An Hou]
//  Synopsis   [Header of 2025 spring Algorithm PA2]
// **************************************************************************
// MaximumPlanarSubsetSolver.h
#ifndef MAXIMUM_PLANAR_SUBSET_SOLVER_H
#define MAXIMUM_PLANAR_SUBSET_SOLVER_H

#include <vector>
#include <utility>

class MaximumPlanarSubsetSolver {
public:
    // Constructor: 傳入總點數和所有弦的配對
    MaximumPlanarSubsetSolver(int totalVertices, const std::vector<std::pair<int, int>>& chords);

    // 取得最大planar subset的結果
    std::vector<std::pair<int, int>> getSolution();

private:
    int n;  // 總點數
    std::vector<int> match;  // 記錄每個點配對到哪一點
    std::vector<std::vector<int>> dp;  // 三角形DP表
    std::vector<std::vector<bool>> used;  // 記錄是否取用某一條弦
    std::vector<std::pair<int, int>> result;  // 最後的答案

    void computeDP();         // 建立DP表
    void reconstruct(int i, int j);  // 從DP表回推答案
};

#endif // MAXIMUM_PLANAR_SUBSET_SOLVER_H
