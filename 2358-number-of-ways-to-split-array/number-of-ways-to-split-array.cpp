class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long n = nums.size(), sum = 0, leftSide=0;

        for(int i=0; i<n; i++) {
            sum += nums[i];
        }

        int res = 0;
        for(int i=0; i<n-1; i++) {
            leftSide += nums[i];

            if(leftSide >= sum-leftSide) res++;
        }
        
        return res;
    }
};