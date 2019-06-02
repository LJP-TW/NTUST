#ifdef CPP_VERSION

#ifdef _DEBUG
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef struct
{
    int *vertices;
    int distance;
} Path;

int main()
{
    int N;

    while (cin >> N)
    {
        for (int n = 0; n < N; ++n)
        {
            int vertices;
            int edges;
            int **edgeMap;
            int isSC = 1;

            cin >> vertices >> edges;

            // Build directed-edge map
            // EdgeMap[From][To] == 1 It means there is a edge s.t. Vertex[From] -> Vertex[To]
            edgeMap = new int*[vertices];
            for (int i = 0; i < vertices; ++i)
            {
                edgeMap[i] = new int[vertices];
                memset(edgeMap[i], 0, sizeof(int) * vertices);
            }

            for (; edges; --edges)
            {
                int from, to;

                cin >> from >> to;

                edgeMap[from][to] = 1;
            }

            // Main algorithm
            for (int i = 0; isSC && i < vertices; ++i)
            {
                Path *P = new Path[vertices + 1];
                int *stack = new int[vertices + 1];
                int stackIndex = 0;
                int V;

                for (int j = 0; j <= vertices; ++j)
                {
                    P[j].distance = -1;
                    P[j].vertices = NULL;
                    stack[j] = -1;
                }

                stack[0] = i;
                P[i].distance = 1;
                P[i].vertices = new int[1];
                P[i].vertices[0] = i;

                while (isSC && stackIndex >= 0 && (V = stack[stackIndex--]) != -1)
                {
                    for (int j = 0; j < vertices; ++j)
                    {
                        if (V != j && edgeMap[V][j])
                        {
                            if (P[j].distance == -1)
                            {
                                P[j].distance = P[V].distance + 1;
                                P[j].vertices = new int[P[j].distance];
                                for (int k = 0; k < P[V].distance; ++k)
                                {
                                    P[j].vertices[k] = P[V].vertices[k];
                                }
                                P[j].vertices[P[V].distance] = j;

                                stack[++stackIndex] = j;
                            }
                            else
                            {
                                // Check whether it is a Back Edge
                                int isBackedge = 0;

                                for (int k = 0; k < P[V].distance; ++k)
                                {
                                    if (P[V].vertices[k] == j)
                                    {
                                        isBackedge = 1;
                                        break;
                                    }
                                }

                                if (!isBackedge)
                                {
                                    isSC = 0;
                                    break;
                                }
                            }
                        }
                    }
                }

                delete[] stack;
                for (int j = 0; j <= vertices; ++j)
                {
                    if (P[j].vertices)
                    {
                        delete[] P[j].vertices;
                    }
                }
                delete[] P;
            }

            if (isSC)
            {
                cout << n + 1 << " YES" << endl;
            }
            else
            {
                cout << n + 1 << " NO" << endl;
            }

            // Free memory
            for (int i = 0; i < vertices; ++i)
            {
                delete[] edgeMap[i];
            }
            delete[] edgeMap;
        }
    }
}

#endif