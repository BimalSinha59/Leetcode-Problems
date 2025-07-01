class Solution {
public:
    vector<int> findPSE(vector<int>& heights, int n){
        vector<int>pse(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            pse[i]=st.empty() ? -1:st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> findNSE(vector<int>& heights, int n){
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            nse[i]=st.empty() ? n:st.top();
            st.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        auto pse=findPSE(heights,n);
        auto nse=findNSE(heights,n);
        int maxArea=0;
        for(int i=0; i<n; i++){
            int width=nse[i]-pse[i]-1;
            int area=heights[i]*width;
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};