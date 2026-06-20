#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // 记录每个空地到所有建筑的总距离
        vector<vector<int>> totalDist(rows, vector<int>(cols, 0));
        // 记录每个空地能到达的建筑数量
        vector<vector<int>> reachableBuildings(rows, vector<int>(cols, 0));
        
        int buildingCount = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // 从每个建筑进行BFS
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    buildingCount++;
                    bfs(grid, i, j, totalDist, reachableBuildings, directions);
                }
            }
        }
        
        // 找到最小总距离
        int minDist = INT_MAX;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0 && reachableBuildings[i][j] == buildingCount) {
                    minDist = min(minDist, totalDist[i][j]);
                }
            }
        }
        
        return minDist == INT_MAX ? -1 : minDist;
    }
    
private:
    void bfs(vector<vector<int>>& grid, int startRow, int startCol,
             vector<vector<int>>& totalDist,
             vector<vector<int>>& reachableBuildings,
             vector<pair<int, int>>& directions) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        
        q.push({startRow, startCol});
        visited[startRow][startCol] = true;
        
        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            dist++;
            
            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();
                
                for (auto [dr, dc] : directions) {
                    int newRow = row + dr;
                    int newCol = col + dc;
                    
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                        !visited[newRow][newCol] && grid[newRow][newCol] == 0) {
                        
                        visited[newRow][newCol] = true;
                        totalDist[newRow][newCol] += dist;
                        reachableBuildings[newRow][newCol]++;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
    }
};
