class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                    
                int num2 = st.back();
                st.pop_back();
                int num1 = st.back();
                st.pop_back();
                int eval;
                if (tokens[i] == "+") {
                    eval = num1 + num2;
                } else if (tokens[i] == "-") {
                    eval = num1 - num2;
                } else if (tokens[i] == "*") {
                    eval = num1 * num2;
                } else {
                    eval = num1 / num2;
                }
                st.push_back(eval);
            } else {
                int num = stoi(tokens[i]);
                st.push_back(num);
            }
        }
        return st[0];
    }
};