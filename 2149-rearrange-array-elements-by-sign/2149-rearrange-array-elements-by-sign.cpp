class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>a,b;
        int n = nums.size();

        for(int i =0; i<n; i++){
            if(nums[i]>0){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
        }

        vector<int> ans;
        int i =0;
        int j =0;
        while(i<a.size() && j<b.size()){
            ans.push_back(a[i]);
            i++;
            ans.push_back(b[j]);
            j++;
        }


       return ans; 
    }
};