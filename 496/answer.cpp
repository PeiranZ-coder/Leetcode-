class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Map to store the next greater element for each number in nums2
        std::unordered_map<int, int> nextGreater;
        std::stack<int> st;  // Monotonic decreasing stack
        
        // Process nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // Pop elements smaller than or equal to current
            while (!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }
            
            // If stack is empty, no greater element to the right
            // Otherwise, top of stack is the next greater element
            nextGreater[nums2[i]] = st.empty() ? -1 : st.top();
            
            // Push current element onto stack
            st.push(nums2[i]);
        }
        
        // Build answer for nums1 using the map
        std::vector<int> answer(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            answer[i] = nextGreater[nums1[i]];
        }
        
        return answer;
    }
};
