// **************************************************************************
//  File       [Maximum_Planar_Subset.cpp]
//  Author     [I-An Hou]
//  Synopsis   [Supporting program of 2025 spring Algorithm PA2]
// **************************************************************************

#include "Maximum_Planar_Subset.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long
using namespace std;

vector<pair<int, int>> Maximum_Planar_Subset(vector<pair<int, int>> chords, int totalVertices){
    
    vector<int> match(totalVertices, -1);

    for (int i = 0; i < chords.size(); ++i) {    // contructing the pair array
        match[chords[i].first] = chords[i].second;
        match[chords[i].second] = chords[i].first;
    }

    // checking the match array
    // cout << "match array: " << endl;
    // for (int i = 0; i < match.size(); ++i) {
    //     cout << match[i] << " ";
    // }

    vector<vector<int>> dp;     // triangular matrix
    dp.reserve(totalVertices);

    for (int i = 0; i < totalVertices; ++i) dp.emplace_back(totalVertices - i, 0);
    
    for (int len = 1; len < totalVertices; ++len) {
        for (int i = 0; i < totalVertices - len; ++i) {
            int j = i + len;
            int k = match[j];
            if (k < i || k > j) dp[i][j - i] = dp[i][j - 1 - i];
            else if (k == i) dp[i][j - i] = dp[i + 1][j - 1 - (i + 1)] + 1;
            else dp[i][j - i] = max(dp[i][j - 1 - i], dp[k + 1][j - 1 - (k + 1)] + 1);
        }
    }

    vector<pair<int, int>> ans;
    return construct_ans(dp, match, 0, totalVertices - 1, ans);
}

vector<pair<int, int>> construct_ans(const vector<vector<int>>& dp, const vector<int>& match, int start, int end, vector<pair<int, int>>& ans) {
    
    if (start >= end) {
        sort(ans.begin(), ans.end());
        return ans;
    }
    int k = match[end];
    if (k < start || k > end) {
        construct_ans(dp, match, start, end - 1, ans);
    } else if (k == start) {
        ans.emplace_back(start, end);
        construct_ans(dp, match, start + 1, end - 1, ans);
    } else {
        int a = dp[start][end - 1 - start];
        int b = dp[k + 1][end - 1 - (k + 1)] + 1;
        if (dp[start][end - start] == a) {
            construct_ans(dp, match, start, end - 1, ans);
        } else {
            construct_ans(dp, match, start, k - 1, ans);
            ans.emplace_back(k, end);
            construct_ans(dp, match, k + 1, end - 1, ans);
        }
    }
    return ans;
}

