class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n  = nums.size();

        int cnt = 0 ;
        int candidate = 0;

        for(int x : nums){
            if(cnt == 0){
                candidate = x;
            }
            if( x == candidate){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return candidate;
    }
};