class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int zeros=0,ones=0,twos=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                zeros++;
            }
            else if(nums[i]==1){
                ones++;
            }
            else{
                twos++;
            }
        }

        int j=0;
        for(int i=0; i<zeros; i++){
            nums[j]=0;
            j++;
        }
        for(int i=0; i<ones; i++){
            nums[j]=1;
            j++;
        }
        for(int i=0; i<twos; i++){
            nums[j]=2;
            j++;
        }
        
    }
};