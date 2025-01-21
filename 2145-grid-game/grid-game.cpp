class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int rows = 2, cols = grid[0].size();

        vector<long long> freqTop(cols), freqBottom(cols);

        freqTop[0] = grid[0][0];
        for(int i=1; i<cols; i++) {
            freqTop[i] = freqTop[i-1] + grid[0][i];
        }

        freqBottom[0] = grid[1][0];
        for(int i=1; i<cols; i++) {
            freqBottom[i] = freqBottom[i-1] + grid[1][i];
        }

        long long res = LONG_LONG_MAX, cur;
        for(int i=0; i<cols; i++) {
            cur = freqTop[cols-1] - freqTop[i];

            if(i-1 >= 0) {
                cur = max(cur, freqBottom[i-1]);
            }
            res = min(res, cur);
        }

        return res;
    }
};