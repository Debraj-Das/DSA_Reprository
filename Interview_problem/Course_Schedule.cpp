#include <bits/stdc++.h>
using namespace std;

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> visits(numCourses, 0);
        for (auto &p : prerequisites)
            graph[p[1]].push_back(p[0]);
        for (int i = 0; i < numCourses; ++i)
            if ((!visits[i]) and cycle(graph, visits, i))
                return false;
        return true;
    }
    bool cycle(vector<vector<int>> &graph, vector<int> &visits, int i)
    {
        if (visits[i] == 1)
            return true;
        if (visits[i] == 2)
            return false;
        visits[i] = 1;
        for (auto &j : graph[i])
            if (cycle(graph, visits, j))
                return true;
        visits[i] = 2;
        return false;
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n = 2;
    vector<vector<int>> prerequisites = {{0, 1}};
    Solution obj;
    cout << obj.canFinish(n, prerequisites) << endl;

    return 0;
}
