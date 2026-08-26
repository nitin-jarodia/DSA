class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int l = *max_element(weights.begin(), weights.end());

        int r = accumulate(weights.begin(), weights.end(), 0);

        while(l <= r){

            int mid = l + (r - l) / 2;

            int currweight = 0;
            int reqdays = 1;

            for(int weight : weights){

               
                if(currweight + weight > mid){

                    reqdays++;
                    currweight = weight;
                }
                else{
                    currweight += weight;
                }
            }

           
            if(reqdays <= days){
                r = mid - 1;
            }

                  else{
                l = mid + 1;
            }
        }

        return l;
    }
};