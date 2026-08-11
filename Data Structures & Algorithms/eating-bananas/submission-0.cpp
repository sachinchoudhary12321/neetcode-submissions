class Solution {
public:
    bool fun(int speed,int time,vector<int>& piles){
        int count=0;
        for(int it:piles){
            count += (it + speed - 1) / speed;
            
        }
        return count <= time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if(h < n) return -1;
        int max_value = INT_MIN;
        for(int it:piles){
            max_value = max(max_value,it);
        } 
        int st = 1,end=max_value;
        int ans=0 ;
        while(st < end){
            int mid = st + (end-st)/2;
            if(fun(mid,h,piles)){
                end = mid;
                ans = mid;
            } 
            else{
                st = mid+1;
            }
        }
        return st;
    }
};
