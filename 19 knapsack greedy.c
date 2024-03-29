#include <stdio.h>


struct Item {
    int value;
    int weight;
};


int compare(const void *a, const void *b) {
    double ratio1 = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    double ratio2 = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);
    return (ratio2 > ratio1) ? 1 : -1;
}

void knapsackGreedy(int W, struct Item items[], int n) {
    // Sort items based on value per unit weight
    qsort(items, n, sizeof(items[0]), compare);

    int curWeight = 0; // Current weight in knapsack
    double finalValue = 0.0; // Final value of items selected
    int i;

    for ( i = 0; i < n; i++) {
        if (curWeight + items[i].weight <= W) {
            curWeight += items[i].weight;
            finalValue += items[i].value;
        }

        else {
            int remain = W - curWeight;
            finalValue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }

    printf("Maximum value in knapsack (using greedy approach): %.2f\n", finalValue);
}

int main() {
    int W = 50; 
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);

    knapsackGreedy(W, items, n);

    return 0;
}
