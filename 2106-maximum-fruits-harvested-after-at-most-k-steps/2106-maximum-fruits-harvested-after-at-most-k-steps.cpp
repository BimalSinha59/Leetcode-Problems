class Solution {
public:
    int minmStp(int l,int r, int s){
        return min(abs(s-l)+(r-l),abs(s-r)+(r-l));
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        int l=0,sum=0;
        int ans=0;
        for(int r=0; r<n; r++){
            sum+=fruits[r][1];
            while(l<=r && minmStp(fruits[l][0],fruits[r][0],startPos)>k){
                sum-=fruits[l][1];
                l++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};