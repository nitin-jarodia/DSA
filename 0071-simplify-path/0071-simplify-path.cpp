class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;

        int n = path.size();

        string token = "";

        string result = "";

        stringstream ss(path);

        while (getline(ss, token, '/')) {
            if (token == "." || token == "") {
                continue;
            }

            if (token != "..") {
                st.push(token);
            } else {
                if (!st.empty()) {
                    st.pop();
                }
            }
        }

        if (st.empty()) {
            return "/";
        }

        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result;
    }
};