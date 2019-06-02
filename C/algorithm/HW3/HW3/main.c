#ifdef C_VERSION

#ifdef _DEBUG
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *vertices;
    int distance;
} Path;

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
            int vertices;
            int edges;
            int **edgeMap;
            int isSC = 1;
            
            gets(buf);
            vertices = atoi(buf);

            gets(buf);
            edges = atoi(buf);

            // Build directed-edge map
            // EdgeMap[From][To] == 1 It means there is a edge s.t. Vertex[From] -> Vertex[To]
            edgeMap = malloc(sizeof(int *) * vertices);
            for (int i = 0; i < vertices; ++i)
            {
                edgeMap[i] = malloc(sizeof(int) * vertices);
                memset(edgeMap[i], 0, sizeof(int) * vertices);
            }

            for (; edges ; --edges)
            {
                int from, to;

                gets(buf);
                sscanf(buf, "%d %d", &from, &to);

                edgeMap[from][to] = 1;
            }

            // Main algorithm
            for (int i = 0; isSC && i < vertices; ++i)
            {
                Path *P = malloc(sizeof(Path) * (vertices + 1));
                int *stack = malloc(sizeof(int) * (vertices + 1));
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
                P[i].vertices = malloc(sizeof(int) * 1);
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
                                P[j].vertices = malloc(sizeof(int) * P[j].distance);
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

                free(stack);
                for (int j = 0; j <= vertices; ++j)
                {
                    if (P[j].vertices)
                    {
                        free(P[j].vertices);
                    }
                }
                free(P);
            }

            if (isSC)
            {
#ifdef _DEBUG
                printf("%d YES\n", n + 1);
#else
                sprintf(buf, "%d YES\n", n + 1);
                strcat(output, buf);
#endif
            }
            else
            {
#ifdef _DEBUG
                printf("%d NO\n", n + 1);
#else
                sprintf(buf, "%d NO\n", n + 1);
                strcat(output, buf);
#endif
            }

            // Free memory
            for (int i = 0; i < vertices; ++i)
            {
                free(edgeMap[i]);
            }
            free(edgeMap);
        }
    }

#ifndef _DEBUG
    printf("%s", output);
#endif
}

#endif