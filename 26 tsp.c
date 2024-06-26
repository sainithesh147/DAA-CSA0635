#include <stdio.h>
#include <limits.h>

#define V 4 

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int graph[][V], int mask, int pos, int n, int dp[][V]) {
    if (mask == (1 << n) - 1) {
        return graph[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int minCost = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { 
            int newMask = mask | (1 << city);
            int cost = graph[pos][city] + tsp(graph, newMask, city, n, dp);
            minCost = min(minCost, cost);
        }
    }

    dp[mask][pos] = minCost;

    return minCost;
}

int main() {

    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = -1;
        }
    }

    int mask = 1;
    int startCity = 0;

    int minCost = tsp(graph, mask, startCity, V, dp);

    printf("Minimum cost of TSP: %d\n", minCost);

    return 0;
}
