#include <bits/stdc++.h>
using namespace std;

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Graph
{
private:
    int V;
    vector<int> *adj;

protected:
    void DFSUtil(int s, vector<bool> &visited, vector<int> &res);
    void BFSUtil(int s, vector<bool> &visited, vector<int> &res);

public:
    Graph(int Vertices)
    {
        this->V = Vertices;
        adj = new vector<int>[Vertices];
    }
    ~Graph()
    {
        for (int i = 0; i < V; i++)
            adj[i].clear();
        delete[] adj;
    }

    void addEdge(int v, int w);
    vector<int> BFS(int s);
    vector<int> DFS(int s);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::BFSUtil(int s, vector<bool> &visited, vector<int> &res)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (auto i = adj[u].begin(); i != adj[u].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}

vector<int> Graph::BFS(int s)
{
    vector<int> res;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
        if (!visited[i])
            BFSUtil(i, visited, res);

    return res;
}

void Graph::DFSUtil(int s, vector<bool> &visited, vector<int> &res)
{
    stack<int> st;
    st.push(s);
    visited[s] = true;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        res.push_back(u);
        for (auto i = adj[u].begin(); i != adj[u].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                st.push(*i);
            }
        }
    }
    return;
}

vector<int> Graph::DFS(int s)
{
    vector<int> res;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
        if (!visited[i])
            DFSUtil(i, visited, res);
    return res;
}





int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(3,2);
    g.addEdge(3,8);
    g.addEdge(3,5);
    g.addEdge(3,4);
    g.addEdge(6,4);
    g.addEdge(6,7);

    vector<int> res = g.BFS(0);
    for (auto i : res)
        cout << i << " ";

    return 0;
}
