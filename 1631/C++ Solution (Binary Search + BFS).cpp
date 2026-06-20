#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        int left = 0;
        int right = 1000000;  // Max possible effort (height difference)
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canReach(heights, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
    
private:
    bool canReach(vector<vector<int>>& heights, int maxEffort) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        visited[0][0] = true;
        
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            if (row == rows - 1 && col == cols - 1) {
                return true;
            }
            
            for (auto [dr, dc] : dirs) {
                int newRow = row + dr;
                int newCol = col + dc;
                
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol]) {
                    int diff = abs(heights[row][col] - heights[newRow][newCol]);
                    
                    if (diff <= maxEffort) {
                        visited[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        
        return false;
    }
};
