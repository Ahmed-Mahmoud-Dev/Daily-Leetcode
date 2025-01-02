class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(), days.end());
        vector<int> dp(400, -1);

        return solve(0, days, costs, dp);
    }

    int pos(vector<int>& days, int i, int plus) {
        return upper_bound(days.begin(), days.end(), days[i]+plus) - days.begin();
    }

    int solve(int i, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if(i >= days.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int res = INT_MAX;

        res = min(res, solve(pos(days, i, 29), days, costs, dp) + costs[2]);
        res = min(res, solve(pos(days, i, 6), days, costs, dp) + costs[1]);
        res = min(res, solve(pos(days, i, 0), days, costs, dp) + costs[0]);


        return dp[i] = res;
    }

};

