#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;  // Return the index if the element is found
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // Return -1 if the element is not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};  // Array must be sorted
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);
    if (result != -1)
        printf("Element %d found at index %d using Binary Search.\n", key, result);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}
