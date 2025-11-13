#include <iostream>
#include <vector>
using namespace std;

int findPathsWithCost(vector<vector<int>>& grid, int r, int c, int remainingCost, vector<vector<vector<int>>>& cache) {
    
    if (r < 0 || c < 0) return 0;

    if (r == 0 && c == 0) return (grid[0][0] == remainingCost) ? 1 : 0;

    if (cache[r][c][remainingCost] != -1)
        return cache[r][c][remainingCost];

    int pathsFromAbove = findPathsWithCost(grid, r - 1, c, remainingCost - grid[r][c], cache);
    int pathsFromLeft = findPathsWithCost(grid, r, c - 1, remainingCost - grid[r][c], cache);

    cache[r][c][remainingCost] = pathsFromAbove + pathsFromLeft;
    return cache[r][c][remainingCost];
}

int main() {
    vector<vector<int>> grid = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };
    
    int targetCost = 25;
    int numRows = grid.size();
    int numCols = grid[0].size();

    vector<vector<vector<int>>> cache(numRows, vector<vector<int>>(numCols, vector<int>(targetCost + 1, -1)));

    int result = findPathsWithCost(grid, numRows - 1, numCols - 1, targetCost, cache);

    cout << "Number of paths with cost " << targetCost << " = " << result << endl;
    return 0;
}
