class Solution {
public:
    bool canComplete(int mountainHeight, vector<int>& workerTimes, long long secs,int n){
        int sum=0;
        for(auto &wt:workerTimes){
            long long wrk=secs/wt;
            long long ht=(-1+sqrt(1+wrk*8))/2;
            sum+=ht;
        }
        return sum>=mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n=workerTimes.size();
        long long low=1;
        long long high=(*max_element(workerTimes.begin(), workerTimes.end()))*1LL*mountainHeight*(mountainHeight+1)/2;
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(canComplete(mountainHeight,workerTimes,mid,n)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};