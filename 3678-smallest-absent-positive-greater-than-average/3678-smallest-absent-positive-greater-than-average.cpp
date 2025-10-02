class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        unordered_set<int>st;
        for(auto it:nums){
            sum+=it;
            st.insert(it);
        }
        int avg=sum/n;
        while(st.count(avg+1)){
            avg++;
        }
        if(avg+1<=0){
            avg=0;
        }
        return avg+1;

    }
};