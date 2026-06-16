// Last updated: 6/16/2026, 4:37:06 PM
class Solution {
public:
    int countCommas(int n) {
        if(n<1000) return 0;
        n = n-1000;
        return n+1;
    }
};