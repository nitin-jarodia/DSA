class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

       int left = 0;
       int right = 1;
       int maxprofit = 0;
      int  currprofit = 0;

       while(right < n){
       

        

                if(prices[left] <  prices[right]){
                    currprofit = prices[right] - prices[left];
                    maxprofit = max(maxprofit,currprofit);
                }

                else{
                    left = right;

                }
              right++;

       }
       return maxprofit;

    }
};