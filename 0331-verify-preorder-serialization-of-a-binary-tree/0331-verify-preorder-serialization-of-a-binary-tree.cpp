class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n=preorder.size();
        stack<char>st;
        int i=n-1;
        while(i>=0){
            char ch=preorder[i];
            while(i>=0 && preorder[i]!=','){
                i--;
            }
            if(ch=='#'){
                st.push(ch);
            }
            else{
                if(st.size()<2){
                    return false;
                }
                else{
                    st.pop();
                    st.pop();
                    st.push('#');
                }
            }
            i--;
        }
        if(st.size()>1){
            return false;
        }
        return true;
    }
};