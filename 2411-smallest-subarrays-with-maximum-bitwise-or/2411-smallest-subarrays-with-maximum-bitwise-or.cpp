class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> bp(31,-1);
        vector<int> minSize(n);
        for(int i=n-1; i>=0; i--){
            int j=i;
            for(int b=0; b<31; b++){
                if((nums[i]&(1<<b))==0){
                    if(bp[b]!=-1){
                        j=max(j,bp[b]);
                    }
                }
                else{
                    bp[b]=i;
                }
            }
            minSize[i]=j-i+1;
        }
        return minSize;
    }
};