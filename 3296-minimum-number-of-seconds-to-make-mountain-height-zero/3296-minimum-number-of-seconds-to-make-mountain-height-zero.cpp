class Solution {
public:
    bool ifPossible(int mountainHeight, vector<int>& workerTimes, long long secs,int n,vector<long long>& sumn){
        int sum=0;
        for(auto &wtm:workerTimes){
            long long divi=secs/wtm;
            auto it=lower_bound(sumn.begin(), sumn.end(), divi);
            int idx=distance(sumn.begin(),it);
            if(it==sumn.end()){
                sum+=1e5;
            }
            else if(sumn[idx]==divi){
                sum+=idx;
            }
            else{
                sum+=(idx-1);
            }
        }
        return sum>=mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        const int N=1e5+1;
        vector<long long>sumn(N+1);
        sumn[0]=0;
        for(int i=1; i<=N; i++){
            sumn[i]=sumn[i-1]+i;
        }
        int n=workerTimes.size();
        long long low=1;
        long long high=(*max_element(workerTimes.begin(), workerTimes.end()))*1LL*mountainHeight*(mountainHeight+1)/2;
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(ifPossible(mountainHeight,workerTimes,mid,n,sumn)){
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