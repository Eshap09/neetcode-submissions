class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int, vector<int>, greater<int>>right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num<=left.top()){
            left.push(num);
        } else{
            right.push(num);
        }

        if(left.size()>right.size()+1){
            int elem = left.top();
            left.pop();
            right.push(elem);
        }
        else if(right.size()> left.size()+1){
            int elem = right.top();
            right.pop();
            left.push(elem);
        }
    }
    
    double findMedian() {
        int leftsize = left.size();
        int rightsize = right.size();
        if(leftsize == rightsize){
            return (left.top()+right.top())/2.0;
        } else if(leftsize>rightsize){
            return left.top();
        } else {
            return right.top();
        }
    }
};
