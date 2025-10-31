class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size()-2;
        int sm=0;
        int ssm=0;
        for(int& it:nums){
            sm+=it;
            ssm+=(it*it);
        }
        int snm=n*(n-1)/2;
        int ssnm=n*(n-1)*(2*n-1)/6;
        int s1=sm-snm, s2=ssm-ssnm;
        return {int(s1+sqrt(2*s2-s1*s1))/2,int(s1-sqrt(2*s2-s1*s1))/2};
    }
};