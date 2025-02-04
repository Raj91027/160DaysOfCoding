# 160 Days of Problem Solving

This repository contains various C++ programs to practice and implement different algorithms and data structures. 
The programs are organized into different directories based on the type of problem they solve, such as Array, Matrix, Searching, Sorting, and String.

## Directory Structure
.
├── .dist/
├── .vscode/
│   └── settings.json
├── Array/
│   ├── Day1-SecondLargestNumber.cpp
│   ├── Day10-MaximumSubArraySum.cpp
│   ├── Day11-MaximumSubarrayProduct.cpp
│   ├── Day12-MaximumCircularSubArraySum.cpp
│   ├── Day13-SmallestMissingPositiveNumber.cpp
│   ├── Day2-MoveAllZeroesToEnd.cpp
│   ├── Day3-ReverseArray.cpp
│   ├── Day4-RotateArray.cpp
│   ├── Day5-NextPermutation.cpp
│   ├── Day6-MajorityElement-II.cpp
│   ├── Day7-StockBuyandSell.cpp
│   ├── Day8-StockBuyAndSell-II.cpp
│   ├── Day9-MinimizeHeight-II.cpp
├── Matrix/
│   ├── Day36-PrintSpiralMatrix.cpp
│   ├── Day37-RotateMatrixBy90Degree.cpp
│   ├── Day38-SearchInSortedMatrix.cpp
│   └── Day39-SearchInARowWiseSortedMatrix.cpp
├── Searching/
├── Sorting/
└── String/
## How to Run

1. Clone the repository:
    ```sh
    git clone https://github.com/your-username/your-repo-name.git
    cd your-repo-name
    ```

2. Open the project in Visual Studio Code:
    ```sh
    code .
    ```

3. Compile and run any C++ file using the following commands:
    ```sh
    g++ -o output Array/Day1-SecondLargestNumber.cpp
    ./output
    ```

## Example

Here is an example of how to search for an element in a row-wise sorted matrix:

```cpp
#include <iostream>
#include <vector>

using namespace std;

bool matSearch(vector<vector<int>> &mat, int x) {
    int n = mat.size();
    if (n == 0) return false;
    int m = mat[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == x) return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {{3, 4, 9},
                               {2, 5, 6},
                               {9, 25, 27}};
    int x = 9;
    if(matSearch(mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}
