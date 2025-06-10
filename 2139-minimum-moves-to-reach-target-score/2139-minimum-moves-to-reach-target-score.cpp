class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans=0;
        int ntgt=target;
        while(ntgt>1 && maxDoubles>0){
           if(ntgt&1){
            ans++;
            ntgt--;
           }
           ntgt=ntgt/2;
           ans++;
           maxDoubles--;
        }
        ans+=(ntgt-1);
        return ans;
    }
};