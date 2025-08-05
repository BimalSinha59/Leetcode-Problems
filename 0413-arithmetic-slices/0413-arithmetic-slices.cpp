class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return 0;
        }
        int i=0,j=1;
        int totalAS=0;
        while(j<n){
            int diff=nums[j]-nums[i];
            while(j+1<n && nums[j+1]-nums[j]==diff){
                j++;
            }
            int l=j-i+1;
            int as=l-3;
            if(as<0){
                as=0;
            }
            else{
                as=as+1;
            }
            totalAS+=(as*(as+1))/2;
            j++;
            i=j-1;
        }
        return totalAS;
    }
};