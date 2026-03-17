#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
void knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }
    printf("Maximum profit: %d\n", K[n][W]);
    printf("Items included in the knapsack:\n");
    w = W;
    for (i = n; i > 0 && K[i][w] != 0; i--) {
        if (K[i][w] != K[i - 1][w]) {
            printf("Item %d (Weight: %d, Value: %d)\n", i, wt[i - 1], val[i - 1]);
            w -= wt[i - 1];
	}
    }
}
int main() {
    int i,n, W;
    int val[10], wt[10];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weights and values of the items:\n");
    for (i = 0; i < n; i++)
        scanf("%d %d", &wt[i], &val[i]);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    knapsack(W, wt, val, n);
    return 0;
}
