class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int ans=0;
        int i=1; 
        while(i<n){
            int cnt=1;
            int sum=neededTime[i-1];
            int maxi=neededTime[i-1];
            while(i<n && colors[i-1]==colors[i]){
                cnt++;
                sum+=neededTime[i];
                maxi=max(maxi,neededTime[i]);
                i++;
            }
            if(cnt>1){
                ans+=(sum-maxi);
            }
            i++;
        }
        return ans;
    }
};