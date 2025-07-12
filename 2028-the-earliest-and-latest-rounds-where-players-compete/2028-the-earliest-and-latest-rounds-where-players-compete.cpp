class Solution {
    int first, second;
    unordered_map<string, pair<int, int>> memo;

    pair<int, int> dfs(vector<int>& players, int round) {
        // Create a string key for memoization
        string key;
        for (int p : players) {
            key += to_string(p) + ",";
        }

        if (memo.count(key)) return memo[key];

        int fIdx = find(players.begin(), players.end(), first) - players.begin();
        int sIdx = find(players.begin(), players.end(), second) - players.begin();

        if (fIdx + sIdx == players.size() - 1 && fIdx < sIdx) {
            return memo[key] = {round, round};
        }

        int n = players.size();
        vector<vector<int>> nextRounds;
        vector<int> curr;

        function<void(int, int)> generate = [&](int l, int r) {
            if (l > r) {
                if (find(curr.begin(), curr.end(), first) != curr.end() &&
                    find(curr.begin(), curr.end(), second) != curr.end()) {
                    nextRounds.push_back(curr);
                }
                return;
            }

            if (l == r) {
                curr.push_back(players[l]);
                generate(l + 1, r - 1);
                curr.pop_back();
                return;
            }

            // left wins
            curr.push_back(players[l]);
            generate(l + 1, r - 1);
            curr.pop_back();

            // right wins
            curr.push_back(players[r]);
            generate(l + 1, r - 1);
            curr.pop_back();
        };

        generate(0, n - 1);

        int minRound = INT_MAX, maxRound = INT_MIN;
        for (auto& nxt : nextRounds) {
            sort(nxt.begin(), nxt.end());  // maintain order
            auto res = dfs(nxt, round + 1);
            minRound = min(minRound, res.first);
            maxRound = max(maxRound, res.second);
        }

        return memo[key] = {minRound, maxRound};
    }

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        first = min(firstPlayer, secondPlayer);
        second = max(firstPlayer, secondPlayer);
        vector<int> players;
        for (int i = 1; i <= n; ++i) {
            players.push_back(i);
        }

        auto [earliest, latest] = dfs(players, 1);
        return {earliest, latest};
    }
};
