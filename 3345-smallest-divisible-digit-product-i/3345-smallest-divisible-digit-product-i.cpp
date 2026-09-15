class Solution {
public:
    int smallestNumber(int n, int t) {

        
        for (int i = n;; i++) {
            int x = i;
            int prod = 1;
            while (x > 0) {
                int digit = x % 10;
                x = x / 10;

                prod *= digit;
            }

            if (prod % t == 0) {
                return i;
            }
        }
        return -1;
    }
};