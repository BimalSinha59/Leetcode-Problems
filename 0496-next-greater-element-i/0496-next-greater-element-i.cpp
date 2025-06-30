class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        stack<int>st;
        unordered_map<int,int>mp;
        for(int i=m-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]]=-1;
            }
            else{
                mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>nge(n);
        for(int i=0; i<n; i++){
            nge[i]=mp[nums1[i]];
        }
        return nge;
    }
};