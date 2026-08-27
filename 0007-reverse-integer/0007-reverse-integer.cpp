class Solution {
public:
    int reverse(int x) {
       long long rev = 0;



       while(x != 0){
            long long dig = x%10;
            
            rev = (long long)(rev * 10) + dig;

            x = x/10;


       }
       if(rev > INT_MAX || rev < INT_MIN)
    return 0;
      
       return (int)rev;
    }
};