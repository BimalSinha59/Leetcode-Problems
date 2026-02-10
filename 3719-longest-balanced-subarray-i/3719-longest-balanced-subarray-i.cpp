class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0; i<n; i++){
            set<int>st;
            int os=0,es=0;
            for(int j=i; j<n; j++){
                if(st.count(nums[j])==0 && nums[j]%2==0){
                    es++;
                }
                else if(st.count(nums[j])==0 && nums[j]%2!=0){
                    os++;
                }
                st.insert(nums[j]);
                if(es==os){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};