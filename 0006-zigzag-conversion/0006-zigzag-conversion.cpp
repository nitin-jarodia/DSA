class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) return s;  // No zigzag needed

        vector<string> rows(numRows);
        int row = 0;
        int step = 1;  // +1 means going down, -1 means going up

        for(char c : s) {

            rows[row] += c;   // Put character in current row

            // If we reach bottom → go up
            if(row == numRows - 1) step = -1;

            // If we reach top → go down
            else if(row == 0) step = 1;

            row += step;      // Move to next row
        }

        // Join all rows to make final string
        string ans = "";
        for(string &r : rows) ans += r;

        return ans;
    }
};
