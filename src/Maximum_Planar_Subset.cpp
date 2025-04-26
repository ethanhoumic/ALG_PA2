// **************************************************************************
//  File       [Maximum_Planar_Subset.cpp]
//  Author     [I-An Hou]
//  Synopsis   [Supporting program of 2025 spring Algorithm PA2]
// **************************************************************************
#include "Maximum_Planar_Subset.h"
#include <algorithm>

MPSolver::MPSolver(int totalVertices, const std::vector<std::pair<int, int>>& chords)
    : totalVertices(totalVertices), match(totalVertices, -1)
{
    for (const auto& p : chords) {
        match[p.first] = p.second;
        match[p.second] = p.first;
    }

    // 初始化三角形 dp 陣列
    dp.reserve(totalVertices);
    for (int i = 0; i < totalVertices; ++i)
        dp.emplace_back(totalVertices - i, -1); // 用 -1 表示尚未計算
}

int MPSolver::topDown(int i, int j) {
    if (i >= j) return 0;
    int len = j - i;
    if (dp[i][len] != -1) return dp[i][len];

    int k = match[j];
    if (k < i || k > j) {
        dp[i][len] = topDown(i, j - 1);
    } else if (k == i) {
        dp[i][len] = topDown(i + 1, j - 1) + 1;
    } else {
        int left = topDown(i, k - 1);
        int right = topDown(k + 1, j - 1);
        dp[i][len] = std::max(topDown(i, j - 1), left + right + 1);
    }
    return dp[i][len];
}

void MPSolver::constructAnswer(int i, int j) {
    if (i >= j || dp[i][j - i] == 0) return;

    int k = match[j];
    if (k < i || k > j) {
        constructAnswer(i, j - 1);
    } else if (k == i) {
        ans.emplace_back(i, j);
        constructAnswer(i + 1, j - 1);
    } else {
        int left = topDown(i, k - 1);
        int right = topDown(k + 1, j - 1);
        if (dp[i][j - i] == dp[i][j - 1 - i]) {
            constructAnswer(i, j - 1);
        } else {
            constructAnswer(i, k - 1);
            ans.emplace_back(k, j);
            constructAnswer(k + 1, j - 1);
        }
    }
}

std::vector<std::pair<int, int>> MPSolver::solve() {
    topDown(0, totalVertices - 1);
    constructAnswer(0, totalVertices - 1);
    return ans;
}




