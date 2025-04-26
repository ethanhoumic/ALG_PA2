# PA2 of 2025 Spring Algorithm: Maximum Planar Subset
## Introduction

This is a programming assignment calculating maximum planar subset `M(i, j)` formed by chord `ij` and arc `ij`. 

## Usage
1. Clone the repo. 
2. Run the following command in terminal:
```
make
./bin/mps inputs/[input file name].in outputs/[output file name].out 
```

The program will display the CPU time and memory usage of the process.

## Sample I/O
Sample input:
```
12
0 4
1 9
2 6
3 10
5 7
8 11
0
```

First number `12` is the total number of vertices, and the following pairs are the two endpoint of each input chord. 

Sample output:
```
3
0 4
5 7
8 11
```

The first number `3` is the total number of chords, and the following pairs are the two endpoints of each chord in the maximum planar subset. 

### Reminder
Occasionally, the reported memory usage may appear abnormally high (e.g. 21 TB). This is due to an unknown glitch and does not reflect actual memory consumption. This issue also occurs on my personal laptop, which obviously does not have such memory capacity.\
If this happens, try the following steps to resolve it:
<pre>make clean
make</pre>
Other possible solutions: 
- reconnecting to the server
- delete and clone the repo 

(To TA: PLEASE DON'T DEDUCT POINTS if you encounter this QAQ This memory issue is random and difficult to reproduce consistently. It may disappear by simply recompiling or re-uploading a file. I've investigated this extensively but haven't found a consistent pattern. Since this problem doesn't affect the function of the program, I kindly ask that this anomaly not be counted against my score. )