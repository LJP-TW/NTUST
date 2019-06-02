#ifdef C_VERSION_2

#ifdef _DEBUG
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef unsigned char bool;

typedef struct
{
    bool discoverd;
    int *path;
    int pathSize;
    int *adj;
    int adjSize;
} Vertex;

int main()
{
    int N;
    char buf[32] = { 0 };
    char output[1024] = { 0 };

    while (gets(buf))
    {
        N = atoi(buf);

        for (int n = 0; n < N; ++n)
        {
            int vertexCount, edgeCount;

            gets(buf);
            vertexCount = atoi(buf);

            gets(buf);
            edgeCount = atoi(buf);

            bool isSC = true;
            Vertex *vertices = malloc(sizeof(Vertex) * vertexCount);
            memset(vertices, 0, sizeof(Vertex) * vertexCount);
            
            for (int v = 0; v < vertexCount; ++v)
            {
                vertices[v].adj = malloc(sizeof(int) * 1000);
                vertices[v].path = malloc(sizeof(int) * 1000);
            }
            
            for (int e = 0; e < edgeCount; ++e)
            {
                int from, to;
                gets(buf);
                sscanf(buf, "%d %d", &from, &to);

                vertices[from].adj[vertices[from].adjSize] = to;
                ++vertices[from].adjSize;
            }

            for (int vi = 0; vi < vertexCount; ++vi)
            {
                int *stack = malloc(sizeof(int) * 1000);
                int stackSize = 0;

                for (int v = 0; v < vertexCount; ++v)
                {
                    vertices[v].discoverd = false;
                    vertices[v].pathSize = 0;
                }

                vertices[vi].discoverd = true;
                vertices[vi].path[vertices[vi].pathSize++] = vi;

                stack[stackSize++] = vi;

                while (stackSize > 0)
                {
                    int nowV = stack[--stackSize];

                    for (int neighbor = 0; neighbor < vertices[nowV].adjSize; ++neighbor)
                    {
                        int nvi = vertices[nowV].adj[neighbor];

                        if (!vertices[nvi].discoverd)
                        {
                            int p = 0;
                            vertices[nvi].discoverd = true;
                            vertices[nvi].pathSize = vertices[nowV].pathSize;
                            for (; p < vertices[nowV].pathSize; ++p)
                            {
                                vertices[nvi].path[p] = vertices[nowV].path[p];
                            }
                            vertices[nvi].path[p] = nvi;

                            stack[stackSize++] = nvi;
                        }
                        else
                        {
                            isSC = false;
                            for (int prePath = 0; prePath < vertices[nowV].pathSize; ++prePath)
                            {
                                int pvi = vertices[nowV].path[prePath];
                                if (pvi == nvi)
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
                printf("%d YES\n", n + 1);
            else
                printf("%d NO\n", n + 1);            
        }
    }
}

#endif