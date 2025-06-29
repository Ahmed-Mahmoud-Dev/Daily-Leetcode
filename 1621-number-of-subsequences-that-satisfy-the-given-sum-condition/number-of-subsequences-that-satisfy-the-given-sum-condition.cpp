long long fastPowMod(long long base, long long exponent, long long mod) {
    long long result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        const unsigned int Mod = 1000000007;
        sort(nums.begin(), nums.end());

        long long res = 0;
        for(int i=0; i<n; i++) {
            int subSize = (upper_bound(nums.begin(), nums.end(), target-nums[i]) - nums.begin()) - i;
            if(subSize <= 0) continue;
            long long acceptedSequences = fastPowMod(2, subSize-1, Mod);

            res += acceptedSequences;
        }
        
        return (int)(res%Mod);
    }
};
