// Last updated: 6/16/2026, 4:37:23 PM
class Solution {
public:
    int fact[11];
    void pre(){
        fact[0] = fact[1] = 1;
        for(int i=2; i<=10; i++){
            fact[i] = fact[i-1]*i;
        }
    }
    bool isDigitorialPermutation(int n) {
        pre();
        unordered_map<int, int> ump;
        string s = to_string(n);
        sort(s.begin(), s.end());
        int fa = 0;
        for(int i=0; i<s.size(); i++){
            fa += fact[s[i]-'0'];
        }
        string o = to_string(fa);
        sort(o.begin(), o.end());
        return o == s;
    }
};