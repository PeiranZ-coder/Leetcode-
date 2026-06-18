class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // 按开始时间排序
        sort(intervals.begin(), intervals.end());

        // 小根堆，存每个会议室的结束时间
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (auto& interval : intervals) {
            int start = interval[0];
            int end   = interval[1];

            // 最早结束的房间已经空出来了，复用它
            if (!min_heap.empty() && min_heap.top() <= start) {
                min_heap.pop();
            }

            // 当前会议占用一个房间
            min_heap.push(end);
        }

        return (int)min_heap.size();  // 堆的大小就是房间数
    }
};
