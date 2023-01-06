#include <stdio.h>

int binary_search(int array[], int size, int key) {
   int start = 0, end = size - 1;
   for(int mid = (start + end) / 2; start <= end; mid = (start + end) / 2) {
       if(array[mid] == key)
           return mid;
       else if(array[mid] > key)
           end = mid - 1;
       else start = mid + 1;
   } return -1;
}

int main() {
    printf("Enter size of the array: ");
    int size;
    scanf("%d", &size);

    printf("Enter elements of the sorted array:\n");
    int arr[size];
    for(int i = 0; i < size; ++i)
        scanf("%d", arr+i);

    printf("Enter element to be searched: ");
    int key;
    scanf("%d", &key);

    int index = binary_search(arr, size, key);

    if(index >= 0)
        printf("%d found at index %d\n", key, index);
    else
        printf("%d not found in array\n", key);

    return 0;
}
