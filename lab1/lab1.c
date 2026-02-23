#include <stdio.h>


int adddia(int arr[][3], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i][i];
    }
    return sum;
}

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = 3;
    int sum =adddia(arr, n);

    printf("Sum of left diagonal elements = %d\n", sum);

    return 0;
}
