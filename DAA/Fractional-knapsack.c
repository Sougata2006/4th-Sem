#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

int main() {
    int n, i, j;
    float capacity, totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    printf("Enter profit and weight of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &item[i].profit, &item[i].weight);

        // Calculate profit/weight ratio
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort items in descending order of ratio
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (item[i].ratio < item[j].ratio) {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    printf("\nSelected items:\n");

    // Select items
    for (i = 0; i < n; i++) {

        // If whole item can be taken
        if (item[i].weight <= capacity) {
            capacity -= item[i].weight;
            totalProfit += item[i].profit;

            printf("Took full item -> Profit: %d Weight: %d\n",
                   item[i].profit, item[i].weight);
        }

        // Take fractional part
        else {
            float fraction = capacity / item[i].weight;
            totalProfit += item[i].profit * fraction;

            printf("Took %.2f fraction of item -> Profit: %d Weight: %d\n",
                   fraction, item[i].profit, item[i].weight);

            capacity = 0;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
