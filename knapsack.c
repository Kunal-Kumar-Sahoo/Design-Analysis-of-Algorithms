#include <stdio.h>

#define MAX 10

int main() {
    int capacity, no_items, cur_weight, item;
    int used[MAX], weight[MAX], value[MAX];
    float total_profit;

    printf("Enter the capacity of knapsack:\n");
    scanf("%d", &capacity);

    printf("Enter the number of items:\n");
    scanf("%d", &no_items);

    printf("Enter the weight and value of %d item:\n", no_items);
    for (int i = 0; i < no_items; i++) {
        printf("Weight[%d]:\t", i);
        scanf("%d", weight+i);
        printf("Value[%d]:\t", i);
        scanf("%d", value+i);
    }

    for (int i = 0; i < no_items; ++i)
        used[i] = 0;

    cur_weight = capacity;
    while (cur_weight > 0) {
        item = -1;
        for (int i = 0; i < no_items; ++i)
            if ((used[i] == 0) &&
                ((item == -1) || ((float) value[i] / weight[i] > (float) value[item] / weight[item])))
                item = i;

        used[item] = 1;
        cur_weight -= weight[item];
        total_profit += value[item];
        if (cur_weight >= 0)
            printf("Added object %d (%d VALUE, %dWeight) completely in the bag. Space left: %d.\n", item + 1, value[item], weight[item], cur_weight);
        else {
            int item_percent = (int) ((1 + (float) cur_weight / weight[item]) * 100);
            printf("Added %d%% (%d VALUE, %dWeight) of object %d in the bag.\n", item_percent, value[item], weight[item], item + 1);
            total_profit -= value[item];
            total_profit += (1 + (float)cur_weight / weight[item]) * value[item];
        }
    }

    printf("Filled the bag with objects worth %.2f VALUE \n", total_profit);
    return 0;
}
