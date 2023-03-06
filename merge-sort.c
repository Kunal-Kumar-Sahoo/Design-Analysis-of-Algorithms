#include <stdio.h>
#include <limits.h>

void merge(int arr[], int lower_bound, int middle, int upper_bound) {
    int n1 = middle-lower_bound+1;
    int n2 = upper_bound-middle;
    int left[n1+1], right[n2+1];
    int i, j, k;

    for(i = 0; i < n1; ++i)
        left[i] = arr[lower_bound+i];
    left[i] = INT_MAX;

    for(j = 0; j < n2; ++j)
        right[j] = arr[middle+j+1];
    right[j] = INT_MAX;
    
    i = j = 0;
    /*
    k = lower_bound;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while(i < n1)
        arr[k++] = left[i++];
    while(j < n2)
        arr[k++] = right[j++];
    */

    for(k = lower_bound; k <= upper_bound; ++k) {
        if(left[i] <= right[j])
            arr[k] = left[i++];
        else arr[k] = right[j++];
    }
    
}

void sort(int arr[], int lower_bound, int upper_bound) {
    if(lower_bound >= upper_bound)
        return;
    int middle = (upper_bound+lower_bound)/2;
    sort(arr, lower_bound, middle);
    sort(arr, middle+1, upper_bound);
    merge(arr, lower_bound, middle, upper_bound);
}

int main() {
    printf("Enter size of the array: ");
    int n; scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    sort(arr, 0, n-1);
    printf("Sorted array:\n");
    for(int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
