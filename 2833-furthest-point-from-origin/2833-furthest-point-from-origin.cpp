class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int cnt = 0;
        int blank = 0;

        for(char ch : moves){
            if(ch == 'L') cnt--;
            else if(ch == 'R') cnt++;
            else blank++;
        }

        return abs(cnt) + blank;
    }
};