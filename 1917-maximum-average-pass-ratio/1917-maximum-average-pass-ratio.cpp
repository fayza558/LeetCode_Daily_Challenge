class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> pr;
        auto ratio = [](int x, int y) {
            return (1.0 * (x + 1) / (y + 1)) - (1.0 * x / y);
        };
        for (auto& it : classes) {
            pr.push({ratio(it[0], it[1]), {it[0], it[1]}});
        }
        while (extraStudents--) {
            auto [gain, students] = pr.top(); pr.pop();
            int x = students.first;
            int y = students.second;
            x++; y++;
            pr.push({ratio(x, y), {x, y}});
        }
        double ans = 0;
        while (!pr.empty()) {
            auto [gain, students] = pr.top(); pr.pop();
            int x = students.first;
            int y = students.second;
            ans += (1.0 * x / y);
        }
        return ans / classes.size();
    }
};
