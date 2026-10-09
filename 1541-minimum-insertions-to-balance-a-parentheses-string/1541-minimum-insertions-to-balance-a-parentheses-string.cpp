class Solution {
public:
    int minInsertions(string s) {
        string ans;
        int need = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (need % 2 == 1) {
                    ans += ')';
                    need--;
                }

                ans += '(';
                need += 2;
            } 
            else {
                if (need == 0) {
                    ans += "()";
                    need = 1;
                } else {
                    ans += ')';
                    need--;
                }
            }
        }

        ans.append(need, ')');

        return ans.size() - s.size();
    }
};