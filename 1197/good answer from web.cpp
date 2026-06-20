class Solution {
public:
    int minKnightMoves(int x, int y) {
        // 1. 利用对称性：映射到第一象限
        x = abs(x);
        y = abs(y);
        
        // 2. 确保 x >= y（利用对称性）
        if (x < y) swap(x, y);
        
        // 3. 处理特殊情况
        if (x == 1 && y == 0) return 3;
        if (x == 2 && y == 2) return 4;
        
        // 4. 核心公式
        int ans = max((x + 1) / 2, (x + y + 2) / 3);
        
        // 5. 奇偶性修正
        return (ans + x + y) & 1 ? ans + 1 : ans;
    }
};

//完整测试程序//
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        if (x < y) swap(x, y);
        if (x == 1 && y == 0) return 3;
        if (x == 2 && y == 2) return 4;
        int ans = max((x + 1) / 2, (x + y + 2) / 3);
        return (ans + x + y) & 1 ? ans + 1 : ans;
    }
};

// 用于验证的BFS实现（小范围）
int bfsKnightMoves(int x, int y) {
    x = abs(x);
    y = abs(y);
    if (x == 0 && y == 0) return 0;
    
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    q.push({0, 0});
    visited.insert({0, 0});
    
    vector<pair<int, int>> dirs = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2}, {1, 2}, {2, -1}, {2, 1}
    };
    
    int steps = 0;
    while (!q.empty()) {
        int size = q.size();
        steps++;
        for (int i = 0; i < size; i++) {
            auto [cx, cy] = q.front();
            q.pop();
            for (auto [dx, dy] : dirs) {
                int nx = cx + dx;
                int ny = cy + dy;
                if (nx == x && ny == y) return steps;
                if (nx >= -2 && ny >= -2 && nx <= x+2 && ny <= y+2) {
                    if (visited.find({nx, ny}) == visited.end()) {
                        visited.insert({nx, ny});
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    Solution sol;
    
    // 测试各种情况
    vector<pair<int, int>> testCases = {
        {0, 0}, {1, 0}, {1, 1}, {2, 0}, {2, 1}, 
        {2, 2}, {3, 0}, {3, 1}, {3, 2}, {3, 3},
        {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4},
        {5, 5}, {10, 10}, {100, 100}
    };
    
    cout << "Testing minKnightMoves formula:\n";
    cout << "x\ty\tFormula\tBFS\tMatch?\n";
    cout << "----------------------------------------\n";
    
    for (auto [x, y] : testCases) {
        if (x > 10 || y > 10) {
            // 大数只测试公式
            cout << x << "\t" << y << "\t" << sol.minKnightMoves(x, y) << "\t-\t-\n";
        } else {
            int formula = sol.minKnightMoves(x, y);
            int bfs = bfsKnightMoves(x, y);
            cout << x << "\t" << y << "\t" << formula << "\t" << bfs << "\t" 
                 << (formula == bfs ? "✓" : "✗") << "\n";
        }
    }
    
    return 0;
}
