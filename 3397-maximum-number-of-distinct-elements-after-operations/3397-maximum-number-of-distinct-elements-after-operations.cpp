class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
       int n=nums.size();
       int previous=INT_MIN;
       int ans=0;
       sort(nums.begin(),nums.end());
       for(int i=0; i<n; i++){
           int x=max(previous+1,nums[i]-k);
           if(x<=nums[i]+k){
            ans++;
            previous=x;
           }
       }
       return ans;
    }
};