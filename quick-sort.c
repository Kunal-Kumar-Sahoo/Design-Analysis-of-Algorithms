#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int p, int r) {
    int i = p - 1;
    for(int j = p; j < r; ++j)
        if(arr[j] <= arr[r]) {
            ++i;
            swap(arr+j, arr+i);
        }
    swap(arr+i+1, arr+r);

    return i+1;
}

void quick_sort(int arr[], int p, int r) {
    if(p < r) {
        int q = partition(arr, p, r);
        quick_sort(arr, p, q-1);
        quick_sort(arr, q+1, r);
    }
}

int main() {
    printf("Enter size of the array: ");
    int n; scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in the array: ", n);
    for(int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    quick_sort(arr, 0, n-1);

    printf("Sorted array: ");
    for(int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
