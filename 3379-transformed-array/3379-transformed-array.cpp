class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                arr[i]=0;
            }
            else if(nums[i]>0){
                int x=(i+nums[i])%n;
                arr[i]=nums[x];
            }
            else{
                int x=i+nums[i];
                if(x>=0){
                    arr[i]=nums[x];
                }
                else{
                    while(x<0){
                        x+=n;
                    }
                    arr[i]=nums[x];
                }
            }
        }
        return arr;
    }
};