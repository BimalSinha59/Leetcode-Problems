class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int>nnums=nums;
        while(nnums.size()>1){
            vector<int>temp;
            for(int i=0; i<nnums.size()-1; i++){
                temp.push_back((nnums[i]+nnums[i+1])%10);
            }
            nnums=temp;
        }
        return nnums[0];
    }
};