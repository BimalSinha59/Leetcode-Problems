class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int maxArea=0;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int idx=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty() ? -1:st.top();
                int area=heights[idx]*(nse-pse-1);
                maxArea=max(maxArea,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int idx=st.top();
            st.pop();
            int nse=n;
            int pse=st.empty() ? -1:st.top();
            int area=heights[idx]*(nse-pse-1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};