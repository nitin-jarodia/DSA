class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0; 
        // long long prod = 1;
        string x = "";

        while(n>0){
            int digit = n%10;
           if(digit != 0){
            x += to_string(digit);
           }
          

            sum += digit;
            n = n/10;

        }
        if(x.empty()) return 0;
        reverse(x.begin() , x.end());
        long long num = stoll(x);
        return num*sum;
    }
};