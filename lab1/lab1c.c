#include <stdio.h>


void rowSum(int arr[][3], int n) {
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
        printf("Sum of row %d = %d\n", i+1, sum);
    }
}


void colSum(int arr[][3], int n) {
    for(int j = 0; j < n; j++) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i][j];
        }
        printf("Sum of column %d = %d\n", j+1, sum);
    }
}

int main() {

    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = 3;

    printf("Row sums:\n");
    rowSum(arr, n);

    printf("\nColumn sums:\n");
    colSum(arr, n);

    return 0;
}
