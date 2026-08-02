class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end());
        int n = people.size();

        int left  = 0;
        int right = n-1;
        int cnt = 0;


        while(left < right){

            int maxlim = people[left] + people[right];

            if(maxlim  <= limit){
                cnt++;
                left++;
                right--;
               
            }
            else{
            right--;
            cnt++;
            }
            if(left == right){
                cnt++;
            }
            

        }
        return cnt;
    }
};