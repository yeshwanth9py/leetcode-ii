// Last updated: 6/16/2026, 4:36:56 PM
class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long ans = 0;
        long long mul = 1e3;
        while(n>=mul){
            ans += (n-mul+1);
            mul = mul*1e3;
        }
        return ans;
    }
};