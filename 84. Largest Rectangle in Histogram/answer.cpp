class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }
        
        std::stack<int> st;  // Stores indices of bars in increasing height order
        int max_area = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            // At i == n, we use height 0 to pop all remaining bars
            int current_height = (i == n) ? 0 : heights[i];
            
            // While stack is not empty and current height is less than height at stack top
            while (!st.empty() && current_height < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                
                // If stack is empty, left boundary is -1
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                max_area = std::max(max_area, height * width);
            }
            
            st.push(i);
        }
        
        return max_area;
    }
};
