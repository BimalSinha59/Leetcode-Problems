class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>nge(n);
        stack<int>st;
        for(int i=2*n; i>=0; i--){
            if(i<n){
                while(!st.empty() && st.top()<=nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    nge[i]=-1;
                }
                else{
                    nge[i]=st.top();
                }
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
};