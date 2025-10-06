class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n=nums.size();
        int os=0,es=0;
        for(int i=0; i<n; i++){
            if(i&1){
                os+=nums[i];
            }
            else{
                es+=nums[i];
            }
        }
        return es-os;
    }
};