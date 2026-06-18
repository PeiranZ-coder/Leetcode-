class MedianFinder {
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size() == right.size()){
            right.push(num);
            left.push(right.top());
            right.pop();
        }else{
            left.push(num);
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size() != right.size()){
            return left.top();
        }else{
            return (left.top() + right.top()) / 2.0;
        }
    }
};
