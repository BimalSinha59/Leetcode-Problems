class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int sum=0;
        int mins=INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                sum+=nums[j];
                int x=j-i+1;
                if(sum>0 && (x>=l && x<=r) ){
                    mins=min(sum,mins);
                }
            }
            sum=0;
        }
        if(mins==INT_MAX){
            return -1;
        }
        return mins;
    }
};