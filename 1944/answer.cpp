#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> canSeePersonsCount(std::vector<int>& heights) {
        int n = heights.size();
        std::vector<int> answer(n, 0);
        std::stack<int> st;  // Monotonic decreasing stack (stores indices)
        
        // Iterate from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Count how many people this person can see
            int count = 0;
            
            // While stack is not empty and current height is greater than stack top
            while (!st.empty() && heights[i] > heights[st.top()]) {
                // Current person can see this shorter person
                count++;
                st.pop();
            }
            
            // If stack is not empty, current person can see the next taller person
            if (!st.empty()) {
                count++;
            }
            
            answer[i] = count;
            
            // Push current person's index onto stack
            st.push(i);
        }
        
        return answer;
    }
};
