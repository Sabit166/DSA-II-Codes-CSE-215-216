#include <bits/stdc++.h>

using namespace std;

int MatrixChainOrder(int p[], int i, int j) {
    if (i == j)
        return 0;

    int min = INT_MAX;

    for (int k = i; k < j; k++) {
        int count = MatrixChainOrder(p, i, k) +
                    MatrixChainOrder(p, k + 1, j) +
                    p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    return min;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, 1, n - 1);

    return 0;
}