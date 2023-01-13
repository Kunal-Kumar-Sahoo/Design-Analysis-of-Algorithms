#include <stdio.h>
#include <limits.h>

int find_sec_min(int arr[], int n) {
    int min, sec_min;
    min = INT_MAX;
    sec_min = INT_MAX;
    for(int i = 0; i < n; ++i) {
        if(arr[i] < min) {
            sec_min = min;
            min = arr[i];
        }
        else if(arr[i] < sec_min && arr[i] > min) 
            sec_min = arr[i];
    }
    return sec_min;
}

int main() {
    printf("Enter size of the array: ");
    int n; scanf("%d", &n);
    int arr[n];
    printf("Enter elements of the array:\n");
    for(int i = 0; i < n; ++i)
        scanf("%d", arr+i);
    printf("Second minimum number: %d\n", find_sec_min(arr, n));
    return 0;
}
