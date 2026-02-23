#include <stdio.h>

int countDuplicates(int arr[], int n) {
    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                break;
            }
        }
    }

    return count;
}

int main() {

    int arr[] = {1, 2, 3, 2, 4, 5, 1, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int totalDuplicates = countDuplicates(arr, n);

    printf("Total number of duplicate elements = %d\n", totalDuplicates);

    return 0;
}
