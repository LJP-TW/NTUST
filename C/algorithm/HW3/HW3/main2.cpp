#ifdef CPP_VERSION_2

#include <iostream>
#include <vector>

using namespace std;

struct Vertex
{
    int color;
    vector<int> adj;
};

struct DFSInfo
{
    DFSInfo(int _v, int _unhandle)
    {
        v = _v;
        unhandle = _unhandle;
    }

    int v;
    int unhandle;
};

int main()
{
    int N;
    while (cin >> N)
    {
        for (int n = 0; n < N; ++n)
        {
            bool isSC = true;
            int vertexAmount, edgeAmount;

            cin >> vertexAmount >> edgeAmount;

            vector<Vertex> vertices(vertexAmount);

            for (int i = 0; i < edgeAmount; ++i)
            {
                int from, to;
                cin >> from >> to;

                vertices[from].adj.push_back(to);
            }

            for (int i = 0; isSC && i < vertexAmount; ++i)
            {
                int v;
                vector<int> s;
                vector<DFSInfo> s2;
                s.push_back(i);

                for (int j = 0; j < vertexAmount; ++j)
                {
                    vertices[j].color = 0;
                }
                
                while (isSC && s.size())
                {
                    v = s[s.size() -1];
                    s.pop_back();

                    vertices[v].color = 1;

                    DFSInfo d(v, vertices[v].adj.size());

                    for (auto next = vertices[v].adj.begin(); next != vertices[v].adj.end(); ++next)
                    {
                        if (vertices[*next].color == 0)
                        {
                            // Tree edge
                            s.push_back(*next);
                        }
                        else if (vertices[*next].color == 1)
                        {
                            --d.unhandle;
                        }
                        else
                        {
                            // Forward / Cross edge
                            isSC = false;
                            break;
                        }
                    }

                    s2.push_back(d);
                    
                    while (d.unhandle == 0)
                    {
                        vertices[d.v].color = 2;

                        s2.pop_back();
                        
                        if (s2.size() == 0)
                            break;

                        d = s2[s2.size() - 1];
                        --d.unhandle;
                        s2.pop_back();
                        s2.push_back(d);
                    }                    
                }
            }

            if (isSC)
            {
                cout << n + 1 << " YES" << endl;
            }
            else
            {
                cout << n + 1 << " NO" << endl;
            }
        }
    }
}

#endif