class Solution {
public:
    int pf(vector<int>& nums,int div){
        int sum=0;
        for(auto it:nums){
            int add=ceil((double)it/div);
            sum+=add;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int s=1,e=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(s<=e){
            int mid=(s+e)/2;
            if(pf(nums,mid)<=threshold){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};