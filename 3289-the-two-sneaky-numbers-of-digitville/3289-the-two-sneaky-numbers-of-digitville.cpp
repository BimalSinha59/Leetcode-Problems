class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>mp;
        int a=-1,b=-1;
        for(auto it:nums){
            mp[it]++;
            if(mp[it]==2 && a==-1){
                a=it;
            }
            else if(mp[it]==2){
                b=it;
            }
        }
        return {a,b};
    }
};