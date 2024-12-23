#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;

while (arr[(step < n ? step : n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == fmin(step, n)) {
            return -1;
        }
    }

    if (arr[prev] == x) {
        return prev;
    }

    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 11;

    int result = jumpSearch(arr, n, x);

    if (result != -1) {
        printf("Elemen %d ditemukan pada indeks %d\n", x, result);
    } else {
        printf("Elemen %d tidak ditemukan\n", x);
    }

    return 0;
}
