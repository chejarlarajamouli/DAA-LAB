#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS Function
void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node])
    {
        if (!visited[next])
        {
            DFS(next, graph, visited);
        }
    }
}

// BFS Function
void BFS(int start, vector<vector<int>>& graph, int vertices)
{
    vector<bool> visited(vertices, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int next : graph[node])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> graph(vertices);

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // DFS
    vector<bool> visited(vertices, false);

    cout << "\nDFS Traversal: ";
    DFS(start, graph, visited);

    // BFS
    cout << "\nBFS Traversal: ";
    BFS(start, graph, vertices);

    return 0;
}
