// **************************************************************************
//  File       [Maximum_Planar_Subset.h]
//  Author     [I-An Hou]
//  Synopsis   [Header of 2025 spring Algorithm PA2]
// **************************************************************************

#ifndef MAXIMUM_PLANAR_SUBSET_H
#define MAXIMUM_PLANAR_SUBSET_H
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> Maximum_Planar_Subset(vector<pair<int, int>> chords, int n);
vector<pair<int, int>> construct_ans(const vector<vector<int>>& dp, const vector<int>& match, int start, int end, vector<pair<int, int>>& ans);


#endif // MAXIMUM_PLANAR_SUBSET_H