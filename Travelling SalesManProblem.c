#include <stdio.h>
#include <limits.h>
#define MAX 10
int cost[MAX][MAX];
int visited[MAX];
int path[MAX], bestPath[MAX];
int n;
int minCost = INT_MAX;
void tsp(int, int, int);
int main()
{
    printf("Enter number of cities: ");
    scanf("%d",&n);
    printf("Enter cost matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    visited[0] = 1;
    path[0] = 0;
    tsp(0,1,0);
    printf("\nMinimum Travelling Cost = %d\n",minCost);
    printf("Optimal Tour: ");
    for(int i=0;i<n;i++)
        printf("%d -> ",bestPath[i]);
    printf("0\n");
    return 0;
}
void tsp(int city, int count, int currentCost)
{
    if(count == n)
    {
        int total = currentCost + cost[city][0];
        if(total < minCost)
        {
            minCost = total;
            for(int i=0;i<n;i++)
                bestPath[i] = path[i];
        }
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && cost[city][i] != 0)
        {
            int tempCost = currentCost + cost[city][i];
            if(tempCost < minCost)   // Bounding condition
            {
                visited[i] = 1;
                path[count] = i;
                tsp(i, count+1, tempCost);
                visited[i] = 0;
            }
        }
    }
}
