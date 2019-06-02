#ifdef CPP_VERSION_3

#include <iostream>
#include <vector>

using namespace std;

struct Vertex
{
    bool discoverd;
    vector<int> path;
    vector<int> adj;
};

int main()
{
    int N;
    while (cin >> N)
    {
        for (int n = 0; n < N; ++n)
        {
            int vertexCount, edgeCount;

            cin >> vertexCount >> edgeCount;

            vector<Vertex> vertices(vertexCount);
            bool isSC = true;

            for (int e = 0; e < edgeCount; ++e)
            {
                int from, to;
                cin >> from >> to;

                vertices[from].adj.push_back(to);
            }

            for (int vi = 0; vi < vertexCount; ++vi)
            {
                vector<int> stack;

                for (auto v = vertices.begin(); v != vertices.end(); ++v)
                {
                    v->discoverd = false;
                    v->path.clear();
                }

                vertices[vi].discoverd = true;
                vertices[vi].path.push_back(vi);

                stack.push_back(vi);

                while (stack.size())
                {
                    int nowV = stack[stack.size() - 1];
                    stack.pop_back();

                    for (auto neighbor = vertices[nowV].adj.begin(); neighbor != vertices[nowV].adj.end(); ++neighbor)
                    {
                        if (!vertices[*neighbor].discoverd)
                        {
                            vertices[*neighbor].discoverd = true;
                            vertices[*neighbor].path = vertices[nowV].path;
                            vertices[*neighbor].path.push_back(*neighbor);

                            stack.push_back(*neighbor);
                        }
                        else
                        {
                            isSC = false;
                            for (auto prePath = vertices[nowV].path.begin(); prePath != vertices[nowV].path.end(); ++prePath)
                            {
                                if (*prePath == *neighbor)
                                {
                                    isSC = true;
                                    break;
                                }
                            }

                            if (!isSC)
                                goto OUTPUT;
                        }
                    }
                }
            }

        OUTPUT:
            if (isSC)
                cout << n + 1 << " YES" << endl;
            else
                cout << n + 1 << " NO" << endl;
        }
    }
}

#endif