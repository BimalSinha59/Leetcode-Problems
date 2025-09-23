class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();

        //--------Brute Force--------
        // unordered_map<int,int>mp;
        // for(auto it:nums){
        //     mp[it]++;
        //     if(mp[it]>n/2){
        //         return it;
        //     }
        // }
        // return -1;

        //-------Optimization using Moore's Voting Algo-------

        int ele,cnt=0;
        for(int i=0; i<n; i++){
            if(cnt==0){
                cnt=1;
                ele=nums[i];
            }
            else if(nums[i]==ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return ele;
    }
};