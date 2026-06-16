// Last updated: 6/16/2026, 4:37:00 PM
class Solution {
public:
    int minimumIndex(vector<int>& cap, int is) {
        int n = cap.size();
        int ans = n;
        int ansv = 1e9;
        for(int i=0; i<n; i++){
            if(cap[i]>=is && ansv>cap[i]){
                ansv = cap[i];
                ans = i;
            }
        }
        if(ans == n) return -1;

        return ans;
    }
};