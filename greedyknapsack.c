#include <stdio.h>

typedef struct {
    int weight;
    int value;
    float ratio;
    int index;
} Item;

void sortItems(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

void fractionalKnapsack(Item items[], int n, int capacity) {
    float totalValue = 0.0;
    float fractions[n];
    for (int i = 0; i < n; i++) fractions[i] = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            fractions[items[i].index] = 1;
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            fractions[items[i].index] = (float)capacity/items[i].weight;
            totalValue += items[i].ratio*capacity;
            capacity = 0;
            break;
        }
    }

    printf("\nItem fractions included:\n");
    for (int i = 0; i < n; i++) {
        if (fractions[i] > 0)
            printf("Item %d: fraction = %.2f\n", i + 1, fractions[i]);
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
        items[i].index = i;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    sortItems(items, n);
    fractionalKnapsack(items, n, capacity);

    return 0;
}
