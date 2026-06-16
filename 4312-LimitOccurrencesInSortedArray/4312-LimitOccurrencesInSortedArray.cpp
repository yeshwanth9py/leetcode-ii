// Last updated: 6/16/2026, 4:36:14 PM
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        vector<int> ans;
        for(int el: nums){
            ump[el]++;
            if(ump[el]<=k){
                ans.push_back(el);
            }
        }

        return ans;
    }
};