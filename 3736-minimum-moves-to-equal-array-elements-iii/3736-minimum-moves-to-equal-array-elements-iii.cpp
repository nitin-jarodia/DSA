
class Solution {
public:
    int minMoves(vector<int>& nums) {

        int maxVal = 0;
        int sum = 0;

      
        for (int num : nums) {
            maxVal = max(maxVal, num);
            sum += num;
        }

     
        return (maxVal * nums.size()) - sum;
    }
};
