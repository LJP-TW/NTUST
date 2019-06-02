#include <iostream>
#include <vector>

using namespace std;

struct Vertex
{
    int color;

    // Neighbors
    vector<int> adj;
};

Vertex *vertices;
int vertexCount, edgeCount;

bool DFS_Visit(int u)
{
    // Set color to grey
    vertices[u].color = 1;

    // Visit all neighbor
    for (int neighbor = 0; neighbor < vertices[u].adj.size(); ++neighbor)
    {
        // Get neighbor id
        int v = vertices[u].adj[neighbor];

        if (vertices[v].color == 2 || (vertices[v].color == 0 && !DFS_Visit(v)))
            return false;
    }
    // Set color to black
    vertices[u].color = 2;
    return true;
}

int main()
{
    int N;
    while (cin >> N)
    {
        for (int n = 0; n < N; ++n)
        {
            cin >> vertexCount >> edgeCount;

            vertices = new Vertex[vertexCount];
            bool isSC = true;

            // Get edges
            for (int e = 0; e < edgeCount; ++e)
            {
                int from, to;
                cin >> from >> to;

                vertices[from].adj.push_back(to);
            }

            // Main DFS algorithm
            for (int vi = 0; isSC && vi < vertexCount; ++vi)
            {
                // Initialize
                for (int _vi = 0; _vi < vertexCount; ++_vi)
                {
                    vertices[_vi].color = 0;
                }

                isSC = DFS_Visit(vi);
            }

            if (isSC)
                cout << n + 1 << " YES" << endl;
            else
                cout << n + 1 << " NO" << endl;

            // Free memory
            delete[] vertices;
        }
    }
}