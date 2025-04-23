
// **************************************************************************
//  File       [main.cpp]
//  Author     [I-An Hou]
//  Synopsis   [The main program of 2025 spring Algorithm PA2]
// **************************************************************************


#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include "../lib/tm_usage.h"
#include "Maximum_Planar_Subset.h"
using namespace std;
#define ll long long

void helpMessage() {
    cout << "Input format error. Please use the correct format." << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        helpMessage();
        return EXIT_FAILURE;
    }

    CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;

    fstream fin(argv[1]);
    if (!fin) {
        cerr << "Failed to open input file!" << endl;
        return EXIT_FAILURE;
    }
    else cout << "Input file: " << argv[1] << endl;

    fstream fout;
    fout.open(argv[2], ios::out);

    
    int totalVertices;
    fin >> totalVertices;
    
    if (totalVertices % 2 != 0 || totalVertices > 180000) {
        helpMessage();
        return EXIT_FAILURE;
    }

    vector<pair<int, int>> chords;
    int n = totalVertices / 2;
    for (int i = 0; i < n; ++i) {
        int start, end;
        if (!(fin >> start)) {
            cout << "Error: start vertex not found." << endl;
            helpMessage();
            break;
        }
        if (!(fin >> end)) {
            cout << "Error: end vertex not found." << endl;
            helpMessage();
            break;
        }
        if (start < 0 || end < 0 || start > totalVertices || end > totalVertices) {
            helpMessage();
            return EXIT_FAILURE;
        }
        chords.emplace_back(start, end);
    }

    tmusg.periodStart();
    
    vector<pair<int, int>> ans = Maximum_Planar_Subset(chords, totalVertices);
    fout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        fout << ans[i].first << " " << ans[i].second << endl;
    }
    tmusg.getPeriodUsage(stat);
    cout <<"The total CPU time: " << (stat.uTime + stat.sTime) / 1000.0 << "ms" << endl; // print CPU time
    cout <<"memory: " << stat.vmPeak << "KB" << endl; // print peak memory

    fin.close();
    fout.close();

    return EXIT_SUCCESS;
}