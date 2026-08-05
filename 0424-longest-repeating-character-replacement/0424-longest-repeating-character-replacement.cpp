class Solution {
public:
    int characterReplacement(string s, int k) {
       int n = s.size();
       unordered_map< char ,int > mp;

       int left  = 0;
       int maxfreq = 0;
       int ans = 0;

       for(int right = 0 ; right < n ; right++){
        mp[s[right]]++;

       maxfreq = max(maxfreq ,  mp[s[right]]);

       while((right - left + 1) - maxfreq  > k){
        mp[s[left]]--;
        left++;

       }

       ans = max(ans,right - left +1);
            
        
       } 
       return ans;
    }
};