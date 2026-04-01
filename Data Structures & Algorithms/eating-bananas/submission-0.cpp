class Solution {
public:
    int hoursToEat(vector<int>& piles, int k){
        int hours =0;
        for(auto i: piles){
            if(i%k ==0){
                hours+= i/k;
            } else {
                hours+= (i+k)/k;
            }
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int minelem = 0;
        int maxelem = 0;
        for(auto i:piles){
            maxelem = max(maxelem, i);
        }
        int low = 1,high = maxelem;
        // if(h==piles.size()){
        //     return low;
        // } 
        // if(sum == h){
        //     return 1;
        // }
        int minspeed=high;
        while(low<=high){
            int mid = low + (high-low)/2;
            int hoursTaken = hoursToEat(piles, mid);
            if(hoursTaken>h){
                low = mid+1;
            } else if(hoursTaken<=h){
                minspeed = mid;
                high = mid-1;
            }
        }
        return minspeed;
    }
};
