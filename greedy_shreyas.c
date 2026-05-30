#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct Item items[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(items[j].ratio < items[j+1].ratio) {
                swap(&items[j], &items[j+1]);
            }
        }
    }
}

float greedyKnapsack(struct Item items[], int n, int W) {
    for(int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    sort(items, n);
    float total_profit = 0;

    for(int i = 0; i < n; i++) {
        if(W >= items[i].weight) {
            total_profit += items[i].profit;
            W -= items[i].weight;
        } else {
            total_profit += items[i].profit * ((float)W / items[i].weight);
            break;
        }
    }
    return total_profit;
}

int main(void) {
    struct Item items[] = {
        {10, 60, 0},
        {20, 100, 0},
        {30, 120, 0}
    };
    int n = sizeof(items) / sizeof(items[0]);
    int W = 50;

    float result = greedyKnapsack(items, n, W);
    printf("Maximum Profit = %.2f\n", result);

    return 0;
}