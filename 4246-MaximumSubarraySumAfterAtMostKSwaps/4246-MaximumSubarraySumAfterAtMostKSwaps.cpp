// Last updated: 6/16/2026, 4:37:03 PM
class Solution {
public:
    long long maxSum(vector<int>& nums, long long k) {
        long long n = nums.size();
        vector<vector<long long>> dpmin(n, vector<long long>(n, 0));
        vector<vector<long long>> dpmax(n, vector<long long>(n, 0));

        priority_queue<long long, vector<long long>, greater<long long>> pqmax;
        long long maxsum = 0;

        for(long long i=0; i<n; i++){
            priority_queue<long long> pqmin;
            long long mins = 0;

            for(long long j=i; j<n; j++){
                if(nums[j]<0){
                    if(pqmin.size()<k || (pqmin.size()>0 && pqmin.top()>nums[j])){
                        pqmin.push(nums[j]);
                        mins += nums[j];
                        if(pqmin.size()>k){
                            long long tel = pqmin.top(); pqmin.pop();
                            mins -= tel;
                        }
                    }
                }
                dpmin[i][j] = mins;
            }

            priority_queue<long long, vector<long long>, greater<long long>> pqmax2 = pqmax;
            long long maxsum2 = maxsum;

            for(long long j=n-1; j>=i; j--){
                dpmax[i][j] = maxsum2;
                pqmax2.push(nums[j]);
                maxsum2 += nums[j];
                if(pqmax2.size()>k){
                    long long tel = pqmax2.top(); pqmax2.pop();
                    maxsum2 -= tel;
                }
            }

            pqmax.push(nums[i]);
            maxsum += nums[i];
            if(pqmax.size()>k){
                long long tel = pqmax.top(); pqmax.pop();
                maxsum -= tel;
            }
        }

        long long ans = -1e9;
        for(long long i=0; i<n; i++){
            long long cs = 0;
            for(long long j=i; j<n; j++){
                cs += nums[j];
                ans = max(ans, cs);
                if(i != 0 || j != n-1){
                    ans = max(ans, cs-dpmin[i][j]+dpmax[i][j]);
                }
            }
        }

        return ans;

    }
};