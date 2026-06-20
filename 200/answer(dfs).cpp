#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Check boundaries and if current cell is water or already visited
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') {
            return;
        }
        
        // Mark as visited by changing to '0'
        grid[i][j] = '0';
        
        // Explore all 4 directions
        dfs(grid, i - 1, j);  // up
        dfs(grid, i + 1, j);  // down
        dfs(grid, i, j - 1);  // left
        dfs(grid, i, j + 1);  // right
    }
};
