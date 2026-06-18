class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
       swap(nums1, nums2);
        }   
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        while (left <= right) {
            // nums1 中取前 i 个元素
            int i = (left + right) / 2;
            // nums2 中取前 j 个元素，使得 i + j = (m + n + 1) / 2
            int j = (m + n + 1) / 2 - i;
            
            // 边界情况处理
            int nums1_left_max = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1_right_min = (i == m) ? INT_MAX : nums1[i];
            int nums2_left_max = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2_right_min = (j == n) ? INT_MAX : nums2[j];
            
            // 检查切分是否正确
            if (nums1_left_max <= nums2_right_min && nums2_left_max <= nums1_right_min) {
                // 找到正确切分
                if ((m + n) % 2 == 1) {
                    return max(nums1_left_max, nums2_left_max);
                } else {
                    return (max(nums1_left_max, nums2_left_max) + 
                            min(nums1_right_min, nums2_right_min)) / 2.0;
                }
            } else if (nums1_left_max > nums2_right_min) {
                // 需要减小 i，即向左移动
                right = i - 1;
            } else {
                // 需要增大 i，即向右移动
                left = i + 1;
            }
        }
        
        // 理论上不会执行到这里
        return 0.0;
    }
};



/// 一个我觉得很不错的code回答
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int > merge{};
        int sz1 = nums1.size(), sz2 = nums2.size();
        int p1 = 0, p2 = 0;

        while (p1 < sz1 && p2 < sz2) {
            if (nums1[p1] < nums2[p2]) {
                merge.push_back(nums1[p1]);
                ++p1;
            } else {
                merge.push_back(nums2[p2]);
                ++p2;
            }
        } // end while()

        if (p1 < sz1) {
            merge.insert(merge.end(), nums1.begin() + p1, nums1.end());
        }
        if (p2 < sz2) {
            merge.insert(merge.end(), nums2.begin() + p2, nums2.end());
        }

        int sz = merge.size();
        if (sz % 2 == 0) {
            return (merge[sz / 2 - 1] + merge[sz / 2]) / 2.0;
        } else {
            return merge[sz / 2];
        }
    }
};
