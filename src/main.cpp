
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

void helpMessage(int errorCode) {
    if (errorCode == 0) cout << "Error: incorrect # of Arguements. " << endl;
    else if (errorCode == 1) cout << "Error: Failed to open input file." << endl;
    else if (errorCode == 2) cout << "Error: Invalid total # of vertices. " << endl;
    else if (errorCode == 3) cout << "Error: Start vertex not found. " << endl;
    else if (errorCode == 4) cout << "Error: End vertex not found. " << endl;
    else if (errorCode == 5) cout << "Error: Invalid vertex. " << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        helpMessage(0);
        return EXIT_FAILURE;
    }

    CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;

    fstream fin(argv[1]);
    if (!fin) {
        helpMessage(1);
        return EXIT_FAILURE;
    }
    // else cout << "Input file: " << argv[1] << endl;

    fstream fout;
    fout.open(argv[2], ios::out);

    
    int totalVertices;
    fin >> totalVertices;
    
    if (totalVertices % 2 != 0 || totalVertices > 180000) {
        helpMessage(2);
        return EXIT_FAILURE;
    }

    vector<pair<int, int>> chords;
    int n = totalVertices / 2;
    for (int i = 0; i < n; ++i) {
        int start, end;
        if (!(fin >> start)) {
            helpMessage(3);
            break;
        }
        if (!(fin >> end)) {
            helpMessage(4);
            break;
        }
        if (start < 0 || end < 0 || start > totalVertices || end > totalVertices) {
            helpMessage(5);
            return EXIT_FAILURE;
        }
        chords.emplace_back(start, end);
    }
    
    MPSolver solver(totalVertices, chords);
    std::vector<std::pair<int, int>>result = solver.solve();
    fout << result.size() << endl;
    for (int i = 0; i < result.size(); ++i) {
        fout << result[i].first << " " << result[i].second << endl;
    }
    tmusg.getPeriodUsage(stat);
    cout <<"The total CPU time: " << (stat.uTime + stat.sTime) / 1000.0 << "ms" << endl; // print CPU time
    cout <<"memory: " << stat.vmPeak << "KB" << endl; // print peak memory

    fin.close();
    fout.close();

    return EXIT_SUCCESS;
}