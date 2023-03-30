#include <stdio.h>
#include <limits.h>

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    
    for(int i = 0; i < n1; ++i)
        L[i] = arr[p + i];

    for(int j = 0; j < n2; ++j)
        R[j] = arr[q + j + 1];

    L[n1] = R[n2] = INT_MAX;

    for(int i = 0, j = 0, k = p; k <= r; ++k) {
        if(L[i] <= R[j])
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
    }
}

void merge_sort(int arr[], int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int main() {
    printf("Enter size of the array: ");
    int n; scanf("%d", &n);

    printf("Enter %d elements in the array:\n", n);
    int arr[n];

    for(int i = 0; i < n; ++i ) 
        scanf("%d", arr+i);

    merge_sort(arr, 0, n-1);

    printf("Sorted array: ");
    for(int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
