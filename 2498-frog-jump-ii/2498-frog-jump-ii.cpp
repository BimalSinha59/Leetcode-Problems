class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        if(n==2){
            return stones[1]-stones[0];
        }
        int ans=INT_MIN;
        for(int i=0; i<n-2; i++){
            int diff=stones[i+2]-stones[i];
            ans=max(diff,ans);
        }
        return ans;
        
    }
};