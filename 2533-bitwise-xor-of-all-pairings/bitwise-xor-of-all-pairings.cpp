class Solution {
public:
    long long xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        const int sz = 30;
        long long freq1[sz] = {0}, freq2[sz] = {0}, n = nums1.size(), m = nums2.size(), res = 0;

        for(int i=0; i<n; i++) {
            for(int mask=0; mask<sz; mask++) {
                if(nums1[i] & 1<<mask) {
                    freq1[mask]++;
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int mask=0; mask<sz; mask++) {
                if(nums2[i] & (1<<mask)) {
                    freq2[mask]++;
                }
            }
        }

        for(int mask=0; mask<sz; mask++) {
            if(((freq1[mask]*m) + (freq2[mask]*n)) & 1) {
                res += (1<<mask);
            }
        }

        return res;
    }
};