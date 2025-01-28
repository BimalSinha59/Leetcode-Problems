class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int count =0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                count++;
            }
        }

        int j=0;
        for(int i=0; i<n; i++){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
        }
        int k=n-1;
        while(count--){
            nums[k]=0;
            k--;
        }
        
    }
};