#include <stdio.h>
#define infinity 999
void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}
void dijkstra(int n, int v, int cost[10][10], int dist[], int parent[])
{
    int i, u, count, w, flag[10], min;
    for (i = 0; i < n; i++)
    {
        flag[i] = 0;
        dist[i] = cost[v][i];
        if (cost[v][i] != infinity && i != v)
            parent[i] = v;
        else
            parent[i] = -1;
    }
    dist[v] = 0;
    parent[v] = -1;
    flag[v] = 1;
    count = 1;
    while (count < n)
    {
        min = infinity;
        u = -1;
        for (w = 0; w < n; w++)
        {
            if (!flag[w] && dist[w] < min)
            {
                min = dist[w];
                u = w;
            }
        }
        if (u == -1)
            break;
        flag[u] = 1;
        count++;
        for (w = 0; w < n; w++)
        {
            if (!flag[w] &&
                dist[u] + cost[u][w] < dist[w])
            {
                dist[w] = dist[u] + cost[u][w];
                parent[w] = u;   // Store parent
            }
        }
    }
}
int main()
{
    int n, v, i, j, cost[10][10], dist[10], parent[10];
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    printf("Enter the cost matrix (use 0 for no direct path):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = infinity;
        }
    }
    printf("Enter the source node (0 to %d):\n", n - 1);
    scanf("%d", &v);
    if (v < 0 || v >= n)
    {
        printf("Invalid source node.\n");
        return 1;
    }
    dijkstra(n, v, cost, dist, parent);
    printf("\nShortest Paths from node %d:\n", v);
    for (i = 0; i < n; i++)
    {
        if (i != v)
        {
            printf("Path to %d (Cost = %d): %d", i, dist[i], v);
            printPath(parent, i);
            printf("\n");
        }
    }
    return 0;
}
