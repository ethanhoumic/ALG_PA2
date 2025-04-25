// **************************************************************************
//  File       [Maximum_Planar_Subset.cpp]
//  Author     [I-An Hou]
//  Synopsis   [Supporting program of 2025 spring Algorithm PA2]
// **************************************************************************
#include "Maximum_Planar_Subset.h"
#include <algorithm>

MaximumPlanarSubsetSolver::MaximumPlanarSubsetSolver(int totalVertices, const std::vector<std::pair<int, int>>& chords)
    : n(totalVertices), match(totalVertices, -1), dp(totalVertices), used(totalVertices) {

    for (const auto& chord : chords) {
        match[chord.first] = chord.second;
        match[chord.second] = chord.first;
    }

    for (int i = 0; i < n; ++i) {
        dp[i] = std::vector<int>(n - i, 0);
        used[i] = std::vector<bool>(n - i, false);
    }

    computeDP();
}

void MaximumPlanarSubsetSolver::computeDP() {
    for (int len = 1; len < n; ++len) {
        for (int i = 0; i < n - len; ++i) {
            int j = i + len;
            int k = match[j];
            if (k < i || k > j) {
                dp[i][len] = dp[i][len - 1];
            } else {
                int candidate = (k == i ? 0 : dp[i][k - 1 - i]) + (k + 1 > j - 1 ? 0 : dp[k + 1][j - 1 - (k + 1)]) + 1;
                if (candidate > dp[i][len - 1]) {
                    dp[i][len] = candidate;
                    used[i][len] = true;
                } else {
                    dp[i][len] = dp[i][len - 1];
                }
            }
        }
    }
}

void MaximumPlanarSubsetSolver::reconstruct(int i, int j) {
    while (i < j && dp[i][j - i] > 0) {
        if (!used[i][j - i]) {
            --j;
        } else {
            int k = match[j];
            result.emplace_back(k, j);
            if (k - 1 >= i) reconstruct(i, k - 1);
            i = k + 1;
            --j;
        }
    }
}

std::vector<std::pair<int, int>> MaximumPlanarSubsetSolver::getSolution() {
    result.clear();
    reconstruct(0, n - 1);
    return result;
}