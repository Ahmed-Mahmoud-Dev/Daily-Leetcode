const int dx[8]={0, 1, 0, -1, 1, -1, -1, 1},
        dy[8]={1, 0, -1, 0, 1, -1, 1, -1};

class Solution {
public:
    bool isValid(int i, int j, int rows, int cols) {
        return (i < rows && j < cols && i >= 0 && j >= 0);
    }

    vector<vector<int>> bfs(vector<pair<int, int>> &water, int rows, int cols)
    {
        queue<pair<int, int>> q;
        vector<vector<int>> distance(rows, vector<int> (cols, -1));
        for(auto it: water) {
            distance[it.first][it.second] = 0;
            q.push(it);
        }

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            int cost = distance[cur.first][cur.second];
            q.pop();
            for (int i=0; i<4; i++) {
                int x = cur.first + dx[i], y = cur.second + dy[i];
                if (isValid(x, y, rows, cols) && distance[x][y] == -1) {
                    distance[x][y] = cost + 1;
                    q.push({x, y});
                }
            }
        }

        return distance;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size(), cols = isWater[0].size();

        vector<pair<int, int>> water;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(isWater[i][j]) {
                    water.push_back({i, j});
                }
            }
        }

        vector<vector<int>> res = bfs(water, rows, cols);

        return res;
    }
};