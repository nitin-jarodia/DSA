class Solution {
public:
    vector<string> ans;

    void dfs(string &s, int start,
             int leftRemove, int rightRemove) {

        // If no removals are left, check whether string is valid
        if (leftRemove == 0 && rightRemove == 0) {

            int balance = 0;

            for (char c : s) {
                if (c == '(')
                    balance++;
                else if (c == ')') {
                    balance--;

                    if (balance < 0)
                        return;
                }
            }

            if (balance == 0)
                ans.push_back(s);

            return;
        }

        for (int i = start; i < s.size(); i++) {

            // Skip duplicate parentheses
            if (i > start && s[i] == s[i - 1])
                continue;

            // Remove '('
            if (leftRemove > 0 && s[i] == '(') {

                s.erase(i, 1);

                dfs(s, i, leftRemove - 1, rightRemove);

                s.insert(i, 1, '(');
            }

            // Remove ')'
            if (rightRemove > 0 && s[i] == ')') {

                s.erase(i, 1);

                dfs(s, i, leftRemove, rightRemove - 1);

                s.insert(i, 1, ')');
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Calculate minimum removals
        for (char c : s) {

            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {

                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        dfs(s, 0, leftRemove, rightRemove);

        return ans;
    }
};