// **************************************************************************
//  File       [Maximum_Planar_Subset.cpp]
//  Author     [I-An Hou]
//  Synopsis   [Supporting program of 2025 spring Algorithm PA2]
// **************************************************************************
#include "Maximum_Planar_Subset.h"
#include <algorithm>

MPSolver::MPSolver(int totalVertices, const std::vector<std::pair<int, int>>& chords)
    : totalVertices(totalVertices)
{
    match = new int[totalVertices];
    std::fill(match, match + totalVertices, -1);

    for (const auto& p : chords) {
        match[p.first] = p.second;
        match[p.second] = p.first;
    }

    // 預先配置一維三角形陣列空間
    int tri_size = (totalVertices * (totalVertices + 1)) / 2;
    dp = new int[tri_size]();
}

MPSolver::~MPSolver() {
    delete[] match;
    delete[] dp;
}

inline int& MPSolver::DP(int i, int j) {
    return dp[((2 * totalVertices - i + 1) * i) / 2 + (j - i)];
}

void MPSolver::computeDP() {
    for (int len = 1; len < totalVertices; ++len) {
        for (int i = 0; i + len < totalVertices; ++i) {
            int j = i + len;
            int k = match[j];
            if (k < i || k > j) {
                DP(i, j) = DP(i, j - 1);
            } else if (k == i) {
                DP(i, j) = DP(i + 1, j - 1) + 1;
            } else {
                DP(i, j) = std::max(
                    DP(i, j - 1),
                    DP(i, k - 1) + DP(k + 1, j - 1) + 1
                );
            }
        }
    }
}

void MPSolver::constructAnswer(int i, int j, std::vector<std::pair<int, int>>& ans) {
    if (i > j || DP(i, j) == 0) return;

    int k = match[j];
    if (k < i || k > j) {
        constructAnswer(i, j - 1, ans);
    } else if (k == i) {
        ans.emplace_back(i, j);
        constructAnswer(i + 1, j - 1, ans);
    } else {
        if (DP(i, j) == DP(i, j - 1)) {
            constructAnswer(i, j - 1, ans);
        } else {
            constructAnswer(i, k - 1, ans);
            ans.emplace_back(k, j);
            constructAnswer(k + 1, j - 1, ans);
        }
    }
}

std::vector<std::pair<int, int>> MPSolver::solve() {
    computeDP();
    std::vector<std::pair<int, int>> ans;
    constructAnswer(0, totalVertices - 1, ans);
    return ans;
}


