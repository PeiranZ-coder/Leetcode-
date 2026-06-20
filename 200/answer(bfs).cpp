#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        
        // Direction vectors for 4 neighbors: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    
                    // BFS using queue
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';  // Mark as visited
                    
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        
                        // Check all 4 neighbors
                        for (auto [dx, dy] : directions) {
                            int nx = x + dx;
                            int ny = y + dy;
                            
                            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
};
