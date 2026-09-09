class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        string dir = "";
        for (int i = 0; i <= n; i++) {
            if (i < n && path[i] != '/') {
                dir += path[i];
            } else {
                if (dir == "..") {
                    if (!st.empty())
                        st.pop();
                } else if (!dir.empty() && dir != ".") {
                    st.push(dir);
                }
                dir = "";
            }
        }
        if (st.empty()) {
            return "/";
        }
        string simplified_path = "";
        while (!st.empty()) {
            simplified_path = "/" + st.top() + simplified_path;
            st.pop();
        }
        return simplified_path;
    }
};