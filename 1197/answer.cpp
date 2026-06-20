#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:
    int minKnightMoves(int x, int y) {
        // 利用对称性，将目标映射到第一象限并确保x >= y
        x = abs(x);
        y = abs(y);
        if (x < y) swap(x, y);
        
        // 如果目标很近，可以直接计算
        if (x == 1 && y == 0) return 3;
        if (x == 2 && y == 2) return 4;
        
        // BFS
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        unordered_set<string> visited;
        visited.insert("0,0");
        
        vector<pair<int, int>> directions = {
            {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
            {1, -2}, {1, 2}, {2, -1}, {2, 1}
        };
        
        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                auto [currX, currY] = q.front();
                q.pop();
                
                if (currX == x && currY == y) {
                    return steps;
                }
                
                for (auto [dx, dy] : directions) {
                    int newX = currX + dx;
                    int newY = currY + dy;
                    
                    // 优化：只搜索有希望的区域
                    if (newX >= -2 && newY >= -2 && 
                        newX <= x + 2 && newY <= y + 2) {
                        
                        string key = to_string(newX) + "," + to_string(newY);
                        if (visited.find(key) == visited.end()) {
                            visited.insert(key);
                            q.push({newX, newY});
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};
