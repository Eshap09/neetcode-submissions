class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i:stones){
            pq.push(i);
        }

        while(!pq.empty()){
            int first = pq.top();
            pq.pop();
            if(!pq.empty()){
                int second = pq.top();
                pq.pop();

                int leftstone = abs(first-second);
                if(leftstone !=0){
                    pq.push(leftstone);
                }
            } else{
                return first;
            }
        }
        return 0;
    }
};
